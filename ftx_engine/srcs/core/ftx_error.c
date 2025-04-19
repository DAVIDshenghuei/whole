/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:11:03 by chugon            #+#    #+#             */
/*   Updated: 2025/04/18 15:34:47 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftx_core.h"

t_engine	*ftx_internal__engine(void);
void		ftx_internal__error_put(const char *s);
int			ftx_internal__engine_check(void);

int	ftx_error(void)
{
	return (ftx_internal__engine()->error);
}

void	ftx_strerror(int error)
{
	static const char	*strerror[FTX_NUMBEROF_ERROR] = {
		FTX_STRERROR_SUCCESS, FTX_STRERROR_FAILURE, FTX_STRERROR_MEMORY,
		FTX_STRERROR_NULLPTR, FTX_STRERROR_MLX, FTX_STRERROR_WINDOW,
		FTX_STRERROR_TEXTURE, FTX_STRERROR_TEXTUREDATA, FTX_STRERROR_EVENT,
		FTX_STRERROR_PARAMETER, FTX_STRERROR_INDEX, FTX_STRERROR_ENGINE
	};

	if (error <= 0 || error >= FTX_NUMBEROF_ERROR)
		return ;
	ftx_internal__error_put("\033[91mERROR: \033[0m");
	ftx_internal__error_put(strerror[error]);
	ftx_internal__error_put("\n");
}

void	ftx_assert(int error)
{
	t_engine	*engine;

	if (error == FTX_SUCCESS)
		return ;
	if (ftx_internal__engine_check() != FTX_SUCCESS)
		ftx_strerror(FTX_ERROR_ENGINE);
	else
		ftx_strerror(error);
	ftx_quit();
	engine = ftx_internal__engine();
	if (engine->user_delete != FTX_NULLPTR)
		engine->user_delete(engine->user_data);
	ftx_clear();
	exit(EXIT_FAILURE);
}

void	ftx_assert_ptr(void *ptr)
{
	if (ptr == FTX_NULLPTR)
		ftx_assert(FTX_ERROR_NULLPTR);
}
