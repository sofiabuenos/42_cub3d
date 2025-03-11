/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:44:50 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/03/10 17:36:04 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parameters(int ac)
{
	if (ac != 2)
		return (1);
	return (0);
}

int	extension(char **av)
{
	int		i;
	if (av[1])
	{
		i = ft_strlen(av[1]);
		if (i - 5 < 0 || av[1][i - 5] == '/' || !(ft_strnstr((av[1] + (i - 4)), ".cub", 4)))
			return (1);
	}
	return (0);
}
void	debug_player_position(t_game *cub)
{
	int x = (int)cub->player->pos.x;
	int y = (int)cub->player->pos.y;

	printf("Posição do Player: X=%d, Y=%d\n", x, y);
	printf("Valor do mapa na posição: %c\n", cub->map[y][x]);

	if (cub->map[y][x] == '1')
		printf("\n\n ******ERRO! O jogador está dentro de uma parede! ******* \n\n");
}
int	gameloop(t_game *cub)
{
	draw_background(cub);
	//debug_player_position(cub);
	handle_move(cub);
	render(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->bground->img, 0, 0);
	return(0);
}

void	load_game(t_game cub)
{
	init_game(&cub);
	mlx_hook(cub.win, 2, 1L << 0, keypress, &cub);
	mlx_hook(cub.win, 3, 1L << 1, keyrelease, &cub);
	mlx_hook(cub.win, 17, 0, quit_game, &cub);
	mlx_loop_hook(cub.mlx, gameloop , &cub);
	mlx_loop(cub.mlx);
}

int	main(int ac, char **av)
{
	t_game	cub;
	ft_bzero(&cub, sizeof(t_game));
	if (parameters(ac))
		return (print_err("Check parameters. Should use ./cub3D path_to_map.cub"), 1);
	if (extension(av))
		return (print_err("Check extension. The file should have a name and a .cub extension"), 1);
	if (init(av, &cub))
		quit(&cub);
	if (parse(&cub))
		quit(&cub);
	load_game(cub);
	return (0);
}
