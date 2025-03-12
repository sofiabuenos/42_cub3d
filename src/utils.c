/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:34:29 by sbueno-s          #+#    #+#             */
/*   Updated: 2025/03/12 14:54:48 by sbueno-s         ###   ########.fr       */
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
