/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:44:50 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/03/09 20:02:06 by shrodrig         ###   ########.fr       */
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

int	gameloop(t_game *cub)
{
	draw_background(cub);
	render(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->bground->img, 0, 0);
	handle_move(cub);
	return(0);
}

void	load_game(t_game cub)
{
	init_mlx(&cub);
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
