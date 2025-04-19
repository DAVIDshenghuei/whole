/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:04:28 by chugon            #+#    #+#             */
/*   Updated: 2025/04/18 16:31:42 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ftx_map.h"
#include "ftx_error.h"

int		ftx_internal__error(int e);
int		ftx_internal__object_create(void *p, t_deleter d);
void	ftx_internal__map_deleter(void *p);

void	*ftx_internal__allocate(size_t s, t_deleter d, t_allocator a, void *p);
int		ftx_internal__map_allocator(void *p, void *l);

// t_map	*ftx_map(int width, int height)
// {
// 	t_map	*map;

// 	if (width <= 0 || height <= 0)
// 		return (ftx_internal__error(FTX_ERROR_PARAMETER), FTX_NULLPTR);
// 	map = (t_map *)malloc(sizeof(t_map));
// 	if (map == FTX_NULLPTR)
// 		return (ftx_internal__error(FTX_ERROR_MEMORY), FTX_NULLPTR);
// 	map->_internal.data = (char *)malloc(sizeof(char) * width * height);
// 	if (map->_internal.data == FTX_NULLPTR)
// 		return (ftx_internal__error(FTX_ERROR_MEMORY), free(map), FTX_NULLPTR);
// 	map->_internal.width = width;
// 	map->_internal.height = height;
// 	if (ftx_internal__object_create(map,
// 		&ftx_internal__map_deleter) == FTX_SUCCESS)
// 		return (map);
// 	return (FTX_NULLPTR);
// }

t_map	*ftx_map(int width, int height)
{
	static t_map	default_map;

	if (width <= 0 || height <= 0)
		return (ftx_internal__error(FTX_ERROR_PARAMETER), FTX_NULLPTR);
	default_map._internal.width = width;
	default_map._internal.height = height;
	return ((t_map *)ftx_internal__allocate(sizeof(t_map),
			&ftx_internal__map_deleter,
			&ftx_internal__map_allocator,
			&default_map)
	);
}

char	ftx_map_getdata(t_map *map, int x, int y)
{
	if (map == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_NULLPTR), 0);
	if (x < 0 || x >= map->_internal.width
		|| y < 0 || y >= map->_internal.height)
		return (ftx_internal__error(FTX_ERROR_INDEX), 0);
	return (map->_internal.data[y * map->_internal.width + x]);
}

int	ftx_map_setdata(t_map *map, char c, int x, int y)
{
	if (map == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_NULLPTR));
	if (x < 0 || x >= map->_internal.width
		|| y < 0 || y >= map->_internal.height)
		return (ftx_internal__error(FTX_ERROR_INDEX));
	map->_internal.data[y * map->_internal.width + x] = c;
	return (FTX_SUCCESS);
}

int	ftx_map_width(t_map *map)
{
	if (map == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_NULLPTR), 0);
	return (map->_internal.width);
}

int	ftx_map_height(t_map *map)
{
	if (map == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_NULLPTR), 0);
	return (map->_internal.height);
}
