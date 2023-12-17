/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 07:32:29 by jhouyet           #+#    #+#             */
/*   Updated: 2023/12/17 06:26:32 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_map_visited(t_game *game)
{
	game->path = ft_calloc(1, sizeof(t_path));
	game->path->nbr_items = game->map->nbr_items;
	game->path->nbr_exit = game->map->nbr_exit;
	game->path->visited = ft_calloc(1, game->map->rows * sizeof(int *));
}

void	ft_free_map_visited(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->rows)
	{
		free(game->path->visited[i]);
		i++;
	}
	free(game->path->visited);
	free(game->path);
	game->path = NULL;
}

void	ft_explore_map(t_game *game, int y, int x)
{
	if (y < 0 || y >= game->map->rows || x < 0 || x >= game->map->cols \
	|| game->map->content[y][x] == '1' || game->path->visited[y][x])
		return ;
	game->path->visited[y][x] = 1;
	if (game->map->content[y][x] == 'C')
		game->path->nbr_items--;
	if (game->map->content[y][x] == 'E')
		game->path->nbr_exit--;
	ft_explore_map(game, y, x + 1);
	ft_explore_map(game, y, x - 1);
	ft_explore_map(game, y + 1, x);
	ft_explore_map(game, y - 1, x);
}

void	ft_check_elem(t_game *game)
{
	int	y;
	int	x;

	ft_init_map_visited(game);
	y = -1;
	while (++y < game->map->rows)
		game->path->visited[y] = ft_calloc(game->map->cols, sizeof(int *));
	y = -1;
	while (++y < game->map->rows)
	{
		x = -1;
		while (++x < game->map->cols)
		{
			if (game->map->content[y][x] == 'P')
			{
				ft_explore_map(game, y, x);
				if (game->path->nbr_items != 0 || game->path->nbr_exit != 0)
					ft_free_error("Error\nNo valid Path\n\n", game);
			}
		}
	}
	ft_free_map_visited(game);
}
