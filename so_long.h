/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:01:40 by jhouyet           #+#    #+#             */
/*   Updated: 2023/12/07 10:07:31 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

# define TILE_SIZE 32

typedef struct s_game
{
	void	*mlx;
	void	*win;

}				t_game;

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
	int		nbr_player;
	int		nbr_items;
	int		nbr_exit;

}				t_map;

typedef struct s_textures
{
	void	*background;
	void	*wall;
	void	*player;
	void	*exit;
	void	*item;
}				t_textures;

void		ft_check_map_file(char *filename);
int			ft_check_rows_size(char *line, int rows, int cols, int i);
void		ft_save_map(char *filename, t_map *map, int rows, int cols);
void		ft_read_map(char *filename, t_map *map);

void		ft_map_elem(t_map *map);
void		ft_map_wall(t_map *map);
void		ft_map_count(t_map *map);

t_textures	ft_load_textures(t_game *game);
void		ft_init_game(t_game *game, t_map *map);
void		ft_init_window(t_game *game, t_map *map);
void		ft_draw_elem(t_game *game, t_map *map, t_textures *textures);
void		ft_draw_map(t_game *game, t_map *map, t_textures *textures);

void		ft_error(char *message);
void		ft_free_error(char *message, t_map *map);
void		ft_free(t_map *map);

#endif