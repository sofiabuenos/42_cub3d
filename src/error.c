/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:54:23 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/03/24 18:56:09 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_err(char *str)
{
	if (*str)
	{
		ft_putstr_fd("Error\n", 2);
		ft_printf("%s\n", str);
	}
}

void	free_array(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_elements(t_game *cub)
{
	if (cub->c_color)
		free(cub->c_color);
	if (cub->f_color)
		free(cub->f_color);
	if (cub->no_texture)
		free(cub->no_texture);
	if (cub->so_texture)
		free(cub->so_texture);
	if (cub->we_texture)
		free(cub->we_texture);
	if (cub->ea_texture)
		free(cub->ea_texture);
}

void	ft_destroy(t_game *cub)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (cub->wall[i].img)
			mlx_destroy_image(cub->mlx, cub->wall[i].img);
	}
	if (cub->bground->img)
		mlx_destroy_image(cub->mlx, cub->bground->img);
	if (cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	if (cub->mlx)
		mlx_destroy_display(cub->mlx);
}

void	quit(t_game *cub, char *str)
{
	print_err(str);
	if (cub)
	{
		if (cub->file_name)
			free(cub->file_name);
		if (cub->file)
			free(cub->file);
		free_elements(cub);
		if (cub->map)
			free_array(cub->map);
		ft_destroy(cub);
		if (cub->player)
			free(cub->player);
		if (cub->bground)
			free(cub->bground);
		if (cub->render)
			free(cub->render);
		if (cub->ray)
			free(cub->ray);
		free(cub->mlx);
	}
	exit(EXIT_FAILURE);
}
