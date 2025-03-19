/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:42:40 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/03/19 16:04:24 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include <limits.h>
# include <math.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-mac/mlx.h"

# define NO "NO " //0
# define SO "SO " //1
# define EA "EA " //2
# define WE "WE " //3
# define F "F "
# define C "C "

# define ER_PARAM "Invalid argument. Usage: ./cub3D path_to_file.cub"
# define ER_FILE "Invalid file. The file must exist and have a .cub extension.\
	Usage: ./cub3D path_to_file.cub"
# define ER_OPEN "Unable to open file"
# define ER_EMPTY "Invalid file. The .cub file is empty"
# define ER_ELMENT "Invalid element format. Usage: ID info. eg: \
	NO path_to_texture.xpm or F 0,255,255"
# define ER_INCOMPLETE "Game setting incomplete or invalid ID"
# define ER_EMPTY_LINE "Invalid map. The map must not contain empty lines"
# define ER_MAPGEN "A valid map is required"
# define ER_RGB "Invalid RGB format. Colors must be three numbers separated by commas,\
	 each ranging from 0 to 255. Example: 0,255,255"
# define ER_TEXTURE "Invalid path. NO, SO, WE, and EA must be followed by a valid \
	.xpm file path."

# define WIDTH 1080
# define HEIGHT 720
# define SIZE 64
# define PI 3.14159265359
# define ROTATE 0.02
# define MOVE_SPEED 0.05

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

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

typedef struct s_texture
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
	int		rot_left;
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
	t_coord		delta;//Comprimento do raio de uma borda da célula até a próxima
	t_coord		side; //Distância inicial do player até a primeira borda do grid
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
	double		wall_x; //posiçao exata na textura(wall), onde ocorreu a colisão
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
	char		*file;
	char		**map;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	char		*f_color;
	char		*c_color;
	int			fd;
	t_texture	*bground;
	t_texture	wall[4];
	t_player	*player;
	t_render	*render;
	t_ray		*ray;
	t_key		key;
	void		*mlx;
	void		*win;
	int			floor;
	int			ceiling;
	double		fov;
}			t_game;

/*====== init ======*/
void			init(t_game *cub);
void			print_elements(t_game *cub);

/*====== parse ======*/
void			parse(t_game *cub, int ac, char **av);
void			check_param(t_game *cub, int ac, char **av);
void			check_filename(t_game *cub, char **av);
void			read_file(t_game *cub, char *file);
void			check_empty_file(t_game *cub);
void			parse_file(t_game *cub);
void			parse_elements(t_game *cub);

/*==== read_utils ====*/
void			insert_spaces(char *str, char *new_str);
int				have_tabs(char *str);
char			*check_tabs(t_game *cub, char *str);
bool			is_empty_line(char *str);
void			last_line(t_game *cub, int i, int j);

/*=== parse_elements ===*/
bool			rgb_ok(char *str);
bool			commas_ok(char *str);
bool			str_is_digit(char *str);
bool			texture_ok(char *str);

/*=== parse_map ===*/
void			parse_map(t_game *cub);
void			get_player_position(t_game *cub, char **map);
void			check_is_empty(t_game *cub, char *row);

/*======= parse utils =======*/
char			*is_element(char *str);
void			get_info(t_game *cub, char *str, char *element);
void			check_duplicate(t_game *cub, char *element, char *texture,
					char *str);
void			assign_texture_or_color(t_game *cub, char *str, char *element);
char			*get_description(t_game *cub, char *str);
char			*is_element(char *str);

/*======= parse check =======*/
void			check_filename(t_game *cub, char **av);
void			check_empty_file(t_game *cub);
void			check_param(t_game *cub, int ac, char **av);
void			check_duplicate(t_game *cub, char *element, char *texture, \
				char *str);

/*======= Utils =======*/
unsigned int	index_to_word(char *str, int nb);
int				word_count(char *str);
void			is_map(t_game *cub, int j);
void			split_map(t_game *cub, int j);
bool			followed_line_breaks(char *str);

/*======= Error =======*/
void			quit(t_game *cub, char *str);
void			ft_destroy(t_game *cub);
void			free_elements(t_game *cub);
void			free_array(char **str);
void			print_err(char *str);

/*======= init game =======*/
void			init_game(t_game *cub);
void			init_background(t_game *cub);
void			init_textures(t_game *cub);
void			init_player(t_game	*cub);

/*======= keys =======*/
int				exit_game(t_game *cub);
int				keypress(int keycode, t_game *cub);
int				keyrelease(int keycode, t_game *cub);

/*======= moves =======*/
bool			is_colliding(t_game *cub, double x, double y);
void			move_forward_or_backward(t_game *cub, bool forward);
void			move_left_or_right(t_game *cub, bool left);
void			handle_move(t_game *cub);

/*======= raycast =======*/
void			get_delta_distance_y(t_game *cub, double ray_dir_y);
void			get_delta_distance_x(t_game *cub, double ray_dir_x);
void			dda(t_game *cub);
void			get_texture_index(t_game *cub);
void			ray_data(t_game *cub, double ray_angle);

/*======= render =======*/
void			draw_background(t_game *cub);
void			draw_walls(t_game *cub, int x, int begin, int end);
void			render(t_game *cub);

/*======= render_utils =======*/
int				convert_to_argb(char	*colors, t_game *cub);
void			my_mlx_pixel_put_color(t_texture *bground, int x, int y, \
				int color);
unsigned int	my_mlx_pixel_get_color(t_texture *wall, int x, int y);

#endif