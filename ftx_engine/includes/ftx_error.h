/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:04:57 by chugon            #+#    #+#             */
/*   Updated: 2025/04/18 15:16:14 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTX_ERROR_H
# define FTX_ERROR_H

# include "ftx_types.h"

enum e_error
{
	FTX_SUCCESS = 0,
	FTX_FAILURE,
	FTX_ERROR_MEMORY,
	FTX_ERROR_NULLPTR,
	FTX_ERROR_MLX,
	FTX_ERROR_WINDOW,
	FTX_ERROR_TEXTURE,
	FTX_ERROR_TEXTUREDATA,
	FTX_ERROR_EVENT,
	FTX_ERROR_PARAMETER,
	FTX_ERROR_INDEX,
	FTX_ERROR_ENGINE,
	FTX_NUMBEROF_ERROR
};

# define FTX_STRERROR_SUCCESS		"No error"
# define FTX_STRERROR_FAILURE		"Undefined error"
# define FTX_STRERROR_MEMORY		"Memory allocation failed"
# define FTX_STRERROR_NULLPTR		"NULL pointer parameter"
# define FTX_STRERROR_MLX			"MiniLibX initialization failed"
# define FTX_STRERROR_WINDOW		"Window initialization failed"
# define FTX_STRERROR_TEXTURE		"Texture is missing"
# define FTX_STRERROR_TEXTUREDATA	"Texture data is missing"
# define FTX_STRERROR_EVENT			"Invalid event"
# define FTX_STRERROR_PARAMETER		"Invalid parameter"
# define FTX_STRERROR_INDEX			"Out of bound index"
# define FTX_STRERROR_ENGINE		"Engine not initialized"

int		ftx_error(void);

void	ftx_strerror(int error);

void	ftx_assert(int error);

void	ftx_assert_ptr(void *ptr);

#endif // FTX_ERROR_H

/**
 * \file ftx_error.h
 * \author Christian Hugon &lt;chriss.hugon@gmail.com&gt;
 * \version 0.1
 * \brief Error code
 */

/**
 * \enum e_error
 * \brief Error code
 *
 * \var e_error::FTX_SUCCESS
 * \brief No Error
 * \var e_error::FTX_FAILURE
 * \brief Unspecified error
 * \var e_error::FTX_EMLXINIT
 * \brief Failed to initialize \b minilibx
 * \var e_error::FTX_EWININIT
 * \brief Failed to create a window
 * \var e_error::FTX_EIMGINIT
 * \brief Failed to create an image
 * \var e_error::FTX_EIMGDATA
 * \brief Failed to load image data
 * \var e_error::EEVENTID
 * \brief Unknown event type
 */
