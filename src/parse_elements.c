/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:59:17 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/02/26 16:29:45 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_path(char *str, t_cub3d *cub, int count)
{
	char	*temp;
	int		start;

	start = index_to_word(str, 2);
	temp = ft_substr(str, start, (ft_strlen(str) - start -1));
	if (access(temp, R_OK) == -1) // READ OK pq ainda n tenho texturas. verificar se precisa X_OK
		return (power_print_err("Check path to texture: ", str), 1);
	cub->elements[count].info = ft_strdup(temp);
	if (temp)
		free(temp);
	return (0);
}

int	check_RGB(char *str, t_cub3d *cub, int count)
{
	char	*temp;
	char	**rgb;
	int		start;
	int		i;

	start = index_to_word(str, 2);
	temp = ft_substr(str, start, (ft_strlen(str) - start -1)); //tirar o '\n'
	if (!there_are_commas(temp))
		return (1);
	i = 0;
	rgb = ft_split(temp, ',');
	i = -1;
	while(rgb[++i])
		if (!(ft_atoi(rgb[i]) <= 255 && ft_atoi(rgb[i]) >= 0))
			return (power_print_err("R,G,B colors range is [0,255]: 0, 255, 255.: ", temp), 1);
	if (i != 3)
	return (power_print_err("R,G,B colors must have 3 numbers separated by commas: ", temp), 1);
	cub->elements[count].info = ft_strdup(temp);
	if (temp)
		free(temp);
	free_array(rgb);
	return (0);
}

int	check_info(char *str, t_cub3d *cub, int count)
{
	if (!ft_strncmp(cub->elements[count].id, F, 2) || !ft_strncmp(cub->elements[count].id, C, 2))
	{
		if (check_RGB(str, cub, count))
			quit(cub);
	}
	else
	{
		if (check_path(str, cub, count))
			quit(cub);
	}
	return (0);
}

int	is_valid_id(char *temp)
{
	if (ft_strncmp(temp, NO, 3) == 0 || ft_strncmp(temp, SO, 3) == 0 ||
		ft_strncmp(temp, WE, 3) == 0 || ft_strncmp(temp, EA, 3) == 0 ||
		ft_strncmp(temp, F, 2) == 0 || ft_strncmp(temp, C, 2) == 0)
		return (1);
	return (0);
}

int	check_id(char *str, t_cub3d *cub, int count)
{
	char			*temp;
	unsigned int	i;
	unsigned int	j;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	j = i;
	while (!ft_isspace(str[j]))
		j++;
	temp = ft_substr(str, i, j - i);
	if (!is_valid_id(temp))
	{
		power_print_err("Invalid ID: ", temp);
		free(temp);
		quit(cub);
	}
	cub->elements[count].id = ft_strdup(temp);
	free(temp);
	return (0);
}

