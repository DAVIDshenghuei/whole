#ifndef CUB3D_H
#define CUB3D_H

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

typedef struct s_map
{
	int		width;
	int		height;
	char	**data;
}	t_map;