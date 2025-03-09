/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:29:48 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/03/09 16:50:15 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*int	init(char **av, t_game *cub)
{
	t_elements	*elements;

	elements = (t_elements *)ft_calloc(6, sizeof(t_elements));
	if(!elements)
		return(print_err("Memory allocation fail - t_elements"), 1);
	cub->elements = elements;
	cub->file_name = ft_strdup(av[1]);
	//init outras partes?
	return (0);
}*/

int init(char **av, t_game *cub)
{
    cub->player = (t_player *)ft_calloc(1, sizeof(t_player));
    if (!cub->player)
		return(print_err("Memory allocation fail - t_player"), 1);
    cub->ray = (t_ray *)ft_calloc(1, sizeof(t_ray));
    if (!cub->ray)
    	return(print_err("Memory allocation fail - t_ray"), 1);
    cub->render = (t_render *)ft_calloc(1, sizeof(t_render));
    if (!cub->render)
		return(print_err("Memory allocation fail - t_render"), 1);
	cub->bground = (t_texture *)ft_calloc(1, sizeof(t_texture));
	if (!cub->bground)
		return(print_err("Memory allocation fail - t_bground"), 1);
	cub->elements = (t_elements *)ft_calloc(6, sizeof(t_elements));
	if (!cub->elements)
		return(print_err("Memory allocation fail - t_elements"), 1);
	ft_bzero(cub->wall, sizeof(t_texture) * 4);
	ft_bzero(&cub->key, sizeof(t_key));
	cub->ceiling = -1;
	cub->floor = -1;
	cub->file_name = ft_strdup(av[1]);
	return(0);
}

void	print_elements(t_game *cub)
{
	int i;
	for (i = 0; i < 6; i++)
	{
		if (cub->elements[i].id)
			printf("Element %d ID: %s\n", i, cub->elements[i].id);
		else
			printf("Element %d ID: (null)\n", i);	
		if (cub->elements[i].info)
			printf("Element %d Info: %s\n", i, cub->elements[i].info);
		else
			printf("Element %d Info: (null)\n", i);
	}
}