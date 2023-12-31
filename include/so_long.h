/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:01:40 by jhouyet           #+#    #+#             */
/*   Updated: 2023/12/20 11:46:48 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include "libft/include/libft.h"
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
	int			exit_pos_x;
	int			exit_pos_y;
}				t_game;

void	ft_check_map(char *filename, t_game *game);
void	ft_check_map_elem(t_game *game);
void	ft_check_map_path(t_game *game, int y, int x);

void	ft_init_game(t_game *game);

int		ft_key_hook(int key, t_game *game);
int		ft_mlx_hook(t_game *game);

void	ft_move(t_game *game, int next_y, int next_x);

void	ft_error(char *message);
void	ft_free_error(char *message, t_game *game);
void	ft_free_message(char *message, t_game *game);
void	ft_free(t_game *game);
void	ft_free_map(char *message, t_game *game, int i, int fd);

char	*ft_strcpy(char *dest, const char *src);

#endif