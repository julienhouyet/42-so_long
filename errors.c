/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:47:24 by jhouyet           #+#    #+#             */
/*   Updated: 2023/12/08 18:13:47 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *message)
{
	perror(message);
	system("leaks so_long");
	exit(EXIT_FAILURE);
}

void	ft_free_error(char *message, t_game *game)
{
	perror(message);
	ft_free(game);
	system("leaks so_long");
	exit(EXIT_FAILURE);
}

void	ft_free(t_game *game)
{
	int	i;

	i = 0;
	while (i <= game->map->rows)
	{
		free(game->map->content[i]);
		i++;
	}
	free(game->map->content);
	free(game->map);
	if (game->textures_created == 1)
	{
		mlx_destroy_image(game->mlx, game->textures->background);
		mlx_destroy_image(game->mlx, game->textures->exit);
		mlx_destroy_image(game->mlx, game->textures->item);
		mlx_destroy_image(game->mlx, game->textures->player);
		mlx_destroy_image(game->mlx, game->textures->wall);
		free(game->textures);
	}
	game->map->content = NULL;
	mlx_destroy_window(game->mlx, game->win);
}
