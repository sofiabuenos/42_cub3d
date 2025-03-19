/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:34:29 by sbueno-s          #+#    #+#             */
/*   Updated: 2025/03/19 15:49:14 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	followed_line_breaks(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n' && str[i + 1] && str[i + 1] == '\n')
			return (true);
	}
	return (false);
}

void	split_map(t_game *cub, int j)
{
	if (followed_line_breaks(cub->file + j))
		quit(cub, ER_EMPTY_LINE);
	cub->map = ft_split(cub->file + j, '\n');
}

void	is_map(t_game *cub, int j)
{
	if (!cub->no_texture || !cub->so_texture \
		|| !cub->we_texture || !cub->ea_texture \
		|| !cub->f_color || !cub->c_color)
		quit(cub, ER_INCOMPLETE);
	split_map(cub, j);
}

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
			in_word = 0;
		str++;
	}
	return (words);
}

unsigned int	index_to_word(char *str, int nb)
{
	unsigned int	i;
	int				word;

	word = 0;
	i = 0;
	while (word < nb && str[i])
	{
		if (!ft_isspace(str[i]))
		{
			word++;
			if (word == nb)
				break ;
			while (!ft_isspace(str[i]) && str[i])
				i++;
		}
		i++;
	}
	return (i);
}
