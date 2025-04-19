/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_log.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 09:11:59 by chugon            #+#    #+#             */
/*   Updated: 2025/04/13 09:12:00 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "ftx_log.h"
#include "ftx_utils.h"

int	ftx_log(const char *fname, const char *log)
{
	ftx_putstr("\033[104m\033[1m[LOG]\033[0m in function `", STDOUT_FILENO);
	ftx_putstr(fname, STDOUT_FILENO);
	ftx_putstr("`: \033[37m", STDOUT_FILENO);
	ftx_putstr(log, STDOUT_FILENO);
	ftx_putstr("\033[0m\n", STDOUT_FILENO);
	return (EXIT_FAILURE);
}
