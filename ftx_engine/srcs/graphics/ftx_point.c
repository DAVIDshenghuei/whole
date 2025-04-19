/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:05:05 by chugon            #+#    #+#             */
/*   Updated: 2025/04/18 16:28:40 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftx_core.h"

t_engine	*ftx_internal__engine(void);
void		*ftx_internal__allocate(size_t s, t_deleter d,
				t_allocator a, void *p);
int			ftx_internal__point_renderer(void *p);
int			ftx_internal__show(void *p, t_renderer r, t_renderobject **l);
int			ftx_internal__hide(void *p, t_renderobject **list);
int			ftx_internal__setzindex(void *p, int z, t_renderobject **l);

t_point	*ftx_point(int x, int y, t_color color)
{
	t_point	*point;

	point = ftx_internal__allocate(sizeof(t_point), &free,
			FTX_NULLPTR, FTX_NULLPTR);
	if (point == FTX_NULLPTR)
		return (FTX_NULLPTR);
	point->x = x;
	point->y = y;
	point->thickness = 1;
	point->color = color;
	return (point);
}

int	ftx_point_show(t_point *point)
{
	return (ftx_internal__show(point,
			&ftx_internal__point_renderer,
			&(ftx_internal__engine()->renderobjects)));
}

int	ftx_point_hide(t_point *point)
{
	return (ftx_internal__hide(point,
			&(ftx_internal__engine()->renderobjects)));
}

int	ftx_point_setzindex(t_point *point, int z)
{
	return (ftx_internal__setzindex(point,
			z,
			&(ftx_internal__engine()->renderobjects)));
}
