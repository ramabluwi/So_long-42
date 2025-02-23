/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralbliwi <ralbliwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:35:28 by ralbliwi          #+#    #+#             */
/*   Updated: 2025/02/19 15:15:07 by ralbliwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_name(char *s)
{
	s += (ft_strlen(s) - 4);
	if (ft_strncmp(s, ".ber", 4) != 0)
	{
		write(2, "Wronge file name :)\n", 19);
		exit(EXIT_FAILURE);
	}
}

int	is_rectangular(t_game *game)
{
	size_t	length;
	int		i;

	i = 0;
	length = ft_strlen(game->map->map[i]);
	i++;
	while (game->map->map[i])
	{
		if (length != ft_strlen(game->map->map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_char(t_game *game)
{
	int		i;
	int		j;
	char	ch;

	i = 0;
	j = 0;
	if (!game || !game->map || !game->map->map)
		return (0);
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			ch = game->map->map[i][j];
			if (ch != '1' && ch != '0' && ch != 'P' && ch != 'C' && ch != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_ones(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			if (i == 0 || i == game->map->height - 1 || j == 0
				|| j == game->map->width - 1)
				if (game->map->map[i][j] != '1')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_counts(t_game *game)
{
	int	exit;
	int	player;

	exit = 0;
	player = 0;
	game->map->collectibles = 0;
	player = count_player(game);
	exit = count_exit(game);
	game->map->collectibles = count_collect(game);
	if (player != 1)
		return (0);
	if (exit != 1)
		return (0);
	if (game->map->collectibles < 1)
		return (0);
	return (1);
}
