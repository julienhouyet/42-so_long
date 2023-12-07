/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:59:44 by jhouyet           #+#    #+#             */
/*   Updated: 2023/12/07 09:57:50 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_textures	ft_load_textures(t_game *game)
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

void	ft_draw_elem(t_game *game, t_map *map, t_textures *textures)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->rows)
	{
		x = -1;
		while (++x < map->cols - 1)
		{
			if (map->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, \
				textures->wall, x * TILE_SIZE, y * TILE_SIZE);
			else if (map->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, \
				textures->player, x * TILE_SIZE, y * TILE_SIZE);
			else if (map->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, \
				textures->exit, x * TILE_SIZE, y * TILE_SIZE);
			else if (map->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, \
				textures->item, x * TILE_SIZE, y * TILE_SIZE);
		}
	}
}

void	ft_draw_map(t_game *game, t_map *map, t_textures *textures)
{
	int	y;
	int	x;
	int	py;
	int	px;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols - 1)
		{
			py = y * TILE_SIZE;
			px = x * TILE_SIZE;
			mlx_put_image_to_window(game->mlx, game->win, \
			textures->background, px, py);
			x++;
		}
		y++;
	}
	ft_draw_elem(game, map, textures);
}
