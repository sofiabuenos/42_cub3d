/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:42:40 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/02/20 15:19:54 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-mac/mlx.h"

typedef struct s_point
{
	unsigned int	x;
	unsigned int	y;
}				t_point;

typedef struct s_cub3d
{
	/* data */
}	t_cub3d;

/*===== parse =====*/
int		parse(int ac, char **av);
/*===== Error =====*/
void	print_err(char *str);

#endif