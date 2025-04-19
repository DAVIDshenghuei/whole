/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_map_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:55:28 by chugon            #+#    #+#             */
/*   Updated: 2025/04/19 08:52:44 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftx_map.h"
#include "ftx_core.h"

int	ftx_internal__error(int e);

int	ftx_map_iterate(t_map *map, t_map_iterator iterator, void *param)
{
	char	*data;
	int		x;
	int		y;

	if (map == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_NULLPTR));
	y = -1;
	while (++y < map->_internal.height)
	{
		x = -1;
		while (++x < map->_internal.width)
		{
			data = &(map->_internal.data[y * map->_internal.width + x]);
			if (iterator(x, y, data, param) != FTX_SUCCESS)
				return (FTX_FAILURE);
		}
	}
	return (FTX_SUCCESS);
}
