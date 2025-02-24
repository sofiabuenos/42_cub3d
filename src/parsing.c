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

int	check_element(char *str, t_cub3d *cub, int count)
{

	if (ft_strlen(str) == 1 && str[0] == '\n')
		return (0);
	if (word_count(str) != 2)
	{
		power_print_err("Invalid line. Format: ID ./path_to_texture or ID color. Fix: ", str);
		quit(cub);
	}
	if (check_id(str, cub, count))
		return (1);
	//check_info()
	printf("%s\n", str);
	return (1);
}

int	parse_elements(char *file, t_cub3d *cub)
{
	char	*line;
	int		count;
	int		fd;

	count = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return(print_err("Unable to open file"), 1);
	line = get_next_line(fd);
	while (line)
	{
		count += check_element(line, cub, count);
		if (count == 6)
			break; // rever esse break. quando tenho algum repetido
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	if (!unique_ids(cub)) // melhorar essa verificação. verificar ainda na etapa linha a linha.
	{
		print_err("Missing or repeted elements");
		quit(cub);
	}
	return (0);
}

int	parse(t_cub3d *cub)
{
	parse_elements(cub->file_name, cub);
	print_elements(cub);
	//parse_map()
	return (0);
}
