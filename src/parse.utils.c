/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:44:49 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/03/17 14:58:16 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*is_element(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (!ft_strncmp(str + i, NO, 3))
		return (NO);
	else if (!ft_strncmp(str + i, SO, 3))
		return(SO);
	else if (!ft_strncmp(str + i, WE, 3))
		return (WE);
	else if (!ft_strncmp(str + i, EA, 3))
		return (EA);
	else if (!ft_strncmp(str + i, F, 2))
		return (F);
	else if (!ft_strncmp(str + i, C, 2))
		return (C);
	else
		return (NULL);
}

char	*get_description(t_game *cub, char *str)
{
	int		i;
	int		len;
	int		j;
	char	*info;

	len = ft_strlen(str);
	if (word_count(str) != 2)
	{
		printf("%d\n", word_count(str));
		quit(cub, ER_ELMENT);
	}
	i = index_to_word(str, 2);
	info = (char *)calloc((len - i + 1), sizeof(char));
	if (!info)
		quit(cub, "Memory allocation faliure - get_description");
	j = 0;
	while(str[i])
	{
		if(ft_isspace(str[i]))
			i++;
		info[j++] = str[i++];
	}
	info[j] = '\0';
	return (info);
}

void	assign_texture_or_color(t_game *cub, char *str, char *element)
{
	if (!ft_strncmp(element, NO, 3))
		cub->no_texture = get_description(cub, str);
	else if (!ft_strncmp(element, SO, 3))
		cub->so_texture = get_description(cub, str);
	else if (!ft_strncmp(element, WE, 3))
		cub->we_texture = get_description(cub, str);
	else if (!ft_strncmp(element, EA, 3))
		cub->ea_texture = get_description(cub, str);
	else if (!ft_strncmp(element, F, 2))
		cub->f_color = get_description(cub, str);
	else if (!ft_strncmp(element, C, 2))
		cub->c_color = get_description(cub, str);
}

void	check_duplicate(t_game *cub, char *element, char *texture)
{
	if (texture)
	{
		if (!ft_strncmp(element, NO, 3))
			quit(cub, "Duplicate NO texture");
		else if (!ft_strncmp(element, SO, 3))
			quit(cub, "Duplicate SO texture");
		else if (!ft_strncmp(element, WE, 3))
			quit(cub, "Duplicate WE texture");
		else if (!ft_strncmp(element, EA, 3))
			quit(cub, "Duplicate EA texture");
		else if (!ft_strncmp(element, F, 2))
			quit(cub, "Duplicate F color");
		else if (!ft_strncmp(element, C, 2))
			quit(cub, "Duplicate C color");
	}
}

void	get_info(t_game *cub, char *str, char *element)
{
	if (!ft_strncmp(element, NO, 3))
		check_duplicate(cub, element, cub->no_texture);
	else if (!ft_strncmp(element, SO, 3))
		check_duplicate(cub, element, cub->so_texture);
	else if (!ft_strncmp(element, WE, 3))
		check_duplicate(cub, element, cub->we_texture);
	else if (!ft_strncmp(element, EA, 3))
		check_duplicate(cub, element, cub->ea_texture);
	else if (!ft_strncmp(element, F, 2))
		check_duplicate(cub, element, cub->f_color);
	else if (!ft_strncmp(element, C, 2))
		check_duplicate(cub, element, cub->c_color);
	assign_texture_or_color(cub, str, element);
}
