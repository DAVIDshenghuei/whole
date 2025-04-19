/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_core.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 08:49:53 by chugon            #+#    #+#             */
/*   Updated: 2025/04/18 11:36:55 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTX_CORE_H
# define FTX_CORE_H

# include "ftx_graphics.h"
# include "ftx_event.h"

typedef struct s_object
{
	void			*content;
	t_deleter		deleter;
	struct s_object	*next;
}	t_object;

typedef struct s_renderobject
{
	int						z;
	int						visibility;
	void					*content;
	t_renderer				renderer;
	struct s_renderobject	*next;
}	t_renderobject;

typedef struct s_engine
{
	int					error;
	int					width;
	int					height;
	char				*title;
	void				*mlx_ptr;
	void				*win_ptr;
	uint64_t			time;
	t_texture			*background;
	t_event_handler		events[FTX_NUMBEROF_EVENT];
	t_object			*objects;
	t_renderobject		*renderobjects;
	t_renderobject		*rendertexts;
	void				*user_data;
	t_deleter			user_delete;
}	t_engine;

/**
 * \brief Starts the engine and initializes the window.
 * \param title Title of the window
 * \param width Width of the window
 * \param height Height of the window
 * \return FTX_SUCCESS on success, non-zero integer on failure
 */
int			ftx_init(char *title, int width, int height);

/**
 * \brief Shutdowns the engine and decallocates all resources.
 * \return FTX_SUCCESS on success, non-zero integer on failure
 */
int			ftx_clear(void);

/**
 * \brief Starts the engine.
 * \return FTX_SUCCESS on success, non-zero integer on failure
 */
int			ftx_exec(void);

/**
 * \brief Stops the engine.
 * \return FTX_SUCCESS
 */
int			ftx_quit(void);

/**
 * \brief Sets the user-defined gamedata.
 * \param gamedata Pointer to the gamedata
 * \return FTX_SUCCESS
 */
int			ftx_userdata(void *userdata);

uint64_t	ftx_elapsed(void);

int			ftx_window_width(void);
int			ftx_window_height(void);
char		*ftx_window_title(void);

int			ftx_window_render(void);

/**
 * \brief Clears the window by removing all drawn elements on the screen.
 * \return FTX_SUCCESS
 */
int			ftx_window_clear(void);

/**
 * \brief Register event
 * \param event_type Type of event:
 * \li FTX_EVENT_UPDATE
 * \li FTX_EVENT_KEYPRESS
 * \li FTX_EVENT_KEYRELEASE
 * \li FTX_EVENT_MOUSEMOTION
 * \li FTX_EVENT_MOUSEPRESS
 * \li FTX_EVENT_MOUSERELEASE
 * \li FTX_EVENT_WINDOWCLOSE
 * \param callback Pointer to the function to be called when the corresponding
 * event is triggered
 * \return `FTX_SUCCESS` on success
 * \see e_event_type
 */
int			ftx_event_register(int event_type, t_event_handler handler);

#endif // FTX_CORE_H

/**
 * \file ftx_core.h
 * \author Christian Hugon &lt;chriss.hugon@gmail.com&gt;
 * \version 0.1
 * \brief Manipulates engine.
 */

/**
 * \struct s_window
 * \brief Window structure
 *
 * \var s_window::win_ptr
 * \brief Pointer to the window used by minilibx
 * \var s_window::title
 * \brief Title of the window
 * \var s_window::width
 * \brief Width of the window
 * \var s_window::height
 * \brief Height of the window
 * \var s_window::_internal
 * \brief Internal data structure
 * \warning For internal use only.
 * \var s_window::s_window_internal::buffer
 * \brief Image buffer for internal rendering
 */

/**
 * \struct s_engine
 * \brief Structure serves as the main engine structure.
 *
 * \var s_engine::gamedata
 * \brief User defined gamedata cast as <b>void *</b>
 * \var s_engine::mlx_ptr
 * \brief Pointer to the minilibx entity
 * \var s_engine::error
 * \brief Error code
 * \var s_engine::window
 * \brief Window structure
 * \see s_window
 * \var s_engine::events
 * \brief List of pointers to function, called when an event is triggered
 * \var s_engine::s_engine_events::update
 * \brief Update event, called at the start of each game loop
 * \var s_engine::s_engine_events::windowclose
 * \brief Called when the window is closed
 * \var s_engine::s_engine_events::keypress
 * \brief Called when a key is pressed
 * \var s_engine::s_engine_events::keyrelease
 * \brief Called when a key is released
 * \var s_engine::s_engine_events::mousemotion
 * \brief Called when the mouse is moved
 * \var s_engine::s_engine_events::mousepress
 * \brief Called when a mouse button is pressed
 * \var s_engine::s_engine_events::mouserelease
 * \brief Called when a mouse button is released
 */
