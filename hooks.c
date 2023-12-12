/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:17:01 by jhouyet           #+#    #+#             */
/*   Updated: 2023/12/11 06:11:08 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int key, t_game *game)
{
	if (key == 53)
	{
		ft_printf("End Game\n");
		ft_free(game);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int ft_mlx_hook(t_game *game)
{
    ft_printf("Window closed\n");
    ft_free(game);
    exit(EXIT_SUCCESS);
    return (0);
}