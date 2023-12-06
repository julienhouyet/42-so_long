/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:46:39 by jhouyet           #+#    #+#             */
/*   Updated: 2023/12/06 18:21:39 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_wall(t_map *map)
{
	int	i;
	int	j;

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

void	ft_map_count(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->nbr_player = 0;
	map->nbr_items = 0;
	map->nbr_exit = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
				map->nbr_player++;
			if (map->map[i][j] == 'E')
				map->nbr_exit++;
			if (map->map[i][j] == 'C')
				map->nbr_items++;
			j++;
		}
		i++;
	}
	if (map->nbr_player != 1 || map->nbr_exit != 1 || map->nbr_items < 1)
		ft_free_error("Error\nBad element", map);
}

void	ft_map_elem(t_map *map)
{
	ft_map_wall(map);
	ft_map_count(map);
}
