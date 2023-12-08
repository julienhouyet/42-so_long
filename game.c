/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:59:44 by jhouyet           #+#    #+#             */
/*   Updated: 2023/12/08 18:13:57 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_textures(t_game *game)
{
	int			width;
	int			height;

	game->textures = malloc(sizeof(t_textures));
	if (!game->textures)
		ft_error("Error\nMalloc game->textures");
	game->textures->background = \
	mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", \
	&width, &height);
	game->textures->wall = \
	mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", \
	&width, &height);
	game->textures->player = \
	mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", \
	&width, &height);
	game->textures->exit = \
	mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm", \
	&width, &height);
	game->textures->item = \
	mlx_xpm_file_to_image(game->mlx, "assets/collectible.xpm", \
	&width, &height);
}

void	ft_draw_elem(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map->rows)
	{
		x = -1;
		while (++x < game->map->cols - 1)
		{
			if (game->map->content[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, \
				game->textures->wall, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map->content[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, \
				game->textures->player, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map->content[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, \
				game->textures->exit, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map->content[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, \
				game->textures->item, x * TILE_SIZE, y * TILE_SIZE);
		}
	}
}

void	ft_draw_map(t_game *game)
{
	int	y;
	int	x;
	int	py;
	int	px;

	y = 0;
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->cols - 1)
		{
			py = y * TILE_SIZE;
			px = x * TILE_SIZE;
			mlx_put_image_to_window(game->mlx, game->win, \
			game->textures->background, px, py);
			x++;
		}
		y++;
	}
}

void	ft_init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_free_error("Error\nMLX init don't work", game);
	ft_load_textures(game);
	game->textures_created = 1;
	game->win = mlx_new_window(game->mlx, TILE_SIZE * (game->map->cols - 1), \
	TILE_SIZE * game->map->rows, "Pokemon Red");
	if (!game->win)
		ft_free_error("Error\nProblem with window", game);
	ft_draw_map(game);
	ft_draw_elem(game);
	//ft_free_error("Error\nProblem with window", game);
}
