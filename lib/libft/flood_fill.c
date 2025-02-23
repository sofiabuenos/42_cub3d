/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:07:39 by sheila            #+#    #+#             */
/*   Updated: 2025/02/10 17:26:18 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fill(t_fill_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->size.x || y >= data->size.y
		|| data->tab[y][x] != data->c)
		return ;
	data->tab[y][x] = 'F';
	fill(data, x + 1, y);
	fill(data, x - 1, y);
	fill(data, x, y + 1);
	fill(data, x, y - 1);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	t_fill_data	data;

	data.tab = tab;
	data.size = size;
	data.c = tab[begin.y][begin.x];
	if (data.c != 'F')
		fill(&data, begin.x, begin.y);
}

char	**make_area(char **zone, t_point size)
{
	char	**new;
	int		i;
	int		j;

	new = malloc(sizeof(char *) * size.y);
	i = -1;
	while (++i < size.y)
	{
		new[i] = malloc(size.x + 1);
		j = -1;
		while (++j < size.x)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}
	return (new);
}

/*int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}*/
