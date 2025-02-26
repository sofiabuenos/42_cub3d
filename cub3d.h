/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheila <sheila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:59:35 by shrodrig          #+#    #+#             */
/*   Updated: 2025/02/26 18:28:44 by sheila           ###   ########.fr       */
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
# define SIZE 64
# define PI 3.14159265359
# define ROTATE 0.02
# define MOVE_SPEED 0.05
//# define BOUNDARY 0.1

# define ESC	65307
# define LEFT	65361
# define RIGHT	65363
# define W		119
# define A		97
# define S		115
# define D		100

# define NO		0
# define SO		1
# define EA		2
# define WE		3


/*
typedef struct s_map
{
	char	**map; //grid do mapa [y][x]
	
	
	}	t_map;
	*/

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;


typedef struct	s_texture
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_texture;

typedef struct s_key
{
	int	foward;
	int	backward;
	int	left;
	int	right;
	int rot_left;
	int	rot_right;
}	t_key;

typedef struct s_player
{
	t_coord		pos;
	t_coord		dir;
	double		angle;
	char		pov;
}	t_player;

typedef struct s_ray
{
	t_coord		dir; // Direção do raio no espaço 2D
	t_coord		delta; // Comprimento do raio de uma borda da célula até a próxima
	t_coord		side; // Distância inicial até a primeira borda do grid
	t_coord		hit; // Distancia do player da parede
	int			map_x; // Posição do jogador convertida para células do mapa
	int			map_y;
	int			step_x; // Passo e direção inicial do raio
	int			step_y;
	double		wall_x;
	int			side_axis;
	
}	t_ray;

typedef struct s_render
{
	int			nbr_text;
	t_texture	*image;
	

}	t_render;

typedef struct s_game
{
	t_player	*player;
	t_texture	wall[4];
	char		texture[4];
	//int			screen_h;
	//int			screen_w;
	void		*mlx;
	void		*win;
	//t_texture	*image;
	t_key		key;
	t_texture	*bground;
	t_ray		*ray;
	t_render	*render;
	double		fov;
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