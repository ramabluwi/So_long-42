/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralbliwi <ralbliwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:36:16 by ralbliwi          #+#    #+#             */
/*   Updated: 2025/02/19 15:52:25 by ralbliwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_extra(t_game *game)
{
	free_map(game);
	free(game->map);
	free(game);
	exit(EXIT_FAILURE);
}

void	collect_num(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!game)
	{
		ft_putstr_fd("Error: game structure is NULL\n", 2);
		return ;
	}
	game->count_collect = 0;
	i = 0;
	while (i < game->map->height && game->map->map[i])
	{
		j = 0;
		while (j < game->map->width && game->map->map[i][j])
		{
			if (game->map->map[i][j] == 'C')
				game->count_collect++;
			j++;
		}
		i++;
	}
}

int	count_collect(t_game *game)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (game->map->map && game->map->map[j])
	{
		i = 0;
		while (game->map->map[j][i])
		{
			if (game->map->map[j][i] == 'C')
				k++;
			i++;
		}
		j++;
	}
	return (k);
}

int	count_player(t_game *game)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (game->map->map && game->map->map[j])
	{
		i = 0;
		while (game->map->map[j][i])
		{
			if (game->map->map[j][i] == 'P')
				k++;
			i++;
		}
		j++;
	}
	return (k);
}

int	count_exit(t_game *game)
{
	int	i;
	int	k;
	int	j;

	j = 0;
	k = 0;
	while (game->map->map && game->map->map[j])
	{
		i = 0;
		while (game->map->map[j][i])
		{
			if (game->map->map[j][i] == 'E')
				k++;
			i++;
		}
		j++;
	}
	return (k);
}
