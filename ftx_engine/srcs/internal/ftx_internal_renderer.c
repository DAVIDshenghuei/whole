/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_internal_renderer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:03:57 by chugon            #+#    #+#             */
/*   Updated: 2025/04/18 19:36:36 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "ftx_core.h"

t_engine	*ftx_internal__engine(void);
t_color		ftx_internal__texture_getcolor(t_texture *t, int x, int y);
int			ftx_internal__error(int e);
int			ftx_internal__texture_setcolor(t_texture *t, t_color c,
				int x, int y);

static
int	ftx_internal__render_pixel(t_color color, int x, int y)
{
	t_engine	*engine;
	t_color		bgcolor;

	engine = ftx_internal__engine();
	if (x < 0 || x >= engine->background->_internal.width
		|| y < 0 || y >= engine->background->_internal.height)
		return (FTX_SUCCESS);
	bgcolor = ftx_internal__texture_getcolor(engine->background, x, y);
	bgcolor = ftx_color_blend(bgcolor, color);
	ftx_internal__texture_setcolor(engine->background, bgcolor, x, y);
	return (FTX_SUCCESS);
}

int	ftx_internal__point_renderer(void *param)
{
	t_point	*point;
	int		w;
	int		h;

	point = (t_point *)param;
	if (point == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_NULLPTR));
	h = point->y - 1;
	while (++h < point->y + point->thickness)
	{
		w = point->x - 1;
		while (++w < point->x + point->thickness)
		{
			ftx_internal__render_pixel(point->color, w, h);
		}
	}
	return (FTX_SUCCESS);
}

int	ftx_internal__sprite_renderer(void *param)
{
	t_sprite	*sprite;
	t_color		color;
	int			x;
	int			y;

	sprite = (t_sprite *)param;
	if (sprite == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_NULLPTR));
	if (sprite->_internal.texture == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_TEXTURE));
	y = -1;
	while (++y < sprite->height && y + sprite->_internal.y
		< sprite->_internal.texture->_internal.height)
	{
		x = -1;
		while (++x < sprite->width && x + sprite->_internal.x
			< sprite->_internal.texture->_internal.width)
		{
			color = ftx_internal__texture_getcolor(sprite->_internal.texture,
					sprite->_internal.x + x,
					sprite->_internal.y + y);
			ftx_internal__render_pixel(color, sprite->x + x, sprite->y + y);
		}
	}
	return (FTX_SUCCESS);
}

int	ftx_internal__text_renderer(void *param)
{
	t_text	*text;

	text = (t_text *)param;
	if (text == FTX_NULLPTR || text->_internal.str == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_NULLPTR));
	mlx_string_put(ftx_internal__engine()->mlx_ptr,
		ftx_internal__engine()->win_ptr,
		text->x, text->y, text->color.argb, text->_internal.str);
	return (FTX_SUCCESS);
}
