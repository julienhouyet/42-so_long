/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:11:48 by jhouyet           #+#    #+#             */
/*   Updated: 2023/12/06 19:30:58 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_argv(int argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		perror("Error\nUsage: ./so_long.c <name_of_file_ber>\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		i = ft_strlen(argv[1]);
		if (!(i >= 4 && argv[1][i - 4] == '.' && \
		argv[1][i - 3] == 'b' && argv[1][i - 2] == 'e' && \
		argv[1][i - 1] == 'r'))
		{
			perror("Error\nFile need to be .ber\n");
			exit(EXIT_FAILURE);
		}
	}
}

t_textures	load_textures(t_game *game)
{
	t_textures	textures;
	int			width;
	int			height;

	textures.background = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", \
	&width, &height);
	textures.wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", \
	&width, &height);
	textures.player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", \
	&width, &height);
	textures.exit = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm", \
	&width, &height);
	textures.item = mlx_xpm_file_to_image(game->mlx, "assets/collectible.xpm", \
	&width, &height);
	return (textures);
}

void	ft_init_game(t_game *game, t_map *map)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_free_error("Error\nMLX init don't work", map);
}

void	ft_init_window(t_game *game, t_map *map)
{
	game->win = mlx_new_window(game->mlx, TILE_SIZE * (map->cols - 1), \
	TILE_SIZE * map->rows, "Pokemon Red");
	if (!game->win)
		ft_free_error("Error\nProblem with window", map);
}

void draw_map(t_game *game, t_map *map, t_textures *textures) {

	int x, y;

	for (int y = 0; y < map->rows; y++) {
		for (int x = 0; x < map->cols - 1; x++) {
			int px = x * TILE_SIZE;
			int py = y * TILE_SIZE;
			mlx_put_image_to_window(game->mlx, game->win, textures->background, px, py);
		}
	}

	for (y = 0; y < map->rows; y++) {
		for (x = 0; x < map->cols - 1; x++) {

            int px = x * TILE_SIZE;
            int py = y * TILE_SIZE;
            if (map->map[y][x] == '1') {
                mlx_put_image_to_window(game->mlx, game->win, textures->wall, px, py);
            } else if (map->map[y][x] == 'P') {
                mlx_put_image_to_window(game->mlx, game->win, textures->player, px, py);
            } else if (map->map[y][x] == 'E') {
                mlx_put_image_to_window(game->mlx, game->win, textures->exit, px, py);
            } else if (map->map[y][x] == 'C') {
                mlx_put_image_to_window(game->mlx, game->win, textures->item, px, py);
            }
        }
    }
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_game		game;
	t_textures	textures;

	ft_check_argv(argc, argv);
	ft_check_map_file(argv[1]);
	ft_read_map(argv[1], &map);
	ft_map_elem(&map);
	ft_init_game(&game, &map);
	textures = load_textures(game.mlx);
	ft_init_window(&game, &map);
	draw_map(&game, &map, &textures);
	mlx_loop(game.mlx);
	ft_printf("Tout est ok !");
}
