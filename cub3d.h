#ifndef CUB3D_H
#define CUB3D_H

# include <sys/time.h>

# include <libft.h>

// # define C3D_BUFFSIZE 1024

// # define C3D_GAME_NAME "Cub3D"
# define C3D_WINDOW_WIDTH 1024
# define C3D_WINDOW_HEIGHT 720
// # define C3D_MINIMAP_WIDTH 11
// # define C3D_MINIMAP_HEIGHT 11

// # define C3D_FRAME_COUNT 20

typedef struct timeval	t_fps;
typedef struct s_data
{

}   t_data;

#endif


typedef struct s_map
{
	int		width;
	int		height;
	char	**data;
}	t_map;

typedef struct s_player
{
	t_bool		set;
	double		angle;
	t_vector	position;
}	t_player;

typedef struct s_ray
{
	t_vector	camera;
	t_vector	dir;
	t_vector	ray_dir;
	t_vector	side;
	t_vector	delta;
	t_vector	plane;
	t_coord		map;
	t_coord		step;
	double		wall_dist;
	double		wallx;
	int			surface;
	int			line_height;
	int			draw_start;
	int			draw_end;
}	t_ray;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

#endif

////////////////////render///////////


# define C3D_BYTES_PER_COLOR 4
typedef enum e_texture_id
{
	C3D_TID_N = 0,
	C3D_TID_S,
	C3D_TID_W,
	C3D_TID_E,
	C3D_TEXTURE_COUNT,
	C3D_TID_F = C3D_TEXTURE_COUNT,
	C3D_TID_C,
	C3D_TOTAL_COUNT
}	t_tid;


typedef struct renderdata
{
	double		step;
	double		pos;
	int			x;
	int			y;
	t_texture	*texture;
}	t_renderdata;

typedef struct s_data
{
	t_display	display;
	t_texture	texture[C3D_TOTAL_COUNT];
	t_animation	animation;
	t_map		map;
	t_minimap	minimap;
	t_player	player;
	t_ray		ray;
	t_fps		fps;
	t_error		error;
	t_bool		update;
	t_image		screen;
}	t_data;

typedef union u_color
{
	int	rgb;
	struct
	{
		char	b;
		char	g;
		char	r;
		char	a;
	};
}	t_color;

typedef struct s_image
{
	void	*data;
	char	*buffer;
	int		width;
	int		height;
	int		bpp;
	int		bytes;
	int		endian;
}	t_image;
