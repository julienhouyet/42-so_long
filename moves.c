/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:13:42 by jhouyet           #+#    #+#             */
/*   Updated: 2023/12/13 11:15:35 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move(t_game *game, int next_y, int next_x)
{
	char	c;

	c = ft_next_pos(game, next_y, next_x);
	if (c == '0' || c == 'C')
	{
		ft_remove_player(game);
		ft_move_player(game, next_y, next_x);
		if (c == 'C')
			game->nbr_items++;
		game->nbr_move++;
		printf("Move : %d\n", game->nbr_move);
	}
	if (c == 'E')
	{
		if (game->nbr_items == game->map->nbr_items)
		{
			ft_remove_player(game);
			ft_move_player(game, next_y, next_x);
			ft_free_message("FIN !", game);
		}
	}
}

char	ft_next_pos(t_game *game, int next_y, int next_x)
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

void	ft_remove_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->textures->background, \
	game->player_pos_x * TILE_SIZE, game->player_pos_y * TILE_SIZE);
	game->map->content[game->player_pos_y][game->player_pos_x] = '0';
}

void	ft_move_player(t_game *game, int next_y, int next_x)
{
	game->player_pos_y += next_y;
	game->player_pos_x += next_x;
	game->map->content[game->player_pos_y][game->player_pos_x] = 'P';
	mlx_put_image_to_window(game->mlx, game->win, game->textures->player, \
	game->player_pos_x * TILE_SIZE, game->player_pos_y * TILE_SIZE);
}
