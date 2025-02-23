/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralbliwi <ralbliwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:10:15 by ralbliwi          #+#    #+#             */
/*   Updated: 2025/02/19 20:13:38 by ralbliwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean(t_game *game)
{
	if (game->image)
	{
		free_imgs(game);
	}
	if (game->map)
	{
		free_map(game);
	}
	if (game->player)
	{
		free(game->player);
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
	exit(0);
}

void	free_init_map(t_game *game)
{
	if (game)
	{
		free(game->map);
		if (game->map)
		{
			free_map(game);
		}
		free(game);
	}
	exit(1);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map->map)
	{
		while (game->map->map[i])
		{
			free(game->map->map[i]);
			i++;
		}
		free(game->map->map);
		free(game->map);
	}
}

void	free_2darr(char **array, int height)
{
	int	i;

	i = 0;
	if (!*array)
	{
		return ;
	}
	while (i < height)
	{
		if (array[i])
			free(array[i]);
		i++;
	}
	free(array);
}

void	free_imgs(t_game *game)
{
	if (game->image)
	{
		if (game->image->wall)
			mlx_destroy_image(game->mlx, game->image->wall);
		if (game->image->floor)
			mlx_destroy_image(game->mlx, game->image->floor);
		if (game->image->exit)
			mlx_destroy_image(game->mlx, game->image->exit);
		if (game->image->player)
			mlx_destroy_image(game->mlx, game->image->player);
		if (game->image->collect)
			mlx_destroy_image(game->mlx, game->image->collect);
	}
	free(game->image);
	game->image = NULL;
}
