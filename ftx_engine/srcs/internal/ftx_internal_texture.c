/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_internal_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:14:09 by chugon            #+#    #+#             */
/*   Updated: 2025/04/18 15:24:48 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftx_graphics.h"

int	ftx_internal__error(int e);

int	ftx_internal__texture_check(t_texture *texture)
{
	if (texture == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_NULLPTR));
	if (texture->_internal.img_ptr == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_TEXTURE));
	if (texture->_internal.data == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_TEXTUREDATA));
	return (FTX_SUCCESS);
}

t_color	ftx_internal__texture_getcolor(t_texture *texture, int x, int y)
{
	int		offset;
	int		*data;
	t_color	color;

	offset = y * texture->_internal.lsize + x * (texture->_internal.bpp / 8);
	data = (int *)(texture->_internal.data + offset);
	color.argb = *data;
	return (color);
}

int	ftx_internal__texture_setcolor(t_texture *texture,
	t_color color,
	int x,
	int y)
{
	int	offset;
	int	*data;

	offset = y * texture->_internal.lsize + x * (texture->_internal.bpp / 8);
	data = (int *)(texture->_internal.data + offset);
	*data = color.argb;
	return (FTX_SUCCESS);
}
