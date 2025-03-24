/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:40:27 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/03/24 18:54:27 by sbueno-s         ###   ########.fr       */
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
