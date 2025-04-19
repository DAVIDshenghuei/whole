/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_animation2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:02:05 by chugon            #+#    #+#             */
/*   Updated: 2025/04/18 16:30:45 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftx_core.h"

int		ftx_internal__error(int e);
void	*ftx_internal__allocate(size_t s, t_deleter d,
			t_allocator a, void *p);

t_animation	*ftx_animation(void)
{
	return ((t_animation *)ftx_internal__allocate(
			sizeof(t_animation),
			&free,
			FTX_NULLPTR,
			FTX_NULLPTR)
	);
}

int	ftx_animation_addframe(t_animation *animation,
	t_sprite *sprite,
	int duration)
{
	t_sprite	*current;

	if (animation == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_NULLPTR));
	sprite->_internal.duration = duration;
	current = animation->_internal.list;
	while (current != FTX_NULLPTR && current->_internal.next != FTX_NULLPTR)
		current = current->_internal.next;
	if (current == FTX_NULLPTR)
	{
		animation->_internal.current = sprite;
		animation->_internal.list = sprite;
	}
	else
		current->_internal.next = sprite;
	ftx_sprite_show(sprite);
	ftx_sprite_hide(sprite);
	return (FTX_SUCCESS);
}

int	ftx_animation_update(t_animation *animation)
{
	if (animation == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_NULLPTR));
	if (animation->_internal.state != FTX_STATE_ON
		|| animation->_internal.current == FTX_NULLPTR)
		return (FTX_SUCCESS);
	if (ftx_elapsed() > animation->_internal.time)
	{
		ftx_sprite_hide(animation->_internal.current);
		if (animation->_internal.current->_internal.next != FTX_NULLPTR)
			animation->_internal.current
				= animation->_internal.current->_internal.next;
		else
		{
			if (animation->_internal.loop == FTX_STATE_ON)
				animation->_internal.current = animation->_internal.list;
			else
				return (ftx_animation_stop(animation));
		}
		animation->_internal.time = ftx_elapsed()
			+ animation->_internal.current->_internal.duration;
		ftx_sprite_show(animation->_internal.current);
	}
	return (FTX_SUCCESS);
}

int	ftx_animation_move(t_animation *animation, int x, int y)
{
	t_sprite	*current;

	current = animation->_internal.list;
	while (current != FTX_NULLPTR)
	{
		current->x += x;
		current->y += y;
		current = current->_internal.next;
	}
	return (FTX_SUCCESS);
}
