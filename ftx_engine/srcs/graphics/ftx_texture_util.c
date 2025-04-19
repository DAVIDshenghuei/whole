/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_texture_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 07:21:15 by chugon            #+#    #+#             */
/*   Updated: 2025/04/19 07:21:37 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftx_graphics.h"

int		ftx_internal__error(int e);
int		ftx_internal__texture_check(t_texture *t);
int		ftx_internal__texture_setcolor(t_texture *t, t_color c, int x, int y);
t_color	ftx_internal__texture_getcolor(t_texture *t, int x, int y);

t_color	ftx_texture_getcolor(t_texture *texture, int x, int y)
{
	if (ftx_internal__texture_check(texture) != FTX_SUCCESS)
		return (ftx_color(0, 0, 0));
	if (x < 0 || x >= texture->_internal.width
		|| y < 0 || y >= texture->_internal.height)
	{
		ftx_internal__error(FTX_ERROR_INDEX);
		return (ftx_color(0, 0, 0));
	}
	return (ftx_internal__texture_getcolor(texture, x, y));
}

int	ftx_texture_setcolor(t_texture *texture, t_color color, int x, int y)
{
	if (ftx_internal__texture_check(texture) != FTX_SUCCESS)
		return (ftx_error());
	if (x < 0 || x >= texture->_internal.width
		|| y < 0 || y >= texture->_internal.height)
		return (ftx_internal__error(FTX_ERROR_INDEX));
	return (ftx_internal__texture_setcolor(texture, color, x, y));
}

int	ftx_texture_fillarea(t_texture *texture, t_color color, t_area area)
{
	int	x;
	int	y;

	if (ftx_internal__texture_check(texture) != FTX_SUCCESS)
		return (ftx_error());
	if (area.x < 0 || area.y < 0 || area.w < 0 || area.h < 0)
		return (ftx_internal__error(FTX_ERROR_PARAMETER));
	y = -1;
	while (++y < area.h)
	{
		x = -1;
		while (++x < area.w)
		{
			ftx_internal__texture_setcolor(texture, color,
				area.x + x, area.y + y);
		}
	}
	return (FTX_SUCCESS);
}

int	ftx_texture_fillall(t_texture *texture, t_color color)
{
	t_area	area;

	if (ftx_internal__texture_check(texture) != FTX_SUCCESS)
		return (ftx_error());
	area.x = 0;
	area.y = 0;
	area.w = texture->_internal.width;
	area.h = texture->_internal.height;
	return (ftx_texture_fillarea(texture, color, area));
}

// int	ftx_texture_fillcolor(t_texture *texture, t_color color)
// {
// 	int	x;
// 	int	y;

// 	if (ftx_internal__texture_check(texture) != FTX_SUCCESS)
// 		return (ftx_error());
// 	y = -1;
// 	while (++y < texture->_internal.height)
// 	{
// 		x = -1;
// 		while (++x < texture->_internal.width)
// 			ftx_internal__texture_setcolor(texture, color, x, y);
// 	}
// 	return (FTX_SUCCESS);
// }
