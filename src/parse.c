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

// int	check_element(char *str, t_cub3d *cub, int count)
// {

// 	if (ft_strlen(str) == 1 && str[0] == '\n')
// 		return (0);
// 	if (word_count(str) != 2)
// 	{
// 		power_print_err("Invalid line. Format: ID ./path_to_texture or ID color. Fix: ", str);
// 		quit(cub);
// 	}
// 	check_id(str, cub, count);
// 	check_info(str, cub, count);
// 	printf("%s\n", str);
// 	return (1);
// }

// int	parse_elements(char *file, t_cub3d *cub)
// {
// 	char	*line;
// 	int		count;
// 	int		fd;

// 	count = 0;
// 	if ((fd = open(file, O_RDONLY)) == -1)
// 		return(print_err("Unable to open file"), 1);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		count += check_element(line, cub, count);
// 		if (count == 6)
// 			break; // rever esse break. quando tenho algum repetido
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	if (line)
// 		free(line);
// 	if (!unique_ids(cub)) // melhorar essa verificação. verificar ainda na etapa linha a linha.
// 	{
// 		print_err("Missing or repeted elements");
// 		quit(cub);
// 	}
// 	return (0);
// }

void	parse_file(t_cub3d *cub)
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
				printf("%s\n", temp);
				element = is_element(temp);
				if (element)
					get_info(cub, temp, element);
			}
			free(temp);
			j = i + 1;
		}
	}
	if (j < i)
		last_line(cub, i, j);
}

void	check_empty_file(t_cub3d *cub)
{
	if (!cub->file[0])
		quit(cub, ER_EMPTY);
}

void	read_file(t_cub3d *cub, char *file_name)
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

void	check_filename(t_cub3d *cub, char **av)
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

void	check_param(t_cub3d *cub, int ac, char **av)
{
	if (ac != 2)
		quit(cub, ER_PARAM);
	if (av[1][0] == '\0')
		quit(cub, ER_FILE);
}

void	parse(t_cub3d *cub, int ac, char **av)
{
	check_param(cub, ac, av);
	check_filename(cub, av);
	read_file(cub, cub->file_name);
	check_empty_file(cub);
	parse_file(cub);
	//parse_elements(cub->file_name, cub);
	//print_elements(cub);
	//parse_map()
}
