/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheila <sheila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:59:35 by shrodrig          #+#    #+#             */
/*   Updated: 2025/02/23 22:01:20 by sheila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include "lib/libft/libft.h"
# include "lib/mlx/mlx.h"

# define WIDTH 1080
# define HEIGHT 720
# define MOVE_SPEED 0.5
# define ROTATE 0.02
# define SIZE 64
# define PI 3.14159265359

# define ESC	65307
# define LEFT	65361
# define RIGHT	65363
# define W		119
# define A		97
# define S		115
# define D		100

typedef struct	s_texture
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_texture;

typedef struct s_map
{
	
	

}	t_map;

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

typedef struct s_key
{
	int	up;
	int	down;
	int	left;
	int	right;
	int rot_left;
	int	rot_right;
}	t_key;


typedef struct s_player
{
	t_coord		*pos;
	t_coord		dir;
	double		angle;
	char		pov;
	

}	t_player;

typedef struct s_ray
{
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	double		delta_x;
	double		delta_y;
	double		side_x;
	double		side_y;
	int			step_x;
	int			step_y;
	double		wall_x;
	int			side;
	
}	t_ray;

typedef struct s_game
{
	t_player	*player;
	t_texture	img[4];
	char		texture[4];
	int			screen_h;
	int			screen_w;
	void		*mlx;
	void		*win;
	t_key		key;
	t_texture	*bground;
	t_ray		*ray;
	//t_map		*map;
}	t_game;

//------------------------- INIT -------------------------------------
void	init_mlx(t_game *cub);
void	init_textures(t_game *cub);
void	init_player(t_game	*cub);


int		keypress(int keycode, t_game *cub);
int		keyrelease(int keycode, t_game *cub);
void	quit_game(t_game *cub);





#endif