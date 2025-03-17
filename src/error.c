/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:54:23 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/03/17 09:13:46 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_err(char *str)
{
	ft_putstr_fd("Error\n", 2);
	printf("%s\n", str);
}

void	free_array(char **str)
{
	int i;

	if (!str)
		return;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_elements(t_cub3d *cub)
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


void	ft_destroy(t_cub3d *cub)
{
	if(cub)
	{
		if (cub->file_name)
			free(cub->file_name);
		free_elements(cub);
	}
}

void	quit(t_cub3d *cub, char *str)
{
	print_err(str);
	ft_destroy(cub);
	exit(EXIT_FAILURE);
}