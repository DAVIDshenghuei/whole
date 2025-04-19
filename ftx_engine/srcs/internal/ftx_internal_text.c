/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_internal_text.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:01:33 by chugon            #+#    #+#             */
/*   Updated: 2025/04/18 12:14:00 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "ftx_graphics.h"

#define FTX_STRING_NULL	"(null)"

int	ftx_internal__error(int error);

char	*ftx_internal__strdup(const char *str)
{
	char	*retval;
	int		size;

	if (str == FTX_NULLPTR)
		return (FTX_NULLPTR);
	size = 0;
	while (str[size] != '\0')
		++size;
	retval = (char *)malloc(sizeof(char) * (size + 1));
	if (retval == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_MEMORY), FTX_NULLPTR);
	size = -1;
	while (str[++size] != '\0')
		retval[size] = str[size];
	retval[size] = '\0';
	return (retval);
}

int	ftx_internal__parse_str(char buffer[], int *index, char *arg)
{
	if (arg == FTX_NULLPTR)
		arg = FTX_STRING_NULL;
	while (*arg != '\0')
	{
		buffer[(*index)++] = *arg;
		++arg;
	}
	return (FTX_SUCCESS);
}

int	ftx_internal__parse_num(char buffer[], int *index, long arg)
{
	char	digit;

	if (arg < 0)
	{
		buffer[(*index)++] = '-';
		arg = -arg;
	}
	if (arg == 0)
		return (buffer[(*index)++] = '0', FTX_SUCCESS);
	else if (arg > 9)
		ftx_internal__parse_num(buffer, index, arg / 10);
	digit = arg % 10 + '0';
	buffer[(*index)++] = digit;
	return (FTX_SUCCESS);
}

char	*ftx_internal__parse_args(const char *format, va_list *list)
{
	static char	buffer[FTX_TEXTBUFFER_SIZE];
	int			i;

	i = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			++format;
			if (*format == 's')
				ftx_internal__parse_str(buffer, &i, va_arg(*list, char *));
			else if (*format == 'd')
				ftx_internal__parse_num(buffer, &i, (long)va_arg(*list, int));
			else
				buffer[i++] = '%';
		}
		else
			buffer[i++] = *format;
		if (*format != '\0')
			++format;
	}
	buffer[i] = '\0';
	return (buffer);
}
