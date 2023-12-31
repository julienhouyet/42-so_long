/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:01:02 by jhouyet           #+#    #+#             */
/*   Updated: 2023/12/20 11:45:01 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	check_max_size(int rows, int cols)
{
	if (rows > MAX_ROWS || cols > MAX_COLS)
		ft_error("Error\nMap size too high");
}

int	check_rows_size(char *line, int rows, int cols, int i)
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

void	save_maps_rows(t_game *game, char *line, int i, int fd)
{
	if (check_rows_size(line, game->map->rows, game->map->cols, i))
	{
		game->map->content[i] = ft_calloc(game->map->cols + 1, \
		sizeof(char));
		if (!game->map->content[i])
			return (ft_free_map("Error\nMalloc for map->content[i]\n\n", \
			game, i, fd), free(line));
		else
			ft_strcpy(game->map->content[i], line);
	}
	else
		return (ft_free_map("Error\nMap S\n\n", game, i, fd), free(line));
	free(line);
}

void	save_map(char *filename, t_game *game, int i)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	game->map->content = ft_calloc(game->map->rows, sizeof(char *));
	if (!game->map->content)
		ft_free_error("Error\nMalloc for game->map->content\n\n", game);
	while (++i < game->map->rows)
	{
		line = get_next_line(fd);
		if (!line)
			return (ft_free_map("Error\nMalloc for game->map->content\n\n", \
			game, i, fd), free(line));
		save_maps_rows(game, line, i, fd);
	}
	close(fd);
	ft_check_map_elem(game);
}

void	ft_check_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	int		rows;

	rows = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nMap not open\n\n");
	game->map = ft_calloc(1, sizeof(t_map));
	if (!game->map)
		ft_error("Error\nMalloc fr game->map\n\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (rows == 0)
			game->map->cols = ft_strlen(line);
		rows++;
		free(line);
	}
	game->map->rows = rows;
	close(fd);
	check_max_size(game->map->rows, game->map->cols);
	save_map(filename, game, -1);
}
