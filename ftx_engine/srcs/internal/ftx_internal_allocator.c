/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_internal_allocator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:32:41 by chugon            #+#    #+#             */
/*   Updated: 2025/04/18 20:59:04 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "ftx_core.h"
#include "ftx_map.h"

t_engine	*ftx_internal__engine(void);
int			ftx_internal__engine_check(void);
int			ftx_internal__error(int error);
int			ftx_internal__object_create(void *p, t_deleter d);

char		*ftx_internal__strdup(const char *s);

void	*ftx_internal__allocate(size_t size, t_deleter deleter,
	t_allocator allocator, void *args)
{
	char	*ptr;
	size_t	index;

	if (ftx_internal__engine_check() != FTX_SUCCESS)
		return (ftx_internal__error(FTX_ERROR_ENGINE), FTX_NULLPTR);
	ptr = (char *)malloc(sizeof(char) * size);
	if (ptr == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_MEMORY), FTX_NULLPTR);
	index = 0;
	while (index < size)
	{
		ptr[index] = 0;
		++index;
	}
	if (allocator != FTX_NULLPTR && allocator(ptr, args) != FTX_SUCCESS)
		return (deleter(ptr), FTX_NULLPTR);
	if (ftx_internal__object_create(ptr, deleter) != FTX_SUCCESS)
		return (deleter(ptr), FTX_NULLPTR);
	return ((void *)ptr);
}

int	ftx_internal__texture_allocator(void *param, void *args)
{
	t_texture	*texture;
	t_texture	*reference;

	texture = (t_texture *)param;
	reference = (t_texture *)args;
	if (reference->_internal.data == FTX_NULLPTR)
	{
		texture->_internal.width = reference->_internal.width;
		texture->_internal.height = reference->_internal.height;
		texture->_internal.img_ptr = mlx_new_image(
				ftx_internal__engine()->mlx_ptr,
				texture->_internal.width, texture->_internal.height);
	}
	else
		texture->_internal.img_ptr = mlx_xpm_file_to_image(
				ftx_internal__engine()->mlx_ptr, reference->_internal.data,
				&(texture->_internal.width), &(texture->_internal.height));
	if (texture->_internal.img_ptr == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_TEXTURE));
	texture->_internal.data = mlx_get_data_addr(texture->_internal.img_ptr,
			&(texture->_internal.bpp), &(texture->_internal.lsize),
			&(texture->_internal.endian));
	if (texture->_internal.data == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_TEXTUREDATA));
	return (FTX_SUCCESS);
}

int	ftx_internal__text_allocator(void *param, void *args)
{
	t_text	*text;
	char	*str;

	text = (t_text *)param;
	str = (char *)args;
	text->_internal.str = ftx_internal__strdup(str);
	if (text->_internal.str == FTX_NULLPTR)
		return (ftx_error());
	return (FTX_SUCCESS);
}

int	ftx_internal__map_allocator(void *param, void *args)
{
	t_map	*map;
	t_map	*reference;

	map = (t_map *)param;
	reference = (t_map *)args;
	map->_internal.width = reference->_internal.width;
	map->_internal.height = reference->_internal.height;
	map->_internal.data = (char *)malloc(sizeof(char)
			* map->_internal.width * map->_internal.height);
	if (map == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_MEMORY));
	return (FTX_SUCCESS);
}
