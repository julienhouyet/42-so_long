/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:46:39 by jhouyet           #+#    #+#             */
/*   Updated: 2023/12/12 17:37:36 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map->cols - 1)
	{
		if (game->map->content[0][i] != '1')
			ft_free_error("Error\nNo wall header", game);
		if (game->map->content[game->map->rows - 1][i] != '1')
			ft_free_error("Error\nNo wall footer", game);
		i++;
	}
	while (j < game->map->rows)
	{
		if (game->map->content[j][0] != '1')
			ft_free_error("Error\nNo wall left", game);
		if (game->map->content[j][game->map->cols - 2] != '1')
			ft_free_error("Error\nNo wall right", game);
		j++;
	}
}

void	ft_map_count(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->map->nbr_player = 0;
	game->map->nbr_items = 0;
	game->map->nbr_exit = 0;
	while (i < game->map->rows)
	{
		j = 0;
		while (j < game->map->cols)
		{
			if (game->map->content[i][j] == 'P')
				game->map->nbr_player++;
			if (game->map->content[i][j] == 'E')
				game->map->nbr_exit++;
			if (game->map->content[i][j] == 'C')
				game->map->nbr_items++;
			j++;
		}
		i++;
	}
	if (game->map->nbr_player != 1 || game->map->nbr_exit != 1 \
	|| game->map->nbr_items < 1)
		ft_free_error("Error\nBad element", game);
}

void	ft_map_player_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->nbr_move = 0;
	while (i < game->map->rows)
	{
		j = 0;
		while (j < game->map->cols)
		{
			if (game->map->content[i][j] == 'P')
			{
				game->player_pos_x = j;
				game->player_pos_y = i;
			}
			j++;
		}
		i++;
	}
}

void	ft_map_elem(t_game *game)
{
	ft_map_wall(game);
	ft_map_count(game);
	ft_map_player_pos(game);
}
