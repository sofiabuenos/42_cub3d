/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:40:27 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/03/19 15:25:24 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	insert_spaces(char *str, char *new_str)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '\t')
		{
			new_str[j++] = ' ';
			new_str[j++] = ' ';
			new_str[j++] = ' ';
			new_str[j++] = ' ';
		}
		else
			new_str[j++] = str[i];
	}
	new_str[j] = '\0';
	free(str);
}

int	have_tabs(char *str)
{
	int	tab;
	int	i;

	tab = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\t')
			tab++;
	}
	return (tab);
}

char	*check_tabs(t_game *cub, char *str)
{
	int		spaces;
	int		tabs;
	int		len;
	char	*new_str;

	spaces = 0;
	tabs = have_tabs(str);
	if (tabs)
		spaces = 4 * tabs;
	len = ft_strlen(str);
	new_str = (char *)ft_calloc((len + spaces + 1), sizeof(char));
	if (!new_str)
		quit(cub, "Memory allocation issue - check_tabs");
	insert_spaces(str, new_str);
	return (new_str);
}

bool	is_empty_line(char *str)
{
	if (ft_strlen(str) == 0)
		return (true);
	else
		return (false);
}

void	last_line(t_game *cub, int i, int j)
{
	char	*temp;

	temp = ft_substr(cub->file, j, (i - j));
	if (!temp)
		quit(cub, "Memory allocation issue - parse_file");
	if (!is_empty_line(temp))
	{
		printf("\n\n%s\n", temp);
	}
	free(temp);
}
