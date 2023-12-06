/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:11:48 by jhouyet           #+#    #+#             */
/*   Updated: 2023/12/06 17:45:49 by jhouyet          ###   ########.fr       */
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

void	ft_map_wall(t_map *map)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (i < map->cols - 1)
	{
		if (map->map[0][i] != '1')
			ft_free_error("Error\nNo wall header", map);
		if (map->map[map->rows - 1][i] != '1')
			ft_free_error("Error\nNo wall footer", map);
		i++;
	}
	while (j < map->rows)
	{
		if (map->map[j][0] != '1')
			ft_free_error("Error\nNo wall left", map);
		if (map->map[j][map->cols - 2] != '1')
			ft_free_error("Error\nNo wall right", map);
		j++;
	}
}

int	main(int argc, char **argv)
{
	t_map	map;

	ft_check_argv(argc, argv);
	ft_check_map_file(argv[1]);
	ft_read_map(argv[1], &map);
	ft_map_wall(&map);
	ft_printf("Tout est ok !");
}
