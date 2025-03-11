/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:19:36 by shrodrig          #+#    #+#             */
/*   Updated: 2025/03/10 11:34:03 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *cub)
{
	cub->mlx = mlx_init();
	if(!cub->mlx)
		error_msg(cub, "Fail to initialize MLX");
	//cub->screen_h = (int)HEIGHT;
	//cub->screen_w = (int)WIDTH;
	cub->win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3d");
	if(!cub->win)
		error_msg(cub, "Fail to initialize MLX");
	init_textures(cub);
	init_background(cub);
	init_player(cub);
}

void	get_texture_and_color(t_game *cub)
{
	int		i;

	i = -1;
	cub->path = (char **)malloc(sizeof(char *) * 4);
	while (++i < 6)
	{
		if (!ft_strcmp(cub->elements[i].id, "NO"))
			cub->path[0] = cub->elements[i].info;
		else if (!ft_strcmp(cub->elements[i].id, "SO"))
			cub->path[1] = cub->elements[i].info;
		else if (!ft_strcmp(cub->elements[i].id, "EA"))
			cub->path[2] = cub->elements[i].info;
		else if (!ft_strcmp(cub->elements[i].id, "WE"))
			cub->path[3] = cub->elements[i].info;
		else if (!ft_strcmp(cub->elements[i].id, "C"))
			cub->ceiling = convert_to_rgb(cub->elements[i].info, cub);
		else if (!ft_strcmp(cub->elements[i].id, "F"))
			cub->floor = convert_to_rgb(cub->elements[i].info, cub);
	}
	if (!cub->path[0] || !cub->path[1] || !cub->path[2] || !cub->path[3]
		|| !cub->ceiling || !cub->floor)
		error_msg(cub, "Fail to get any of elements");
}

void	init_textures(t_game *cub)
{
	int	i;
	int	t_size;
	
	i = -1;
	t_size = (int)SIZE;
	get_texture_and_color(cub);
	while (++i < 4)
	{
		if (!cub->path[i])
    		error_msg(cub, "Texture path is NULL");
		cub->wall[i].img = mlx_xpm_file_to_image(cub->mlx, cub->path[i], &t_size, &t_size);
		if (!cub->wall[i].img)
			error_msg(cub, "Fail to load wall texture");
		cub->wall[i].addr = mlx_get_data_addr(cub->wall[i].img, &cub->wall[i].bpp, &cub->wall[i].size_line, &cub->wall[i].endian);
		if (!cub->wall[i].addr)
			error_msg(cub, "Fail to get wall texture adress");
	}
}

void	init_background(t_game *cub)
{
	cub->bground->img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	if (!cub->bground->img)
		error_msg(cub, "Fail to initialize background");
	cub->bground->addr = mlx_get_data_addr(cub->bground->img, &cub->bground->bpp, &cub->bground->size_line,
			&cub->bground->endian);
	if (!cub->bground->addr)
		error_msg(cub, "Fail to get background adress");
}

void	init_player(t_game	*cub)
{
	cub->player->pos.x += 0.5;
	cub->player->pos.y += 0.5;

	if (cub->player->pov == 'N')
		cub->player->angle = 3 * PI / 2;
	else if (cub->player->pov == 'S')
		cub->player->angle = PI / 2;
	else if (cub->player->pov == 'E')
		cub->player->angle = 0;
	else if (cub->player->pov == 'W')
		cub->player->angle = PI;
	//cub->player->dir.x = cos(cub->player->angle) * MOVE_SPEED;
	//cub->player->dir.y = sin(cub->player->angle) * MOVE_SPEED;
	cub->player->dir.x = cos(cub->player->angle);
	cub->player->dir.y = sin(cub->player->angle);
	cub->fov = 60 * (PI / 180); //plano da camera em radianos;
}



/*__DEVICE__ float ceil(float __x)

Função: ceilf
Descrição: Retorna o menor número inteiro maior ou igual a x. Essa função arredonda o número para cima.
Exemplo: Se x = 2.3, a função retorna 3.0.

__DEVICE__ float cos(float __x)

Função: cosf
Descrição: Retorna o cosseno de x (onde x é em radianos). O cosseno é uma função trigonométrica que calcula a projeção do ponto no círculo unitário na direção horizontal.
Exemplo: Se x = π/3 (60 graus), a função retorna 0.5.

__DEVICE__ float fabs(float __x) __NOEXCEPT

    Função: fabsf
    Descrição: Retorna o valor absoluto de x. Ou seja, se x for negativo, ele retorna o valor positivo de x, e se já for positivo, retorna o mesmo valor.
    Exemplo: Se x = -3.5, a função retorna 3.5.

__DEVICE__ float floor(float __x)

    Função: floorf
    Descrição: Retorna o maior número inteiro menor ou igual a x. Essa função arredonda o número para baixo.
    Exemplo: Se x = 2.7, a função retorna 2.0.
*/


