/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:11:48 by jhouyet           #+#    #+#             */
/*   Updated: 2023/12/06 10:47:30 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void	check_argv(int argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		perror("Error\nUtilisation: ./so_long.c <nom_du_fichier_ber>\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		i = ft_strlen(argv[1]);
		if (!(i >= 4 && argv[1][i - 4] == '.' && \
		argv[1][i - 3] == 'b' && argv[1][i - 2] == 'e' && \
		argv[1][i - 1] == 'r'))
		{
			perror("Error\nL'extension du fichier de la map doit être .ber\n");
			exit(EXIT_FAILURE);
		}
	}
}

void    check_map(char *filename)
{
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Error\nLa carte n'est pas lisible.");
        exit(EXIT_FAILURE);
    }
    close(fd);
}

void	save_map(char *filename, t_map *map, int rows, int cols)
{
	int		fd;
    char	*line;
	int 	i;

	i = -1;
	fd = open(filename, O_RDONLY);
	map->map = (char **)malloc(rows * sizeof(char *));
	if (map->map == NULL)
		ft_error("Error\nAllocating memory for map->map");
    while (++i < rows)
    {
		line = get_next_line(fd);
		map->map[i] = (char *)malloc((cols + 1) * sizeof(char));
		if (map->map[i] == NULL)
			ft_error("Error\nAllocating memory for map->map[i]");
		else
		{
			map->map[i] = ft_strdup(line);
			free(line);
		}
	}
	close(fd);
}

void    read_map(char *filename, t_map *map)
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
            break;
		if (rows == 0)
			map->cols = ft_strlen(line);
		rows++;
        free(line);
    }
	map->rows = rows;
	close(fd);
	save_map(filename, map, map->rows, map->cols);
}

int	main(int argc, char **argv)
{
	t_map map;

	check_argv(argc, argv);
	check_map(argv[1]);
	read_map(argv[1], &map);
	ft_printf("Rows : %d\n", map.rows);
	ft_printf("Cols : %d\n", map.cols);
}
