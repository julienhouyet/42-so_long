/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:17:01 by jhouyet           #+#    #+#             */
/*   Updated: 2023/12/12 15:54:06 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int key, t_game *game)
{
	if (key == 53)
		ft_free_message("End Game\n", game);
	if (key == 13)
		ft_move(game, -1, 0);
	if (key == 1)
		ft_move(game, 1, 0);
	if (key == 2)
		ft_move(game, 0, 1);
	if (key == 0)
		ft_move(game, 0, -1);
	return (0);
}

int ft_mlx_hook(t_game *game)
{
		ft_free_message("Window Closed\n", game);
    return (0);
}