/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:47:24 by jhouyet           #+#    #+#             */
/*   Updated: 2023/12/06 18:33:24 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

void	ft_free_error(char *message, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	map->map = NULL;
	system("leaks so_long");
	perror(message);
	exit(EXIT_FAILURE);
}
