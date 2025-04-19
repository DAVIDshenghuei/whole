/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 08:49:39 by chugon            #+#    #+#             */
/*   Updated: 2025/04/19 06:58:01 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTX_TYPES_H
# define FTX_TYPES_H

# include <stdint.h>
# include <sys/time.h>
# include <stdlib.h>

# include "ftx_error.h"

/// \brief Null pointer
# define FTX_NULLPTR			NULL

/// \brief Default window title
# define FTX_DEFAULT_TITLE		"42X Engine Demo"

/// \brief Default window width
# define FTX_DEFAULT_WIDTH		1024

/// \brief Default window height
# define FTX_DEFAULT_HEIGHT		720

# define FTX_TEXTBUFFER_SIZE	1024

# define FTX_COLOR_MAX			255

typedef struct s_engine	t_engine;

typedef struct timeval	t_time;

typedef int				(*t_allocator)(void *, void *);
typedef void			(*t_deleter)(void *);
typedef int				(*t_renderer)(void *);
typedef int				(*t_event_handler)();

enum e_state
{
	FTX_STATE_OFF,
	FTX_STATE_ON
};

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_area
{
	int	x;
	int	y;
	int	w;
	int	h;
}	t_area;

#endif // FTX_TYPES_H

/**
 * \file ftx_types.h
 * \author Christian Hugon &lt;chriss.hugon@gmail.com&gt;
 * \version 0.1
 * \brief Constants and Macros.
 */
