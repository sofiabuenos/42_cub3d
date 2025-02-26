/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:44:49 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/02/26 16:04:48 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	word_count(char *str)
{
	int	words;

	words = 0;
	while (*str)
	{
		if (!ft_isspace(*str))
		{
			words++;
			str++;
			while (!ft_isspace(*str))
				str++;
		}
		str++;
	}
	return (words);
}

unsigned int	index_to_word(char *str, int nb)
{
	int	word;
	unsigned int	i;

	word = 0;
	i = 0;
	while (word < nb && str[i])
	{
		if (!ft_isspace(str[i]))
		{
			word++;
			if (word == nb)
				break;
			while (!ft_isspace(str[i]) && str[i])
				i++;
		}
		i++;
	}
	return (i);
}

int	there_are_commas(char *str)
{
	int	comma;
	int	i;

	comma = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		return(power_print_err("Fix RGB format. Must have 3 numbers separated by commas. eg.: 0, 255, 255.: ", str), 0);
	return (1);
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
