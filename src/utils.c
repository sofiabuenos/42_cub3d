/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:34:29 by sbueno-s          #+#    #+#             */
/*   Updated: 2025/03/12 16:21:32 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	word_count(char *str)
{
	int	words;
	int	in_word;	
	words = 0;
	in_word = 0;
	while (*str)
	{
		if (!ft_isspace(*str) && !in_word)
		{
			in_word = 1;
			words++;
		}
		else if (ft_isspace(*str))
		{
			in_word = 0;
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
