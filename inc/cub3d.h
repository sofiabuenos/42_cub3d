/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:42:40 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/03/12 14:20:38 by sbueno-s         ###   ########.fr       */
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
# define ER_ELM "Invalid element format. Usage: ID info. eg: NO path_to_texture.xpm or F 0,255,255"

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


/*======= init =======*/
void			init(t_cub3d *cub);
void			print_elements(t_cub3d *cub);
/*======= parse =======*/
void			parse(t_cub3d *cub, int ac, char **av);
void			read_file(t_cub3d *cub, char *file);
void			check_empty_file(t_cub3d *cub);
void			parse_file(t_cub3d *cub);
/*======= read =======*/
char			*check_tabs(t_cub3d *cub, char *str);
char			*is_element(char *str);
bool			is_empty_line(char *str);
void			last_line(t_cub3d *cub, int i, int j);
void			get_info(t_cub3d *cub, char *str, char *element);
/*======= parse_elements =======*/
int				check_id(char *str, t_cub3d *cub, int count);
int				is_valid_id(char *temp);
int				check_info(char *str, t_cub3d *cub, int count);
int				check_RGB(char *str, t_cub3d *cub, int count);
int				check_path(char *str, t_cub3d *cub, int count);
/*======= parse utils =======*/
int				word_count(char *str);
int				there_are_commas(char *str);
unsigned int	index_to_word(char *str, int nb);
int				unique_ids(t_cub3d *cub);
/*======= Error =======*/
void			print_err(char *str);
void			ft_destroy(t_cub3d *cub);
void			quit(t_cub3d *cub, char *str);
void			free_array(char **str);

#endif