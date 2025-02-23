/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralbliwi <ralbliwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:39:20 by ralbliwi          #+#    #+#             */
/*   Updated: 2025/02/19 14:35:50 by ralbliwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*initialize_map(t_game *game)
{
	game->map = malloc(sizeof(t_game));
	if (!game->map)
	{
		ft_putstr_fd("Can't init map\n", 2);
		free_init_map(game);
	}
	game->map->width = 0;
	game->map->height = 0;
	game->map->exit_found = 0;
	game->map->map = NULL;
	game->map->collectibles = 0;
	return (game->map);
}

int	ft_open(char *argv, t_game *game)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("failed open map\n");
		free(game->map);
		free(game);
		exit(1);
	}
	return (fd);
}

void	map_reader(char *map_name, t_game *game)
{
	int	i;
	int	fd;

	i = 0;
	fd = ft_open(map_name, game);
	if (fd == -1)
		free_extra(game);
	game->map->height = count_lines(fd);
	if (game->map->height <= 2)
		free_extra(game);
	game->map->map = malloc(sizeof(char *) * (game->map->height + 1));
	if (!game->map->map)
		free_extra(game);
	fd = ft_open(map_name, game);
	while (i < game->map->height)
	{
		game->map->map[i] = get_next_line(fd);
		if (i == 0)
			game->map->width = ft_strlen(game->map->map[i]) - 1;
		i++;
	}
	free(get_next_line(fd));
	game->map->map[i] = NULL;
	replacing_nline(game->map->map);
	close(fd);
}

int	count_lines(int fd)
{
	int		count;
	char	*line;

	count = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

void	replacing_nline(char **tmp)
{
	int	i;
	int	j;

	if (!tmp)
		return ;
	i = 0;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] == '\n')
			{
				tmp[i][j] = '\0';
				break ;
			}
			j++;
		}
		i++;
	}
}
