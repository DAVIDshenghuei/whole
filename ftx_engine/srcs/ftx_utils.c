/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 09:12:30 by chugon            #+#    #+#             */
/*   Updated: 2025/04/15 16:11:12 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "ftx_utils.h"
#include "ftx_error.h"

void	*ftx_memset(void *b, int c, int len)
{
	unsigned char	*dst;

	dst = (unsigned char *)b;
	while (len > 0)
	{
		*dst = (unsigned char)c;
		++dst;
		--len;
	}
	return (b);
}

void	ftx_zero(void *ptr, int size)
{
	unsigned char	*uc_ptr;

	uc_ptr = (unsigned char *)ptr;
	while (size > 0)
	{
		*uc_ptr = 0;
		++uc_ptr;
		--size;
	}
}

int	ftx_putstr(const char *s, int fd)
{
	if (s == NULL)
		return (FTX_FAILURE);
	while (*s != '\0')
	{
		if (write(fd, s, 1) < 0)
			return (FTX_FAILURE);
		++s;
	}
	return (FTX_SUCCESS);
}

int	ftx_putnum(int n, int fd)
{
	char	digit;

	if (n < 0)
	{
		n = (~n) + 1;
		write(fd, "-", 1);
	}
	if (n == 0)
		write(fd, "0", 1);
	else if (n > 9)
		ftx_putnum(n / 10, fd);
	digit = n % 10 + '0';
	write(fd, &digit, 1);
	return (FTX_SUCCESS);
}
