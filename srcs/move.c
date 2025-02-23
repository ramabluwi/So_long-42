/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralbliwi <ralbliwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:55:42 by ralbliwi          #+#    #+#             */
/*   Updated: 2025/02/19 15:10:42 by ralbliwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_game *game)
{
	game->player = malloc(sizeof(t_player));
	if (!game->player)
	{
		ft_putstr_fd("error allocating memory for player\n", 2);
		clean(game);
	}
	game->player->player_x = 0;
	game->player->player_y = 0;
	find_position(game);
}

void	move_player(t_game *game, int pos_x, int pos_y)
{
	int	new_x;
	int	new_y;

	new_x = game->player->player_x + pos_x;
	new_y = game->player->player_y + pos_y;
	if (game->map->map[new_y][new_x] != '1')
	{
		game->player->player_x = new_x;
		game->player->player_y = new_y;
		if (game->map->map[new_y][new_x] == 'C')
		{
			game->count_collect--;
			game->map->map[new_y][new_x] = '0';
		}
		if (game->map->map[new_y][new_x] == 'E')
		{
			if (game->count_collect == 0)
				close_game(game);
		}
		game->move_count++;
		redesign_player(game, game->mlx, game->win);
		ft_putnbr_fd(game->move_count, 1);
		write(1, "\n", 1);
	}
}

void	close_game(t_game *game)
{
	ft_putnbr_fd(++game->move_count, 1);
	write(1, "\nCongrats ! YOU WIN :)\n", 23);
	clean(game);
}

void	find_position(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->map->map[j])
	{
		i = 0;
		while (game->map->map[j][i])
		{
			if (game->map->map[j][i] == 'P')
			{
				game->player->player_x = i;
				game->player->player_y = j;
			}
			i++;
		}
		j++;
	}
}
