/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_internal_engine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:13:53 by chugon            #+#    #+#             */
/*   Updated: 2025/04/18 12:13:55 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ftx_core.h"

t_engine	*ftx_internal__engine(void)
{
	static t_engine	engine_instance;

	return (&engine_instance);
}

int	ftx_internal__error(int error)
{
	ftx_internal__engine()->error = error;
	return (error);
}

void	ftx_internal__error_put(const char *str)
{
	while (*str != '\0')
	{
		write(STDERR_FILENO, str, 1);
		++str;
	}
}

int	ftx_internal__engine_check(void)
{
	t_engine	*engine;

	engine = ftx_internal__engine();
	if (engine->mlx_ptr == FTX_NULLPTR)
	{
		engine->error = FTX_ERROR_MLX;
		return (FTX_ERROR_MLX);
	}
	if (engine->win_ptr == FTX_NULLPTR)
	{
		engine->error = FTX_ERROR_WINDOW;
		return (FTX_ERROR_WINDOW);
	}
	return (FTX_SUCCESS);
}
