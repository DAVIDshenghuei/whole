/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 09:12:19 by chugon            #+#    #+#             */
/*   Updated: 2025/04/18 10:09:58 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftx_core.h"

t_engine		*ftx_internal__engine(void);
t_renderobject	*ftx_internal__renderobject_find(void *p,
					t_renderobject **l);
int				ftx_internal__renderobject_create(void *p,
					t_renderer r,
					t_renderobject **l);
int				ftx_internal__renderobject_insert(t_renderobject *o,
					t_renderobject **l);
int				ftx_internal__renderobject_remove(t_renderobject *o,
					t_renderobject **l);
int				ftx_internal__error(int e);

int	ftx_internal__show(void *param, t_renderer renderer, t_renderobject **list)
{
	t_renderobject	*object;

	if (param == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_NULLPTR));
	object = ftx_internal__renderobject_find(param, list);
	if (object != FTX_NULLPTR)
	{
		object->visibility = FTX_STATE_ON;
		return (FTX_SUCCESS);
	}
	return (ftx_internal__renderobject_create(param, renderer, list));
}

int	ftx_internal__hide(void *param, t_renderobject **list)
{
	t_renderobject	*object;

	if (param == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_NULLPTR));
	object = ftx_internal__renderobject_find(param, list);
	if (object != FTX_NULLPTR)
		object->visibility = FTX_STATE_OFF;
	return (FTX_SUCCESS);
}

int	ftx_internal__setzindex(void *param, int z, t_renderobject **list)
{
	t_renderobject	*object;

	if (param == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_NULLPTR));
	object = ftx_internal__renderobject_find(param, list);
	if (object == FTX_NULLPTR)
		return (FTX_FAILURE);
	object->z = z;
	if (ftx_internal__renderobject_remove(object, list) == FTX_SUCCESS)
		ftx_internal__renderobject_insert(object, list);
	return (FTX_SUCCESS);
}
