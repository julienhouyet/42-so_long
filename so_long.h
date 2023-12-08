/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:01:40 by jhouyet           #+#    #+#             */
/*   Updated: 2023/12/08 17:41:16 by jhouyet          ###   ########.fr       */
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
# define MAX_ROWS 45
# define MAX_COLS 80

typedef struct s_map
{
	char	**content;
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

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_textures	*textures;
	int			map_created;
	int			textures_created;

}				t_game;

void	ft_error(char *message);
void	ft_free_error(char *message, t_game *game);
void	ft_free(t_game *game);

void	ft_check_map(char *filename, t_game *game);
void	ft_check_max_size(int rows, int cols);
int		ft_check_rows_size(char *line, int rows, int cols, int i);
void	ft_save_map(char *filename, t_game *game, int i);

void	ft_map_wall(t_game *game);
void	ft_map_elem(t_game *game);
void	ft_map_count(t_game *game);

void	ft_init_game(t_game *game);
void	ft_load_textures(t_game *game);
void	ft_draw_map(t_game *game);
void	ft_draw_elem(t_game *game);

char	*ft_strcpy(char *dest, const char *src);

#endif