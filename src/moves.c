/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:13:42 by jhouyet           #+#    #+#             */
/*   Updated: 2023/12/20 12:33:13 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

char	next_pos(t_game *game, int next_y, int next_x)
{
	int	temp_y;
	int	temp_x;

	temp_y = game->player_pos_y + next_y;
	temp_x = game->player_pos_x + next_x;
	if (game->map->content[temp_y][temp_x] == '0')
		return ('0');
	if (game->map->content[temp_y][temp_x] == 'C')
		return ('C');
	if (game->map->content[temp_y][temp_x] == 'E')
		return ('E');
	return ('1');
}

void	remove_player(t_game *game)
{
	if (game->exit_pos_y == game->player_pos_y && \
	game->exit_pos_x == game->player_pos_x)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->textures->exit, \
		game->player_pos_x * TILE_SIZE, game->player_pos_y * TILE_SIZE);
		game->map->content[game->player_pos_y][game->player_pos_x] = 'E';
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->textures->background, \
		game->player_pos_x * TILE_SIZE, game->player_pos_y * TILE_SIZE);
		game->map->content[game->player_pos_y][game->player_pos_x] = '0';
	}
}

void	move_player(t_game *game, int next_y, int next_x)
{
	game->player_pos_y += next_y;
	game->player_pos_x += next_x;
	game->map->content[game->player_pos_y][game->player_pos_x] = 'P';
	mlx_put_image_to_window(game->mlx, game->win, game->textures->player, \
	game->player_pos_x * TILE_SIZE, game->player_pos_y * TILE_SIZE);
}

void	ft_move(t_game *game, int next_y, int next_x)
{
	char	c;

	c = next_pos(game, next_y, next_x);
	if (c == '0' || c == 'C')
	{
		remove_player(game);
		move_player(game, next_y, next_x);
		if (c == 'C')
			game->nbr_items++;
		game->nbr_move++;
		ft_printf("Move : %d\n", game->nbr_move);
	}
	if (c == 'E')
	{
		remove_player(game);
		move_player(game, next_y, next_x);
		game->nbr_move++;
		ft_printf("Move : %d\n", game->nbr_move);
		if (game->nbr_items == game->map->nbr_items)
		{
			ft_free_message("FIN !\n\n", game);
		}
	}
}
