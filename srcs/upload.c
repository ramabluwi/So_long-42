/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralbliwi <ralbliwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:38:54 by ralbliwi          #+#    #+#             */
/*   Updated: 2025/02/20 18:20:20 by ralbliwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(void *mlx, t_game *game, t_image *images)
{
	images->wall = mlx_xpm_file_to_image(mlx, "./textures/wall.xpm",
			&images->width, &images->height);
	if (!images->wall)
		check_textures(game, images);
	images->floor = mlx_xpm_file_to_image(mlx, "./textures/floor.xpm",
			&images->width, &images->height);
	if (!images->floor)
		check_textures(game, images);
	images->exit = mlx_xpm_file_to_image(mlx, "./textures/exit.xpm",
			&images->width, &images->height);
	if (!images->exit)
		check_textures(game, images);
	images->player = mlx_xpm_file_to_image(mlx, "./textures/sonic.xpm",
			&images->width, &images->height);
	if (!images->player)
		check_textures(game, images);
	images->collect = mlx_xpm_file_to_image(mlx, "./textures/ring.xpm",
			&images->width, &images->height);
	if (!images->collect)
		check_textures(game, images);
}

t_image	*init_imgs(void *mlx, t_game *game)
{
	t_image	*images;

	images = malloc(sizeof(t_image));
	if (!images)
		clean(game);
	images->height = 64;
	images->width = 64;
	images->wall = NULL;
	images->collect = NULL;
	images->exit = NULL;
	images->player = NULL;
	images->floor = NULL;
	load_textures(mlx, game, images);
	return (images);
}

void	design_game(int i, int j, t_game *game)
{
	void	*image;

	if (game->map->map[i][j] == '1')
		image = game->image->wall;
	else if (game->map->map[i][j] == '0')
		image = game->image->floor;
	else if (game->map->map[i][j] == 'E')
		image = game->image->exit;
	else if (game->map->map[i][j] == 'P')
		image = game->image->floor;
	else if (game->map->map[i][j] == 'C')
		image = game->image->collect;
	else
		return ;
	mlx_put_image_to_window(game->mlx, game->win, image, j * 64, i * 64);
}

void	render_textures(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			design_game(i, j, game);
			j++;
		}
		i++;
	}
}

void	redesign_player(t_game *game, void *mlx, void *win)
{
	render_textures(game);
	mlx_put_image_to_window(mlx, win, game->image->player,
		game->player->player_x * 64, game->player->player_y * 64);
}
