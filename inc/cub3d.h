/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:42:40 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/03/17 09:14:13 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-mac/mlx.h"

# define NO "NO "
# define SO "SO "
# define WE "WE "
# define EA "EA "
# define F "F "
# define C "C "

# define ER_PARAM "Invalid argument. Usage: ./cub3D path_to_file.cub"
# define ER_FILE "Invalid file. The file must exist and have a .cub extension. Usage: ./cub3D path_to_file.cub"
# define ER_OPEN "Unable to open file"
# define ER_EMPTY "Invalid file. The .cub file is empty"
# define ER_ELMENT "Invalid element format. Usage: ID info. eg: NO path_to_texture.xpm or F 0,255,255"
# define ER_INCOMPLETE "Game setting incomplete or invalid ID"
# define ER_EMPTY_LINE "Invalid map. The map must not contain empty lines"
# define ER_MAPGEN "A valid map is required"
# define ER_RGB "Invalid RGB format. Colors must be three numbers separated by commas, each ranging from 0 to 255. Example: 0,255,255"
# define ER_TEXTURE "Invalid path. NO, SO, WE, and EA must be followed by a valid .xpm file path."
typedef struct s_point
{
	unsigned int	x;
	unsigned int	y;
}					t_point;


// typedef struct s_elements
// {
// 	char	*id;
// 	char	*info;
	
// } t_elements;

typedef struct s_cub3d
{
	char	*file_name;
	char	*file;
	char	**map;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*f_color;
	char	*c_color;
	int		fd;
}			t_cub3d;


/*====== init ======*/
void			init(t_cub3d *cub);
void			print_elements(t_cub3d *cub);
/*====== parse ======*/
void			parse(t_cub3d *cub, int ac, char **av);
void			check_param(t_cub3d *cub, int ac, char **av);
void			check_filename(t_cub3d *cub, char **av);
void			read_file(t_cub3d *cub, char *file);
void			check_empty_file(t_cub3d *cub);
void			parse_file(t_cub3d *cub);
void			parse_elements(t_cub3d *cub);
/*==== read_utils ====*/
void			insert_spaces(char *str, char *new_str);
int				have_tabs(char *str);
char			*check_tabs(t_cub3d *cub, char *str);
bool			is_empty_line(char *str);
void			last_line(t_cub3d *cub, int i, int j);
/*=== parse_elements ===*/
bool			RGB_ok(char *str);
bool			commas_ok(char *str);
bool			str_is_digit(char *str);
bool			texture_ok(char *str);
/*=== parse_map ===*/
void			parse_map(t_cub3d *cub);
/*======= parse utils =======*/
char			*is_element(char *str);
void			get_info(t_cub3d *cub, char *str, char *element);
void			check_duplicate(t_cub3d *cub, char *element, char *texture);
void			assign_texture_or_color(t_cub3d *cub, char *str, char *element);
char			*get_description(t_cub3d *cub, char *str);
char			*is_element(char *str);
/*======= Utils =======*/
void			is_map(t_cub3d *cub, int j);
unsigned int	index_to_word(char *str, int nb);
int				word_count(char *str);
void			is_map(t_cub3d *cub, int j);
bool			followed_line_breaks(char *str);
void			split_map(t_cub3d *cub, int j);
/*======= Error =======*/
void			print_err(char *str);
void			ft_destroy(t_cub3d *cub);
void			quit(t_cub3d *cub, char *str);
void			free_elements(t_cub3d *cub);
void			free_array(char **str);

#endif