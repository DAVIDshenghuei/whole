/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_engine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:21:32 by chugon            #+#    #+#             */
/*   Updated: 2025/04/18 12:13:01 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "ftx_core.h"

t_engine	*ftx_internal__engine(void);
int			ftx_internal__engine_check(void);
int			ftx_internal__error(int e);
int			ftx_internal__object_clear(void);
int			ftx_internal__renderobject_clear(t_renderobject **l);

int	ftx_init(char *title, int width, int height)
{
	t_engine	*engine;

	engine = ftx_internal__engine();
	engine->mlx_ptr = mlx_init();
	if (engine->mlx_ptr == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_MLX));
	engine->title = title;
	engine->width = width;
	engine->height = height;
	engine->win_ptr = mlx_new_window(
			engine->mlx_ptr, width, height, title);
	if (engine->win_ptr == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_WINDOW));
	engine->background = ftx_texture(width, height);
	if (engine->background == FTX_NULLPTR)
		return (ftx_error());
	return (engine->error);
}

int	ftx_clear(void)
{
	t_engine	*engine;

	engine = ftx_internal__engine();
	if (ftx_internal__engine_check() != FTX_SUCCESS)
		return (ftx_error());
	ftx_internal__object_clear();
	ftx_internal__renderobject_clear(&(engine->renderobjects));
	ftx_internal__renderobject_clear(&(engine->rendertexts));
	mlx_destroy_window(engine->mlx_ptr,
		engine->win_ptr);
	engine->win_ptr = FTX_NULLPTR;
	mlx_destroy_display(engine->mlx_ptr);
	free(engine->mlx_ptr);
	engine->mlx_ptr = FTX_NULLPTR;
	return (FTX_SUCCESS);
}

int	ftx_quit(void)
{
	if (ftx_internal__engine_check() != FTX_SUCCESS)
		return (ftx_error());
	mlx_loop_end(ftx_internal__engine()->mlx_ptr);
	return (FTX_SUCCESS);
}

int	ftx_userdata(void *userdata)
{
	ftx_internal__engine()->user_data = userdata;
	return (FTX_SUCCESS);
}
