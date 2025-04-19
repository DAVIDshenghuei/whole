/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 08:49:02 by chugon            #+#    #+#             */
/*   Updated: 2025/04/18 11:42:13 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "ftx_core.h"
#include "ftx_event.h"
#include "ftx_error.h"

t_engine	*ftx_internal__engine(void);
int			ftx_internal__error(int error);
int			ftx_internal__engine_check(void);

uint64_t	ftx_elapsed(void)
{
	t_engine	*engine;
	t_time		now;

	engine = ftx_internal__engine();
	gettimeofday(&now, FTX_NULLPTR);
	return (now.tv_sec * 1000UL
		+ now.tv_usec / 1000UL
		- engine->time);
}

static
int	ftx_internal__event_getmask(int type)
{
	if (FTX_EVENT_KEYPRESS == type)
		return (FTX_MASK_KEYPRESS);
	else if (FTX_EVENT_KEYRELEASE == type)
		return (FTX_MASK_KEYRELEASE);
	else if (FTX_EVENT_MOUSEMOTION == type)
		return (FTX_MASK_MOUSEMOTION);
	else if (FTX_EVENT_MOUSEPRESS == type)
		return (FTX_MASK_MOUSEPRESS);
	else if (FTX_EVENT_MOUSERELEASE == type)
		return (FTX_MASK_MOUSERELEASE);
	return (FTX_NUMBEROF_EVENT);
}

static
int	ftx_internal__window_close(void *param)
{
	t_engine			*engine;
	t_event_handler		event_close;

	engine = (t_engine *)param;
	mlx_loop_end(engine->mlx_ptr);
	event_close = engine->events[FTX_EVENT_WINDOWCLOSE];
	if (event_close != FTX_NULLPTR)
		return (event_close(engine->user_data));
	return (FTX_SUCCESS);
}

int	ftx_exec(void)
{
	t_engine	*engine;
	t_time		now;
	int			event_index;

	if (ftx_internal__engine_check() != FTX_SUCCESS)
		return (ftx_error());
	engine = ftx_internal__engine();
	event_index = FTX_EVENT_WINDOWCLOSE;
	while (++event_index < FTX_NUMBEROF_EVENT)
	{
		if (engine->events[event_index] != FTX_NULLPTR)
			mlx_hook(engine->win_ptr,
				event_index, ftx_internal__event_getmask(event_index),
				engine->events[event_index], engine->user_data);
	}
	mlx_hook(engine->win_ptr, DestroyNotify, StructureNotifyMask,
		&ftx_internal__window_close, engine);
	if (engine->events[FTX_EVENT_UPDATE] != FTX_NULLPTR)
		mlx_loop_hook(engine->mlx_ptr, engine->events[FTX_EVENT_UPDATE],
			engine->user_data);
	gettimeofday(&(now), FTX_NULLPTR);
	engine->time = now.tv_sec * 1000UL + now.tv_usec / 1000UL;
	mlx_loop(engine->mlx_ptr);
	return (engine->error);
}
