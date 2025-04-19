/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_internal_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:34:00 by chugon            #+#    #+#             */
/*   Updated: 2025/04/19 07:08:43 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftx_core.h"

int	ftx_internal__error(int e);

int	ftx_internal__limit_check(int value, int min, int max)
{
	if (value < min || value > max)
		return (ftx_internal__error(FTX_ERROR_INDEX));
	return (FTX_SUCCESS);
}
