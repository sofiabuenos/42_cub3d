/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:44:49 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/02/24 16:21:12 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	word_count(char *str)
{
	int	words;

	words = 0;
	while (*str)
	{
		if (!isspace(*str))
		{
			words++;
			str++;
			while (!isspace(*str))
				str++;
		}
		str++;
	}
	return (words);
}

int	is_valid_id(char *temp)
{
	if (ft_strncmp(temp, NO, 3) == 0 || ft_strncmp(temp, SO, 3) == 0 ||
		ft_strncmp(temp, WE, 3) == 0 || ft_strncmp(temp, EA, 3) == 0 ||
		ft_strncmp(temp, F, 2) == 0 || ft_strncmp(temp, C, 2) == 0)
		return (1);
	return (0);
}

int	unique_ids(t_cub3d *cub)
{
	int		i;
	int		flags[6] = {0, 0, 0, 0, 0, 0};

	i = 0;
	while (i < 6)
	{
		if (ft_strncmp(cub->elements[i].id, NO, 3) == 0)
			 flags[0]++;
		else if (ft_strncmp(cub->elements[i].id, SO, 3) == 0)
			flags[1]++;
		else if (ft_strncmp(cub->elements[i].id, WE, 3) == 0)
			flags[2]++;
		else if (ft_strncmp(cub->elements[i].id, EA, 3) == 0)
			flags[3]++;
		else if (ft_strncmp(cub->elements[i].id, F, 2) == 0)
			flags[4]++;
		else if (ft_strncmp(cub->elements[i].id, C, 2) == 0)
			flags[5]++;
		i++;
	}
	i = 0;
	while (i < 6)
	{
		if (flags[i] != 1)
			return (0); // Retorna 0 se algum ID não estiver presente ou estiver repetido
		i++;
	}
	return (1); // Retorna 1 se todos os IDs estiverem presentes e sem repetição
}
