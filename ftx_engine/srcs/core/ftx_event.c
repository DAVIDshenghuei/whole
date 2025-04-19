/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:02:09 by chugon            #+#    #+#             */
/*   Updated: 2025/04/18 12:12:30 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "ftx_event.h"
#include "ftx_core.h"
#include "ftx_error.h"

t_engine	*ftx_internal__engine(void);
int			ftx_internal__error(int e);
int			ftx_internal__engine_check(void);

int	ftx_event_register(int event_type, t_event_handler handler)
{
	t_engine	*engine;

	if (ftx_internal__engine_check() != FTX_SUCCESS)
		return (ftx_error());
	if (event_type < 0 || event_type >= FTX_NUMBEROF_EVENT)
		return (ftx_internal__error(FTX_ERROR_EVENT));
	engine = ftx_internal__engine();
	engine->events[event_type] = handler;
	return (FTX_SUCCESS);
}
