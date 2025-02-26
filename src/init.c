/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:29:48 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/02/26 11:03:19 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init(char **av, t_cub3d *cub)
{
	t_elements	*elements;

	elements = (t_elements *)ft_calloc(6, sizeof(t_elements));
	if(!elements)
		return(print_err("Memory allocation fail - t_elements"), 1);
	cub->elements = elements;
	cub->file_name = ft_strdup(av[1]);
	//init outras partes?
	return (0);
}

void	print_elements(t_cub3d *cub)
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