/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 09:12:40 by chugon            #+#    #+#             */
/*   Updated: 2025/04/16 14:22:54 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTX_UTILS_H
# define FTX_UTILS_H

/**
 * @brief Writes `len` bytes of value `c` (converted to an unsigned char)
 * to the memory area `b`.
 * @param b
 * @param c
 * @param len
 * @return Returns its firtst argument.
 */
void	*ftx_memset(void *b, int c, int len);

void	ftx_zero(void *ptr, int size);

/**
 * @brief Writes the string pointed to by `s` to the file descriptor `fd`.
 * @param s
 * @param fd
 * @return Returns `0` on success, non-zero integer on failure.
 */
int		ftx_putstr(const char *s, int fd);

int		ftx_putnum(int num, int fd);

#endif // FTX_UTILS_H

/**
 * \file ftx_utils.h
 * \author Christian Hugon &lt;chriss.hugon@gmail.com&gt;
 * \version 0.1
 * \brief Utilities functions.
 */
