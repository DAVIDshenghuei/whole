/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 08:49:26 by chugon            #+#    #+#             */
/*   Updated: 2025/04/19 07:11:06 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftx_graphics.h"

t_color	ftx_color(uint8_t r, uint8_t g, uint8_t b)
{
	t_color	color;

	color.b = b;
	color.g = g;
	color.r = r;
	color.a = 0;
	return (color);
}

t_color	ftx_color_blend(t_color old, t_color new)
{
	const float	alpha = (float)new.a / FTX_COLOR_MAX;

	new.r = new.r - new.r * alpha + old.r * alpha;
	new.g = new.g - new.g * alpha + old.g * alpha;
	new.b = new.b - new.b * alpha + old.b * alpha;
	return (new);
}
