/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:59:17 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/03/19 14:02:22 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	texture_ok(char *str)
{
	char	*line;
	int		fd;
	int		i;

	if (str)
	{
		i = ft_strlen(str);
		if (i - 5 < 0 || str[i - 5] == '/' || !(ft_strnstr((str + (i - 4)), \
			".xpm", 4)))
			return (false);
	}
	if (access(str, R_OK) == -1)
		return (false);
	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), false);
	close(fd);
	free(line);
	return (true);
}

bool	str_is_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool	commas_ok(char *str)
{
	int	i;
	int	commas;

	i = -1;
	commas = 0;
	while (str[++i])
	{
		if (str[i] == ',')
			commas++;
	}
	if (commas != 2)
		return (false);
	return (true);
}

bool	rgb_ok(char *str)
{
	char	**rgb;
	int		i;

	if (commas_ok(str) == false)
		return (false);
	rgb = ft_split(str, ',');
	i = -1;
	while (rgb[++i])
	{
		if (str_is_digit(rgb[i]) == false || !(ft_atoi(rgb[i]) <= 255
				&& ft_atoi(rgb[i]) >= 0))
			return (free_array(rgb), false);
	}
	if (i != 3)
		return (free_array(rgb), false);
	free_array(rgb);
	return (true);
}
