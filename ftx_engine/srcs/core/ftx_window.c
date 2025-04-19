/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:02:21 by chugon            #+#    #+#             */
/*   Updated: 2025/04/19 07:19:00 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "ftx_core.h"

t_engine	*ftx_internal__engine(void);
int			ftx_internal__renderall(t_renderobject *l);
int			ftx_internal__engine_check(void);

int	ftx_window_width(void)
{
	if (ftx_internal__engine_check() != FTX_SUCCESS)
		return (0);
	return (ftx_internal__engine()->width);
}

int	ftx_window_height(void)
{
	if (ftx_internal__engine_check() != FTX_SUCCESS)
		return (0);
	return (ftx_internal__engine()->height);
}

char	*ftx_window_title(void)
{
	if (ftx_internal__engine_check() != FTX_SUCCESS)
		return (0);
	return (ftx_internal__engine()->title);
}

int	ftx_window_render(void)
{
	t_engine			*engine;

	if (ftx_internal__engine_check() != FTX_SUCCESS)
		return (ftx_error());
	engine = ftx_internal__engine();
	ftx_internal__renderall(engine->renderobjects);
	mlx_put_image_to_window(engine->mlx_ptr,
		engine->win_ptr,
		engine->background->_internal.img_ptr,
		0,
		0);
	ftx_internal__renderall(engine->rendertexts);
	return (FTX_SUCCESS);
}

int	ftx_window_clear(void)
{
	static const t_color	default_color;

	if (ftx_internal__engine_check() != FTX_SUCCESS)
		return (ftx_error());
	ftx_texture_fillall(ftx_internal__engine()->background,
		default_color);
	return (FTX_SUCCESS);
}
