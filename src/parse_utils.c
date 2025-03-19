/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:44:49 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/03/19 15:22:04 by shrodrig         ###   ########.fr       */
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
		return (SO);
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

char	*get_color_description(t_game *cub, char *str)
{
	char	**temp;
	int		i;
	int		j;
	char	*info;

	temp = ft_split(str, ',');
	if ((!temp || !temp[0] || !temp[1] || !temp[2] || temp[3] != NULL))
	{
		return (free(str), free_array(temp), quit(cub, ER_ELMENT), NULL);
	}
	info = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!info)
		return (free(str), free_array(temp), quit(cub, "Memory allocation \
		 failure - get_description"), NULL);
	j = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[++i])
	{
		if (!ft_isspace(str[i]))
			info[j++] = str[i];
	}
	info[j] = '\0';
	free_array(temp);
	return (info);
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
		free(str);
		quit(cub, ER_ELMENT);
	}
	i = index_to_word(str, 2);
	info = (char *)calloc((len - i + 1), sizeof(char));
	if (!info)
		quit(cub, "Memory allocation failure - get_description");
	j = 0;
	while (str[i] && !ft_isspace(str[i]))
		info[j++] = str[i++];
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
		cub->f_color = get_color_description(cub, str);
	else if (!ft_strncmp(element, C, 2))
		cub->c_color = get_color_description(cub, str);
}

void	get_info(t_game *cub, char *str, char *element)
{
	if (!ft_strncmp(element, NO, 3))
		check_duplicate(cub, element, cub->no_texture, str);
	else if (!ft_strncmp(element, SO, 3))
		check_duplicate(cub, element, cub->so_texture, str);
	else if (!ft_strncmp(element, WE, 3))
		check_duplicate(cub, element, cub->we_texture, str);
	else if (!ft_strncmp(element, EA, 3))
		check_duplicate(cub, element, cub->ea_texture, str);
	else if (!ft_strncmp(element, F, 2))
		check_duplicate(cub, element, cub->f_color, str);
	else if (!ft_strncmp(element, C, 2))
		check_duplicate(cub, element, cub->c_color, str);
	assign_texture_or_color(cub, str, element);
}
