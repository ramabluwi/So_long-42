/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralbliwi <ralbliwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:05:06 by ralbliwi          #+#    #+#             */
/*   Updated: 2025/02/20 15:06:22 by ralbliwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <X11/keysym.h>
# include <mlx.h>

typedef struct s_player
{
	int			player_y;
	int			player_x;
}				t_player;

typedef struct s_image
{
	void		*wall;
	void		*floor;
	void		*collect;
	void		*exit;
	void		*player;
	int			height;
	int			width;
}				t_image;

typedef struct s_map
{
	char		**map;
	int			height;
	int			width;
	int			collectibles;
	int			exit_found;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			count_collect;
	int			move_count;
	t_player	*player;
	t_image		*image;
	t_map		*map;
}				t_game;

typedef struct s_flood_fill
{
	t_map		*original_map;
	int			*collectibles;
	char		**mapi;
}				t_flood_fill;

void			file_name(char *s);
t_map			*initialize_map(t_game *game);
t_game			*initialize_game(char **argv);
void			map_reader(char *map_name, t_game *game);
int				ft_open(char *argv, t_game *game);
int				count_lines(int fd);
void			free_2darr(char **array, int height);
void			clean(t_game *game);
void			free_init_map(t_game *game);
void			free_map(t_game *game);
void			free_imgs(t_game *game);
void			replacing_nline(char **temp);
void			init_player(t_game *game);
void			move_player(t_game *game, int pos_x, int pos_y);
void			close_game(t_game *game);
void			find_position(t_game *game);
t_image			*init_imgs(void *mlx, t_game *game);
void			design_game(int i, int j, t_game *game);
void			render_textures(t_game *game);
void			redesign_player(t_game *game, void *mlx, void *win);
void			free_extra(t_game *game);
void			collect_num(t_game *game);
void			init_win(t_game *game);
int				is_rectangular(t_game *game);
int				check_char(t_game *game);
int				check_ones(t_game *game);
int				check_counts(t_game *game);
void			map_check(t_game *game);
int				valid_path(t_game *game);
int				count_collect(t_game *game);
int				count_player(t_game *game);
int				count_exit(t_game *game);
char			**copy_map(char **original_map, int height);
t_flood_fill	*ft_fill(char **map, t_map *orig_map, int *collects);
int				flood_fill(t_flood_fill *fdata, int x, int y);
void			free_textures(t_game *game, t_image *image);
void			check_textures(t_game *game, t_image *image);
void			load_textures(void *mlx, t_game *game, t_image *images);

#endif