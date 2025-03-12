/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:40:27 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/03/12 13:24:40 by sbueno-s         ###   ########.fr       */
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

char	*check_tabs(t_cub3d *cub, char *str)
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
	return(new_str);
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
	//printf("%s\n", cub->file);
}

void	check_empty_file(t_cub3d *cub)
{
	if (!cub->file[0])
		quit(cub, ER_EMPTY);
}

bool	is_empty_line(char *str)
{
	if (ft_strlen(str) == 1 && str[0] == '\n')
		return (true);
	else
		return (false);
}

void	last_line(t_cub3d *cub, int i, int j)
{
	char	*temp;

	temp = ft_substr(cub->file, j, (i - j + 1));
	if (!temp)
		quit(cub, "Memory allocation issue - parse_file");
	if (!is_empty_line(temp))
	{
		printf("%s\n", temp);
	}
	free(temp);
}

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

void	get_description(t_cub3d *cub, char *str, char *info)
{
	int	i;
	int	len;
	int	j;

	len = ft_strlen(str);
	if (word_count(str) != 2)
		quit(cub, ER_ELM);
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
			temp = ft_substr(cub->file, j, (i - j + 1));
			if (!temp)
				quit(cub, "Memory allocation issue - parse_file");
			if (!is_empty_line(temp))
			{
				printf("%s", temp);
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


// void	split_map(t_cub3d *cub)
// {
// 	int	count;
// 	int	i;

// 	count = 0;
// 	i = -1;
// 	while (cub->line_file[++i])
// 	{
// 		if (cub->line_file[i] == '\n')
// 			count++;
// 	}
// 	cub->file_cpy = (char *)malloc(sizeof(char *) * (count + 1));
// 	if (!cub->file_cpy)
// 		quit(cub, ER_ALLOC, " - split_map");
	
// 	// cub->file_cpy = ft_split(cub->line_file, '\n');
// 	// i = -1;
// 	// while (cub->file_cpy[++i])
// 	// 	printf("%s\n", cub->file_cpy[i]);
// }
