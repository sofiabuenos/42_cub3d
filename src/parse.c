/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:13:39 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/02/20 15:17:09 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_elements(t_game *cub)
{
	if (RGB_ok(cub->f_color) == false || RGB_ok(cub->c_color) == false)
		quit(cub, ER_RGB);
	if (texture_ok(cub->no_texture) == false || texture_ok(cub->so_texture) == false ||
		texture_ok(cub->we_texture) == false || texture_ok(cub->ea_texture) == false)
		quit(cub, ER_TEXTURE);
}

void	parse_file(t_game *cub)
{
	char	*temp;
	char	*element;
	int		j;
	int		i;

	j = 0;
	i = -1;
	while (cub->file[++i])
	{
		if (cub->file[i] == '\n')
		{
			temp = ft_substr(cub->file, j, (i - j));
			if (!temp)
				quit(cub, "Memory allocation issue - parse_file");
			if (!is_empty_line(temp))
			{
				element = is_element(temp);
				if (element)
					get_info(cub, temp, element);
				else 
				{
					free(temp);
					is_map(cub, j);
					break;
				}
			}
			free(temp);
			j = i + 1;
		}
	}
	// if (j < i)
	// 	last_line(cub, i, j);
}

void	check_empty_file(t_game *cub)
{
	if (!cub->file[0])
		quit(cub, ER_EMPTY);
}

void	read_file(t_game *cub, char *file_name)
{
	char	*line;
	char	*file;
	char	*temp;

	if ((cub->fd = open(file_name, O_RDONLY)) == -1)
		quit(cub, ER_OPEN);
	file = ft_strdup("");
	while (1)
	{
		line = get_next_line(cub->fd);
		if (!line)
			break;
		line = check_tabs(cub, line);
		temp = file;
		file = ft_strjoin(temp, line);
		free(line);
		free (temp);
	}
	cub->file = ft_strdup(file);
	free(file);
	close(cub->fd);
}

void	check_filename(t_game *cub, char **av)
{
	int		i;
	if (av[1])
	{
		i = ft_strlen(av[1]);
		if (i - 5 < 0 || av[1][i - 5] == '/' || !(ft_strnstr((av[1] + (i - 4)), ".cub", 4)))
			quit(cub, ER_FILE);
	}
	cub->file_name = ft_strdup(av[1]);
}

void	check_param(t_game *cub, int ac, char **av)
{
	if (ac != 2)
		quit(cub, ER_PARAM);
	if (av[1][0] == '\0')
		quit(cub, ER_FILE);
}

void	parse(t_game *cub, int ac, char **av)
{
	check_param(cub, ac, av);
	check_filename(cub, av);
	read_file(cub, cub->file_name);
	check_empty_file(cub);
	parse_file(cub);
	parse_elements(cub);
	parse_map(cub);
	//print_elements(cub);
}
