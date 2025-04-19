/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_internal_deleter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:01:19 by chugon            #+#    #+#             */
/*   Updated: 2025/04/18 14:18:48 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "ftx_core.h"
#include "ftx_map.h"

t_engine	*ftx_internal__engine(void);

void	ftx_internal__texture_deleter(void *param)
{
	t_texture	*texture;

	texture = (t_texture *)param;
	mlx_destroy_image(ftx_internal__engine()->mlx_ptr,
		texture->_internal.img_ptr);
	free(texture);
}

void	ftx_internal__text_deleter(void *param)
{
	t_text	*text;

	text = (t_text *)param;
	free(text->_internal.str);
	free(text);
}

void	ftx_internal__map_deleter(void *param)
{
	t_map	*map;

	map = (t_map *)param;
	free(map->_internal.data);
	free(map);
}
