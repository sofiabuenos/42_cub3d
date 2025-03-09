/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:42:40 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/03/09 16:56:32 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <limits.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-mac/mlx.h"

# define NO "NO" // 0
# define SO "SO" // 1
# define EA "EA" // 2
# define WE "WE" // 3
# define F "F"
# define C "C"

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

typedef struct s_point
{
	unsigned int	x;
	unsigned int	y;
}					t_point;

typedef struct s_elements
{
	char	*id;
	char	*info;
	
} t_elements;

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
	int		foward;
	int		backward;
	int		left;
	int		right;
	int 	rot_left;
	int		rot_right;
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
	t_coord		dir;	// Direção do raio no espaço 2D
	t_coord		delta;	// Comprimento do raio de uma borda da célula até a próxima
	t_coord		side;	// Distância inicial do player até a primeira borda do grid
	t_coord		hit;	// Distancia do player da parede nas coordenadas x e y
	double		hit_dist; //Distancia do player da parede
	int			map_x;	// Posição do jogador convertida para células do mapa
	int			map_y;
	int			step_x;	// Passo e direção inicial do raio
	int			step_y;
	int			side_axis;
	t_texture	texture;	
}	t_ray;

typedef struct s_render
{
	double		wall_x; //posiçao exata na textua(wall), onde ocorreu a colisão
	int			wall_height; //coordenada correta na imagem 64x64
	double		scale; //escala da textura 
	int			draw_start; //onde começa a textura (wall)
	int			draw_end; //onde termina a textura (wall)
	int			text_x; //coordenada da textura em x
	int			text_y; //coordenada da textura em y
	double		texture_pos; // angulo do raio atual
	double		text_step; //angulo referente ao tamanho do passo entre raios
	int			color;
}	t_render;

typedef struct s_game
{
	char		*file_name;
	char		**map;
	char		**path;
	t_elements	*elements;
	t_player	*player;
	t_texture	wall[4];
	t_key		key;
	t_texture	*bground;
	t_ray		*ray;
	void		*mlx;
	void		*win;
	int			floor;
	int			ceiling;
	double		fov;
	//int			screen_h;
	//int			screen_w;
	t_render	*render;
}				t_game;

/*======= parse =======*/
int				parse(t_game *cub);
/*======= parse_elements =======*/
int				check_id(char *str, t_game *cub, int count);
int				is_valid_id(char *temp);
int				check_info(char *str, t_game *cub, int count); //https://github.com/widium/Cub3D/blob/main/srcs/engine/raycasting.c#L55
int				check_RGB(char *str, t_game *cub, int count);
int				check_path(char *str, t_game *cub, int count);
/*======= parse utils =======*/
int				word_count(char *str);
int				there_are_commas(char *str);
unsigned int	index_to_word(char *str, int nb);
int				unique_ids(t_game *cub);
/*======= Error =======*/
void			print_err(char *str);
void			power_print_err(char *s1, char *s2);
void			ft_destroy(t_game *cub);
void			quit(t_game *cub);
void			free_array(char **str);
/*======= init =======*/
int				init(char **av, t_game *cub);
void			print_elements(t_game *cub);

/*======= main =======*/


/*======= init game =======*/
void			init_mlx(t_game *cub);
void			init_textures(t_game *cub);
void			get_texture_and_color(t_game *cub);
void			init_background(t_game *cub);
void			init_player(t_game	*cub);

/*======= keys =======*/
int				keypress(int keycode, t_game *cub);
int				keyrelease(int keycode, t_game *cub);

/*======= moves =======*/
void			handle_move(t_game *cub);
void			move_forward(t_game *cub);
void			move_backward(t_game *cub);
void			move_left(t_game *cub);
void			move_right(t_game *cub);

/*======= raycast =======*/
void			ray_info(t_game *cub, double ray_angle);
void			dda(t_game *cub);
void			get_delta_distance_y(t_game *cub, double ray_dir_y);
void			get_delta_distance_x(t_game *cub, double ray_dir_x);
void			get_texture_index(t_game *cub);

/*======= render =======*/
void			my_mlx_pixel_put(t_texture	*bground, int x, int y, int color);
void			draw_background(t_game *cub);
void			draw_walls(t_game *cub, int x, int begin, int end);
void			define_draw_points(t_game *cub);
void			render(t_game *cub);

/*======= utils =======*/
int				convert_to_rgb(char	*colors, t_game *cub);
void			my_mlx_pixel_put_color(t_texture *bground, int x, int y, int color);
unsigned int	my_mlx_pixel_get_color(t_texture *wall, int x, int y);

/*======= quit_game =======*/
int			quit_game(t_game *cub);
void			error_msg(t_game *cub, char *msg);
void			free_textures(t_game *cub);


void read_cub_file(char *filename, t_game *game);
void parse_map(char *line, t_game *game, int row);

#endif