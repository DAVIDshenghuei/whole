/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_internal_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:14:13 by chugon            #+#    #+#             */
/*   Updated: 2025/04/18 12:14:16 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftx_core.h"

int	ftx_internal__renderall(t_renderobject *list)
{
	t_renderobject	*object;

	object = list;
	while (object != FTX_NULLPTR)
	{
		if (object->visibility == FTX_STATE_ON)
			object->renderer(object->content);
		object = object->next;
	}
	return (FTX_SUCCESS);
}
