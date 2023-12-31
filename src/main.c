/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:11:48 by jhouyet           #+#    #+#             */
/*   Updated: 2023/12/20 11:44:59 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	check_argv(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		ft_error("Error\nFile need to be .ber\n\n");
	else
	{
		i = ft_strlen(argv[1]);
		if (!(i >= 4 && argv[1][i - 4] == '.' && \
		argv[1][i - 3] == 'b' && argv[1][i - 2] == 'e' && \
		argv[1][i - 1] == 'r'))
			ft_error("Error\nFile need to be .ber\n\n");
	}
}

int	main(int argc, char **argv)
{
	t_game		*game;

	check_argv(argc, argv);
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		ft_error("Error\nMalloc t_game\n\n");
	ft_check_map(argv[1], game);
	ft_init_game(game);
	mlx_key_hook(game->win, ft_key_hook, game);
	mlx_hook(game->win, 17, 0, ft_mlx_hook, game);
	mlx_loop(game->mlx);
}
