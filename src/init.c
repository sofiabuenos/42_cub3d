/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:29:48 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/03/12 06:31:43 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_cub3d *cub)
{
	ft_bzero(cub, sizeof(t_cub3d));
	//init outras partes?
}

void	print_elements(t_cub3d *cub)
{
	if (cub->no_texture)
		printf("NO texture: %s\n", cub->no_texture);
	if (cub->so_texture)
		printf("SO texture: %s\n", cub->so_texture);
	if (cub->we_texture)
		printf("WE texture: %s\n", cub->we_texture);
	if (cub->ea_texture)
		printf("EA texture: %s\n", cub->ea_texture);
	if (cub->f_color)
		printf("F color: %s\n", cub->f_color);
	if (cub->c_color)
		printf("C color: %s\n", cub->c_color);
}