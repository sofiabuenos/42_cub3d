/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:08:08 by sbueno-s          #+#    #+#             */
/*   Updated: 2025/03/25 16:06:50 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	character;
	int		i;
	int		rd;

	i = 0;
	rd = 1;
	character = 0;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(100000);
	while (rd > 0)
	{
		rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1);
		buffer[i++] = character;
		if (character == '\n')
			break ;
	}
	buffer[i] = '\0';
	if (rd == -1 || i == 0 || (!buffer[i - 1] && !rd))
		return (free(buffer), NULL);
	return (buffer);
}
