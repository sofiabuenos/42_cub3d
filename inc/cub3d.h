/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:42:40 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/02/26 16:22:23 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-mac/mlx.h"

# define NO "NO"
# define SO "SO"
# define WE "WE"
# define EA "EA"
# define F "F"
# define C "C"

typedef struct s_point
{
	unsigned int	x;
	unsigned int	y;
}					t_point;

// typedef struct s_directions
// {
// 	/*data*/
// } t_directions;

// typedef struct s_colors
// {
// 	/*data*/
// } t_colors;

typedef struct s_elements
{
	char	*id;
	char	*info;
	
} t_elements;

typedef struct s_cub3d
{
	char		*file_name;
	char		**map;
	t_elements	*elements;
}				t_cub3d;

/*======= parse =======*/
int				parse(t_cub3d *cub);
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
void			power_print_err(char *s1, char *s2);
void			ft_destroy(t_cub3d *cub);
void			quit(t_cub3d *cub);
void			free_array(char **str);
/*======= init =======*/
int				init(char **av, t_cub3d *cub);
void			print_elements(t_cub3d *cub);

#endif