/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_animation1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:11:37 by chugon            #+#    #+#             */
/*   Updated: 2025/04/18 10:18:58 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftx_core.h"

int	ftx_internal__error(int e);

int	ftx_animation_play(t_animation *animation)
{
	if (animation == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_NULLPTR));
	animation->_internal.state = FTX_STATE_ON;
	ftx_sprite_hide(animation->_internal.current);
	animation->_internal.current = animation->_internal.list;
	animation->_internal.time = ftx_elapsed()
		+ animation->_internal.current->_internal.duration;
	return (ftx_sprite_show(animation->_internal.current));
}

int	ftx_animation_resume(t_animation *animation)
{
	if (animation == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_NULLPTR));
	if (animation->_internal.state == FTX_STATE_ON)
		return (FTX_SUCCESS);
	animation->_internal.state = FTX_STATE_ON;
	animation->_internal.time += ftx_elapsed();
	return (ftx_sprite_show(animation->_internal.current));
}

int	ftx_animation_pause(t_animation *animation)
{
	if (animation == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_NULLPTR));
	if (animation->_internal.state == FTX_STATE_OFF)
		return (FTX_SUCCESS);
	animation->_internal.state = FTX_STATE_OFF;
	animation->_internal.time -= ftx_elapsed();
	return (FTX_SUCCESS);
}

int	ftx_animation_stop(t_animation *animation)
{
	ftx_animation_pause(animation);
	return (ftx_sprite_hide(animation->_internal.current));
}

int	ftx_animation_setloop(t_animation *animation, int loop)
{
	if (animation == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_NULLPTR));
	if (loop == 0)
		animation->_internal.loop = FTX_STATE_OFF;
	else
		animation->_internal.loop = FTX_STATE_ON;
	return (FTX_SUCCESS);
}
