/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 09:11:29 by chugon            #+#    #+#             */
/*   Updated: 2025/04/18 21:06:54 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "ftx_core.h"

t_engine	*ftx_internal__engine(void);
int			ftx_internal__error(int e);
int			ftx_internal__object_create(void *p, t_deleter d);
void		ftx_internal__texture_deleter(void *p);
int			ftx_internal__engine_check(void);
int			ftx_internal__texture_check(t_texture *texture);

int			ftx_internal__texture_allocator(void *p, void *l);
void		*ftx_internal__allocate(size_t s, t_deleter d,
				t_allocator a, void *p);

t_texture	*ftx_texture(int width, int height)
{
	static t_texture	default_texture;

	if (width <= 0 || height <= 0)
		return (ftx_internal__error(FTX_ERROR_PARAMETER), FTX_NULLPTR);
	default_texture._internal.width = width;
	default_texture._internal.height = height;
	return ((t_texture *)ftx_internal__allocate(sizeof(t_texture),
			&ftx_internal__texture_deleter,
			&ftx_internal__texture_allocator,
			&default_texture)
	);
}

t_texture	*ftx_texture_xpm(char *filename)
{
	static t_texture	default_texture;

	if (filename == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_NULLPTR), FTX_NULLPTR);
	default_texture._internal.data = filename;
	return ((t_texture *)ftx_internal__allocate(sizeof(t_texture),
			&ftx_internal__texture_deleter,
			&ftx_internal__texture_allocator,
			&default_texture)
	);
}

int	ftx_texture_width(t_texture *texture)
{
	if (ftx_internal__texture_check(texture) != FTX_SUCCESS)
		return (0);
	return (texture->_internal.width);
}

int	ftx_texture_height(t_texture *texture)
{
	if (ftx_internal__texture_check(texture) != FTX_SUCCESS)
		return (0);
	return (texture->_internal.height);
}
