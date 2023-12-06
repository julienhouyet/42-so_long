/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:01:02 by jhouyet           #+#    #+#             */
/*   Updated: 2023/12/06 16:40:34 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nMap not found");
	close(fd);
}

int	ft_check_rows_size(char *line, int rows, int cols, int i)
{
	if (i == rows - 1)
	{
		if ((line[cols - 1] == '\n') || (line[cols - 1] == '\0' \
		&& line[cols - 2] == '1'))
			return (1);
		else
			return (0);
	}
	else
	{
		if (line[cols - 1] == '\n')
			return (1);
		else
			return (0);
	}
}

void	ft_save_map(char *filename, t_map *map, int rows, int cols)
{
	int		fd;
	char	*line;
	int		i;

	i = -1;
	fd = open(filename, O_RDONLY);
	map->map = (char **)malloc(rows * sizeof(char *));
	if (map->map == NULL)
		ft_free_error("Error\nAllocating memory for map->map", map);
	while (++i < rows)
	{
		line = get_next_line(fd);
		if (ft_check_rows_size(line, rows, cols, i))
		{
			map->map[i] = (char *)malloc((cols) * sizeof(char));
			if (map->map[i] == NULL)
				ft_free_error("Error\nAllocating memory for map->map[i]", map);
			else
				map->map[i] = ft_strdup(line);
		}
		else
			ft_free_error("Error\nMap size not allowed", map);
		free(line);
	}
	close(fd);
}

void	ft_read_map(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		rows;

	rows = 0;
	fd = open(filename, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (rows == 0)
			map->cols = ft_strlen(line);
		rows++;
		free(line);
	}
	map->rows = rows;
	close(fd);
	ft_save_map(filename, map, map->rows, map->cols);
}
