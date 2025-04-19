/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_graphics.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 09:11:51 by chugon            #+#    #+#             */
/*   Updated: 2025/04/19 11:24:54 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTX_GRAPHICS_H
# define FTX_GRAPHICS_H

# include "ftx_types.h"

typedef union u_color
{
	int	argb;
	struct
	{
		uint8_t	b;
		uint8_t	g;
		uint8_t	r;
		uint8_t	a;
	};
}	t_color;

typedef struct s_point
{
	int		x;
	int		y;
	int		thickness;
	t_color	color;
}	t_point;

typedef struct s_texture
{
	struct s_texture_internal
	{
		void	*img_ptr;
		char	*data;
		int		width;
		int		height;
		int		bpp;
		int		lsize;
		int		endian;
	}	_internal;
}	t_texture;

typedef struct s_sprite
{
	int	x;
	int	y;
	int	width;
	int	height;
	struct s_sprite_internal
	{
		int				x;
		int				y;
		int				duration;
		t_texture		*texture;
		struct s_sprite	*next;
	}	_internal;
}	t_sprite;

typedef struct s_animation
{
	struct s_animation_internal
	{
		int			loop;
		int			state;
		uint64_t	time;
		t_sprite	*current;
		t_sprite	*list;
	}	_internal;
}	t_animation;

typedef struct s_text
{
	int		x;
	int		y;
	t_color	color;
	struct s_text_internal
	{
		char	*str;
	}	_internal;
}	t_text;

t_point		*ftx_point(int x, int y, t_color color);
int			ftx_point_show(t_point *point);
int			ftx_point_hide(t_point *point);

t_text		*ftx_text(char *str, int x, int y, t_color color);
int			ftx_text_format(t_text *text, const char *format, ...);
int			ftx_text_show(t_text *text);
int			ftx_text_hide(t_text *text);

int			ftx_pixel_render(t_color color, int x, int y);

/**
 * \brief Returns a new pointer to the animation allocated with `malloc(3)`.
 * \return Pointer to the animation, or FTX_NULLPTR if allocation failed
 */
t_animation	*ftx_animation(void);

/**
 * \brief Adds a frame to the animation
 * \param animation Pointer to the animation
 * \param sprite Pointer to the sprite used as a frame for the animation
 * \param duration Duration of the frame in ms
 */
int			ftx_animation_addframe(t_animation *animation,
				t_sprite *sprite, int duration);

/**
 * \brief Moves all the frames int the animation at once
 * \param animation Pointer to the animation
 * \param x Offset on X-axis
 * \param y Offset on Y-axis
 * \return FTX_SUCCESS
 */
int			ftx_animation_move(t_animation *animation, int x, int y);

int			ftx_animation_setloop(t_animation *animation, int loop);
int			ftx_animation_play(t_animation *animation);
int			ftx_animation_resume(t_animation *animation);
int			ftx_animation_pause(t_animation *animation);
int			ftx_animation_stop(t_animation *animation);

/**
 * \brief Updates the animation
 * \param animation Pointer to the animation
 * \return FTX_SUCCESS
 */
int			ftx_animation_update(t_animation *animation);

/**
 * \brief Returns a pointer to the sprite allocated with `malloc(3)`.
 * \param x Position on X-axis
 * \param y Position on Y-axis
 * \param width Width of the sprite
 * \param height Height of the sprite
 * \return Pointer to sprite, or FTX_NULLPTR if allocation failed
 */
t_sprite	*ftx_sprite(int x, int y, int width, int height);

/**
 * \brief Modifies the current texture of the sprite
 * \param sprite Pointer to the sprite
 * \param texture Pointer to the image used as texture
 * \return FTX_SUCCESS
 */
int			ftx_sprite_settexture(t_sprite *sprite, t_texture *texture,
				int x, int y);

int			ftx_sprite_show(t_sprite *sprite);

int			ftx_sprite_hide(t_sprite *sprite);

int			ftx_sprite_setzindex(t_sprite *sprite, int z);

/**
 * \brief Instanciate a new color
 * \param r
 * \param g
 * \param b
 * \return Color
 */
t_color		ftx_color(uint8_t r, uint8_t g, uint8_t b);

/**
 * \brief Blends two colors.
 * \details This function handles transparency
 * \param old
 * \param new
 * \return
 */
t_color		ftx_color_blend(t_color old, t_color new);

/**
 * \brief Creates a new image from a XPM file.
 * \param engine Pointer to the engine
 * \param image Pointer to the image to store the result
 * \param filename Filename to load
 * \return Returns `0` on success, `1` on failure
 */
t_texture	*ftx_texture_xpm(char *filename);

/**
 * \brief Creates a new image.
 * \param image Pointer to the image to store the result
 * \param width Width of the image to create
 * \param height Height of the image to create
 * \return Returns `0` on success, `1` on failure
 */
t_texture	*ftx_texture(int width, int height);

int			ftx_texture_width(t_texture *texture);
int			ftx_texture_height(t_texture *texture);

/**
 * \brief Modify the color of a pixel in an image.
 * \param image Pointer to the image
 * \param color	New color of the pixel
 * \param x X-coordinate of pixel to modify
 * \param y	Y-coordinate of pixel to modify
 * \return Returns `0` on success, non-zero integer on failure
 */
int			ftx_texture_setcolor(t_texture *texture, t_color color,
				int x, int y);

/**
 * \brief Fills the whole image with a single color.
 * \param image Pointer to the image
 * \param color Color to fill
 * \return Returns `0` on success, non-zero integer on failure
 */
int			ftx_texture_fillall(t_texture *texture, t_color color);

int			ftx_texture_fillarea(t_texture *texture, t_color color, t_area area);

/**
 * \brief Returns the color of the pixel located at position (x, y).
 * \param image Pointer to the image
 * \param x X-coordinate of the pixel to get
 * \param y Y-coordinate of the pixel to get
 * \return Color of the pixel
 */
t_color		ftx_texture_getcolor(t_texture *texture, int x, int y);

#endif // FTX_GRAPHICS_H

/**
 * \file ftx_image.h
 * \author Christian Hugon &lt;chriss.hugon@gmail.com&gt;
 * \version 0.1
 * \brief Functions for manipulating color and image.
 */

/**
 * \union u_color
 * \brief ARGB color
 * \details Alpha component represents the transparency.
 * A color with an alpha value of 255 is fully transparent.
 *
 * \var u_color::argb
 * \brief ARGB color represented as integer
 * \var u_color::a
 * \brief Alpha component
 * \var u_color::r
 * \brief Red component
 * \var u_color::g
 * \brief Green component
 * \var u_color::b
 * \brief Blue component
 */

/**
 * \struct s_image
 * \brief Image structure
 *
 * \var s_image::img_ptr
 * \brief Pointer to minilibx image structure
 * \var s_image::width
 * \brief Width of the image
 * \var s_image::height
 * \brief Height of the image
 * \var s_image::_internal
 * \brief Internal data structure
 * \warning For internal use only.
 * \var s_image::s_image_internal::data
 * \brief Data buffer
 * \var s_image::s_image_internal::bpp
 * \brief Bits per pixel
 * \var s_image::s_image_internal::lsize
 * \brief Number of bytes per line
 * \var s_image::s_image_internal::endian
 * \brief \b 1 for big endian, \b 0 for little endian
 */
