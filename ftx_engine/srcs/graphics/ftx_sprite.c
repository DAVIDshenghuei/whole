/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 08:50:01 by chugon            #+#    #+#             */
/*   Updated: 2025/04/19 07:23:20 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftx_core.h"

t_engine	*ftx_internal__engine(void);
int			ftx_internal__error(int e);
void		*ftx_internal__allocate(size_t s, t_deleter d,
				t_allocator a, void *p);
int			ftx_internal__sprite_renderer(void *p);
int			ftx_internal__show(void *p, t_renderer r, t_renderobject **l);
int			ftx_internal__hide(void *p, t_renderobject **l);
int			ftx_internal__setzindex(void *p, int z, t_renderobject **l);
int			ftx_internal__limit_check(int i, int a, int b);

t_sprite	*ftx_sprite(int x, int y, int width, int height)
{
	t_sprite	*sprite;

	sprite = ftx_internal__allocate(sizeof(t_sprite), &free,
			FTX_NULLPTR, FTX_NULLPTR);
	if (sprite == FTX_NULLPTR)
		return (FTX_NULLPTR);
	sprite->x = x;
	sprite->y = y;
	sprite->width = width;
	sprite->height = height;
	return (sprite);
}

int	ftx_sprite_settexture(t_sprite *sprite, t_texture *texture, int x, int y)
{
	if (sprite == FTX_NULLPTR || texture == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_NULLPTR));
	if (ftx_internal__limit_check(x, 0, texture->_internal.width - 1)
		|| ftx_internal__limit_check(y, 0, texture->_internal.height - 1))
		return (ftx_error());
	sprite->_internal.texture = texture;
	sprite->_internal.x = x;
	sprite->_internal.y = y;
	return (FTX_SUCCESS);
}

int	ftx_sprite_show(t_sprite *sprite)
{
	return (ftx_internal__show(sprite,
			&ftx_internal__sprite_renderer,
			&(ftx_internal__engine()->renderobjects)));
}

int	ftx_sprite_hide(t_sprite *sprite)
{
	return (ftx_internal__hide(sprite,
			&(ftx_internal__engine()->renderobjects)));
}

int	ftx_sprite_setzindex(t_sprite *sprite, int z)
{
	return (ftx_internal__setzindex(sprite,
			z,
			&(ftx_internal__engine()->renderobjects)));
}
