/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_renderobject.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:02:35 by chugon            #+#    #+#             */
/*   Updated: 2025/04/18 10:06:02 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ftx_core.h"

int	ftx_internal__error(int error);

t_renderobject	*ftx_internal__renderobject_find(void *content,
					t_renderobject **list)
{
	t_renderobject	*current;

	current = *list;
	while (current != FTX_NULLPTR)
	{
		if (current->content == content)
			return (current);
		current = current->next;
	}
	return (FTX_NULLPTR);
}

int	ftx_internal__renderobject_insert(t_renderobject *object,
		t_renderobject **list)
{
	t_renderobject	*current;

	current = *list;
	if (current == FTX_NULLPTR)
	{
		*list = object;
		return (FTX_SUCCESS);
	}
	if (object->z < current->z)
	{
		object->next = current;
		*list = object;
	}
	while (current != FTX_NULLPTR)
	{
		if (current->next == FTX_NULLPTR)
			break ;
		else if (object->z < current->next->z)
			break ;
		current = current->next;
	}
	object->next = current->next;
	current->next = object;
	return (FTX_SUCCESS);
}

int	ftx_internal__renderobject_remove(t_renderobject *object,
		t_renderobject **list)
{
	t_renderobject	*current;
	t_renderobject	*next;

	current = *list;
	if (current == FTX_NULLPTR || current->next == FTX_NULLPTR)
		return (FTX_FAILURE);
	while (current != FTX_NULLPTR)
	{
		next = current->next;
		if (next == object)
			break ;
		current = current->next;
	}
	current->next = next->next;
	next->next = FTX_NULLPTR;
	return (FTX_SUCCESS);
}

int	ftx_internal__renderobject_create(void *content,
		t_renderer renderer,
		t_renderobject **list)
{
	t_renderobject	*new;

	new = (t_renderobject *)malloc(sizeof(t_renderobject));
	if (new == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_MEMORY));
	new->z = 0;
	new->visibility = FTX_STATE_ON;
	new->content = content;
	new->next = FTX_NULLPTR;
	new->renderer = renderer;
	ftx_internal__renderobject_insert(new, list);
	return (FTX_SUCCESS);
}

int	ftx_internal__renderobject_clear(t_renderobject **list)
{
	t_renderobject	*current;
	t_renderobject	*delete;

	current = *list;
	while (current != FTX_NULLPTR)
	{
		delete = current;
		current = current->next;
		free(delete);
	}
	return (FTX_SUCCESS);
}
