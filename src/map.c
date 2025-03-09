/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:29:51 by sheila            #+#    #+#             */
/*   Updated: 2025/03/09 14:31:40 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void print_map(t_game *game)
{
    int row = 0;

    printf("Mapa carregado:\n");
    while (game->map[row])
    {
        printf("%s\n", game->map[row]);
        row++;
    }

    printf("\nPosição do jogador: (X: %.2f, Y: %.2f, Direção: %c)\n", 
           game->player->pos.x, game->player->pos.y, game->player->pov);
}

void parse_map(char *line, t_game *game, int row)
{
    int col = 0;

    game->map[row] = strdup(line);
    if (!game->map[row])
    {
        perror("Erro ao copiar linha do mapa");
        exit(1);
    }

    while (line[col])
    {
        if (strchr("NSEW", line[col])) // Verifica se é um caractere válido
        {
            if (!game->player)  // Certifique-se de que player está alocado
            {
                fprintf(stderr, "Erro: Estrutura do jogador não foi inicializada\n");
                exit(1);
            }

            game->player->pos.x = col;
            game->player->pos.y = row;
            game->player->pov = line[col];
            game->map[row][col] = '0';  // Evita acessar memória não inicializada
        }
        col++;
    }
}

// Função principal para processar o arquivo .cub
void read_cub_file(char *filename, t_game *game)
{
    FILE *file = fopen(filename, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int row = 0;
    int map_size = 10;  // Alocação inicial

    if (!file)
    {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    // Aloca um número inicial de linhas e expande conforme necessário
    game->map = (char **)malloc(sizeof(char *) * map_size);
    if (!game->map)
    {
        perror("Erro ao alocar memória para o mapa");
        fclose(file);
        exit(1);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        line[strcspn(line, "\n")] = 0; // Remove a quebra de linha

        if (strspn(line, " 01NSEW") == strlen(line))
        {
            if (row >= map_size - 1)  // Se precisar expandir
            {
                map_size *= 2;
                game->map = realloc(game->map, sizeof(char *) * map_size);
                if (!game->map)
                {
                    perror("Erro ao realocar memória para o mapa");
                    fclose(file);
                    exit(1);
                }
            }

            parse_map(line, game, row);
            row++;
        }
    }

    game->map[row] = NULL; // Finaliza a matriz do mapa

    free(line);
    fclose(file);
    print_map(game);
}
