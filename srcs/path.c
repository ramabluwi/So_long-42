/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralbliwi <ralbliwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:10:49 by ralbliwi          #+#    #+#             */
/*   Updated: 2025/02/20 18:19:46 by ralbliwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check(t_game *game)
{
	if (!is_rectangular(game))
	{
		ft_putstr_fd("Error\nNot rectangular shape\n", 2);
		clean(game);
	}
	if (!check_char(game) || !check_counts(game))
	{
		ft_putstr_fd("Error\nInvalid character or No exit\n", 2);
		clean(game);
	}
	if (!check_ones(game))
	{
		ft_putstr_fd("Error\nMAP is not closed by Walls\n", 2);
		clean(game);
	}
	if (!valid_path(game))
	{
		ft_putstr_fd("Error\nInvalid path\n", 2);
		clean(game);
	}
}

int	valid_path(t_game *game)
{
	int				x;
	int				y;
	char			**copy;
	int				collects;
	t_flood_fill	*fill;

	x = game->player->player_x;
	y = game->player->player_y;
	collects = game->count_collect;
	copy = copy_map(game->map->map, game->map->height);
	if (!copy)
		return (0);
	fill = ft_fill(copy, game->map, &collects);
	if (!fill)
		return (0);
	flood_fill(fill, x, y);
	free(fill);
	free_2darr(copy, game->map->height);
	if (collects == 0 && game->map->exit_found)
		return (1);
	return (0);
}

char	**copy_map(char **original_map, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * height);
	if (!copy)
		return (0);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(original_map[i]);
		if (!copy[i])
		{
			free_2darr(copy, i);
			return (0);
		}
		i++;
	}
	return (copy);
}

void	init_win(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->map->width * 64,
			game->map->height * 64, "Sonic Game");
	if (!game->win)
		clean(game);
}
