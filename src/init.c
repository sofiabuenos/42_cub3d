/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:29:48 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/03/19 14:38:20 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*void	init(t_game *cub)
{
	ft_bzero(cub, sizeof(t_game));
	cub->player = (t_player *)ft_calloc(1, sizeof(t_player));
	if (!cub->player)
		quit(cub, "Memory allocation fail - t_player");
	cub->bground = (t_texture *)ft_calloc(1, sizeof(t_texture));
	if (!cub->bground)
		quit(cub, "Memory allocation fail - t_bground");
	cub->render = (t_render *)ft_calloc(1, sizeof(t_render));
	if (!cub->render)
		quit(cub, "Memory allocation fail - t_render");
	cub->ray = (t_ray *)ft_calloc(1, sizeof(t_ray));
	if (!cub->ray)
		quit(cub, "Memory allocation fail - t_ray");
	ft_bzero(cub->wall, sizeof(t_texture) * 4);
	ft_bzero(&cub->key, sizeof(t_key));
	cub->ceiling = -1;
	cub->floor = -1;
}*/

void	print_elements(t_game *cub)
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
