/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:44:49 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/03/12 14:35:04 by sbueno-s         ###   ########.fr       */
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

void	get_description(t_cub3d *cub, char *str, char *info)
{
	int	i;
	int	len;
	int	j;

	len = ft_strlen(str);
	if (word_count(str) != 2)
	{
		printf("%d\n", word_count(str));
		quit(cub, ER_ELM);
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
}

void	assign_texture_or_color(t_cub3d *cub, char *str, char *element)
{
	if (!ft_strncmp(element, NO, 3))
		get_description(cub, str, cub->no_texture);
	else if (!ft_strncmp(element, SO, 3))
		get_description(cub, str, cub->so_texture);
	else if (!ft_strncmp(element, WE, 3))
		get_description(cub, str, cub->we_texture);
	else if (!ft_strncmp(element, EA, 3))
		get_description(cub, str, cub->ea_texture);
	else if (!ft_strncmp(element, F, 2))
		get_description(cub, str, cub->f_color);
	else if (!ft_strncmp(element, C, 2))
		get_description(cub, str, cub->c_color);
}

void	check_duplicate(t_cub3d *cub, char *element, char *texture)
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

void	get_info(t_cub3d *cub, char *str, char *element)
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

// int	there_are_commas(char *str)
// {
// 	int	comma;
// 	int	i;

// 	comma = 0;
// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == ',')
// 			comma++;
// 		i++;
// 	}
// 	if (comma != 2)
// 		return(power_print_err("Fix RGB format. Must have 3 numbers separated by commas. eg.: 0, 255, 255.: ", str), 0);
// 	return (1);
// }


