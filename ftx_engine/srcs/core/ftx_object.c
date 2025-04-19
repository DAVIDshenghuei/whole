/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:05:15 by chugon            #+#    #+#             */
/*   Updated: 2025/04/18 14:20:52 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftx_core.h"
#include "ftx_error.h"

t_engine	*ftx_internal__engine(void);
int			ftx_internal__error(int e);

int	ftx_internal__object_create(void *content, t_deleter deleter)
{
	t_object	*current;
	t_object	*new;

	new = (t_object *)malloc(sizeof(t_object));
	if (new == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_MEMORY));
	new->content = content;
	new->deleter = deleter;
	new->next = FTX_NULLPTR;
	current = ftx_internal__engine()->objects;
	while (current != FTX_NULLPTR && current->next != FTX_NULLPTR)
		current = current->next;
	if (current == FTX_NULLPTR)
		ftx_internal__engine()->objects = new;
	else
		current->next = new;
	return (FTX_SUCCESS);
}

int	ftx_internal__object_clear(void)
{
	t_object	*current;
	t_object	*delete;

	current = ftx_internal__engine()->objects;
	while (current != FTX_NULLPTR)
	{
		delete = current;
		current = current->next;
		delete->deleter(delete->content);
		free(delete);
	}
	return (FTX_SUCCESS);
}
