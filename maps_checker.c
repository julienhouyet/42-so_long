/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:01:02 by jhouyet           #+#    #+#             */
/*   Updated: 2023/12/15 16:57:19 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_max_size(int rows, int cols)
{
	if (rows > MAX_ROWS || cols > MAX_COLS)
		ft_error("Error\nMap size too high");
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

void	ft_save_map(char *filename, t_game *game, int i)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	game->map->content = (char **)malloc(game->map->rows * sizeof(char *));
	if (!game->map->content)
		ft_free_error("Error\nMalloc for game->map->content\n\n", game);
	while (++i < game->map->rows)
	{
		line = get_next_line(fd);
		if (ft_check_rows_size(line, game->map->rows, game->map->cols, i))
		{
			game->map->content[i] = (char *)malloc((game->map->cols + 1) \
			* sizeof(char));
			if (!game->map->content[i])
				ft_free_error("Error\nMalloc for map->content[i]\n\n", game);
			else
				ft_strcpy(game->map->content[i], line);
		}
		else
			return (ft_free_map("Error\nMap S\n\n", game, i, fd), free(line));
		free(line);
	}
	close(fd);
	ft_map_elem(game);
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
	game->map = malloc(sizeof(t_map));
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
	ft_check_max_size(game->map->rows, game->map->cols);
	ft_save_map(filename, game, -1);
}
