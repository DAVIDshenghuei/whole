/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_event.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:04:25 by chugon            #+#    #+#             */
/*   Updated: 2025/04/15 15:48:57 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTX_EVENT_H
# define FTX_EVENT_H

# include <X11/X.h>
# include <X11/keysym.h>

enum e_event_type
{
	FTX_EVENT_UPDATE = 0,
	FTX_EVENT_WINDOWCLOSE,
	FTX_EVENT_KEYPRESS = KeyPress,
	FTX_EVENT_KEYRELEASE = KeyRelease,
	FTX_EVENT_MOUSEPRESS = ButtonPress,
	FTX_EVENT_MOUSERELEASE = ButtonRelease,
	FTX_EVENT_MOUSEMOTION = MotionNotify,
	FTX_NUMBEROF_EVENT
};

enum e_event_mask
{
	FTX_MASK_KEYPRESS = KeyPressMask,
	FTX_MASK_KEYRELEASE = KeyReleaseMask,
	FTX_MASK_MOUSEPRESS = ButtonPressMask,
	FTX_MASK_MOUSERELEASE = ButtonReleaseMask,
	FTX_MASK_MOUSEMOTION = PointerMotionMask
};

enum e_keycode
{
	FTX_KEY_SPACE = XK_space,
	FTX_KEY_0 = XK_0,
	FTX_KEY_1 = XK_1,
	FTX_KEY_2 = XK_2,
	FTX_KEY_3 = XK_3,
	FTX_KEY_4 = XK_4,
	FTX_KEY_5 = XK_5,
	FTX_KEY_6 = XK_6,
	FTX_KEY_7 = XK_7,
	FTX_KEY_8 = XK_8,
	FTX_KEY_9 = XK_9,
	FTX_KEY_A = XK_a,
	FTX_KEY_B = XK_b,
	FTX_KEY_C = XK_c,
	FTX_KEY_D = XK_d,
	FTX_KEY_E = XK_e,
	FTX_KEY_F = XK_f,
	FTX_KEY_G = XK_g,
	FTX_KEY_H = XK_h,
	FTX_KEY_I = XK_i,
	FTX_KEY_J = XK_j,
	FTX_KEY_K = XK_k,
	FTX_KEY_L = XK_l,
	FTX_KEY_M = XK_m,
	FTX_KEY_N = XK_n,
	FTX_KEY_O = XK_o,
	FTX_KEY_P = XK_p,
	FTX_KEY_Q = XK_q,
	FTX_KEY_R = XK_r,
	FTX_KEY_S = XK_s,
	FTX_KEY_T = XK_t,
	FTX_KEY_U = XK_u,
	FTX_KEY_V = XK_v,
	FTX_KEY_W = XK_w,
	FTX_KEY_X = XK_x,
	FTX_KEY_Y = XK_y,
	FTX_KEY_Z = XK_z,
	FTX_KEY_LEFT = XK_Left,
	FTX_KEY_UP = XK_Up,
	FTX_KEY_RIGHT = XK_Right,
	FTX_KEY_DOWN = XK_Down
};

#endif // FTX_EVENT_H

/**
 * \file ftx_event.h
 * \author Christian Hugon &lt;chriss.hugon@gmail.com&gt;
 * \version 0.1
 * \brief Register callback functions to handle different events.
 */

/**
 * \enum e_event_type
 * \brief List of events
 * \var e_event_type::FTX_EVENT_UPDATE
 * \brief Update event
 */
