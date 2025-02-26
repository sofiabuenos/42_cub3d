/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:54:23 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/02/26 12:28:17 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_err(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	//ft_putstr_fd("\n", 2);
}

void	power_print_err(char *s1, char *s2)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(s2, 2);
	//ft_putstr_fd("\n", 2);
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
	int	i;
	if (cub->elements)
	{
		i = -1;
		while (++i < 6)
		{
			if (cub->elements[i].info)
				free(cub->elements[i].info);
		}
		free(cub->elements);
		cub->elements = NULL;
	}
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

void	quit(t_cub3d *cub)
{
	ft_destroy(cub);
	exit(EXIT_FAILURE);
}