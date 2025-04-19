/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 09:40:13 by chugon            #+#    #+#             */
/*   Updated: 2025/04/18 19:59:06 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTX_MAP_H
# define FTX_MAP_H

/**
 * \brief Structure for managing 2D arrays.
 */
typedef struct s_map
{
	struct s_map_internal
	{
		int		width;
		int		height;
		char	*data;
	}	_internal;
}	t_map;

typedef int	(*t_map_iterator)(int, int, char *, void *);

t_map	*ftx_map(int width, int height);

int		ftx_map_width(t_map *map);

int		ftx_map_height(t_map *map);

char	ftx_map_getdata(t_map *map, int x, int y);

int		ftx_map_setdata(t_map *map, char c, int x, int y);

int		ftx_map_iterate(t_map *map, t_map_iterator iterator, void *param);

#endif // FTX_MAP_H

/**
 * \file ftx_map.h
 * \author Christian Hugon &lt;chriss.hugon@gmail.com&gt;
 * \version 0.1
 * \brief Functions for managing 2D array.
 */
