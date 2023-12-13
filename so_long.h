/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:01:40 by jhouyet           #+#    #+#             */
/*   Updated: 2023/12/13 09:10:02 by jhouyet          ###   ########.fr       */
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

typedef struct s_path
{
	char	**visited;
	int		nbr_items;
	int		nbr_exit;

}				t_path;

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
	t_path		*path;
	int			map_created;
	int			textures_created;
	int			mlx_init;
	int			win_init;
	int			nbr_move;
	int			nbr_items;
	int			player_pos_x;
	int			player_pos_y;
}				t_game;

void	ft_error(char *message);
void	ft_free_error(char *message, t_game *game);
void	ft_free_message(char *message, t_game *game);
void	ft_free(t_game *game);

void	ft_check_map(char *filename, t_game *game);
void	ft_check_max_size(int rows, int cols);
int		ft_check_rows_size(char *line, int rows, int cols, int i);
void	ft_save_map(char *filename, t_game *game, int i);

void	ft_map_wall(t_game *game);
void	ft_map_elem(t_game *game);
void	ft_map_count(t_game *game);
void	ft_map_player_pos(t_game *game);

void	ft_init_map_visited(t_game *game);
void	ft_free_map_visited(t_game *game);
void	ft_check_elem(t_game *game);
void	ft_explore_map(t_game *game, int x, int y);

void	ft_init_game(t_game *game);
void	ft_load_textures(t_game *game);
void	ft_draw_map(t_game *game);
void	ft_draw_elem(t_game *game);

int		ft_key_hook(int key, t_game *game);
int		ft_mlx_hook(t_game *game);

void	ft_move(t_game *game, int next_y, int next_x);
char	ft_next_pos(t_game *game, int next_y, int next_x);
void	ft_move_player(t_game *game, int next_y, int next_x);
void	ft_remove_player(t_game *game);

void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_right(t_game *game);
void	ft_move_left(t_game *game);
void	ft_map(t_game *game);

char	*ft_strcpy(char *dest, const char *src);

#endif