/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:23:34 by shrodrig          #+#    #+#             */
/*   Updated: 2025/03/19 15:44:59 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	convert_to_argb(char *colors, t_game *cub)
{
	char	**str;
	int		r;
	int		g;
	int		b;

	str = ft_split(colors, ',');
	if (!str || !str[0] || !str[1] || !str[2])
		quit(cub, "Fail to convert colors for ARGB");
	r = ft_atoi(str[0]);
	g = ft_atoi(str[1]);
	b = ft_atoi(str[2]);
	free_array(str);
	return (0 << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put_color(t_texture *bground, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel = bground->addr + (y * bground->size_line + x * bground->bpp / 8);
		*(unsigned int *)pixel = color;
	}
}

unsigned int	my_mlx_pixel_get_color(t_texture *wall, int x, int y)
{
	char	*pixel;

	pixel = wall->addr + (y * wall->size_line + x * (wall->bpp / 8));
	return (*(unsigned int *)pixel);
}
