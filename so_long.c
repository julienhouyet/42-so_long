/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:11:48 by jhouyet           #+#    #+#             */
/*   Updated: 2023/12/07 10:56:05 by jhouyet          ###   ########.fr       */
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

int	ft_close(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit (EXIT_SUCCESS);
	return (0);
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
	textures = ft_load_textures(game.mlx);
	ft_init_window(&game, &map);
	ft_draw_map(&game, &map, &textures);
	mlx_hook(game.win, 2, 1L<<0, ft_close, &game);
	mlx_loop(game.mlx);
	ft_free(&map);
}
