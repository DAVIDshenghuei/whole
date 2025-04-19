/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_allocator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:03:47 by chugon            #+#    #+#             */
/*   Updated: 2025/04/18 16:29:31 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftx_graphics.h"
#include "ftx_core.h"
#include "ftx_error.h"

int		ftx_internal__error(int e);
int		ftx_internal__object_create(void *p, t_deleter d);
char	*ftx_internal__strdup(const char *s);
void	ftx_internal__text_deleter(void *p);

void	*ftx_internal__allocate(size_t s, t_deleter d, t_allocator a, void *p);

// t_point	*ftx_point(int x, int y, t_color color)
// {
// 	t_point			*point;

// 	point = (t_point *)malloc(sizeof(t_point));
// 	if (point == FTX_NULLPTR)
// 		return (ftx_internal__error(FTX_ERROR_MEMORY), FTX_NULLPTR);
// 	point->x = x;
// 	point->y = y;
// 	point->thickness = 1;
// 	point->color = color;
// 	if (ftx_internal__object_create(point, &free) == FTX_SUCCESS)
// 		return (point);
// 	return (FTX_NULLPTR);
// }

// t_animation	*ftx_animation(void)
// {
// 	t_animation	*animation;

// 	animation = (t_animation *)malloc(sizeof(t_animation));
// 	if (animation == FTX_NULLPTR)
// 		return (ftx_internal__error(FTX_ERROR_MEMORY), FTX_NULLPTR);
// 	animation->_internal.state = FTX_STATE_OFF;
// 	animation->_internal.loop = FTX_STATE_OFF;
// 	animation->_internal.current = FTX_NULLPTR;
// 	animation->_internal.list = FTX_NULLPTR;
// 	animation->_internal.time = ftx_elapsed();
// 	if (ftx_internal__object_create(animation, &free) == FTX_SUCCESS)
// 		return (animation);
// 	return (FTX_NULLPTR);
// }

// t_text	*ftx_text(char *str, int x, int y, t_color color)
// {
// 	t_text	*text;

// 	if (str == FTX_NULLPTR)
// 		return (ftx_internal__error(FTX_ERROR_NULLPTR), FTX_NULLPTR);
// 	text = (t_text *)malloc(sizeof(t_text));
// 	if (text == FTX_NULLPTR)
// 		return (ftx_internal__error(FTX_ERROR_MEMORY), FTX_NULLPTR);
// 	text->x = x;
// 	text->y = y;
// 	text->color = color;
// 	text->_internal.str = ftx_internal__strdup(str);
// 	if (text->_internal.str == FTX_NULLPTR)
// 		return (free(text), FTX_NULLPTR);
// 	if (ftx_internal__object_create(text, &ftx_internal__text_deleter)
// 		== FTX_SUCCESS)
// 		return (text);
// 	return (FTX_NULLPTR);
// }
