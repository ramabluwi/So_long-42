/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralbliwi <ralbliwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:46:52 by ralbliwi          #+#    #+#             */
/*   Updated: 2025/02/20 18:18:30 by ralbliwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		clean(game);
	if (keycode == XK_w || keycode == XK_Up)
	{
		move_player(game, 0, -1);
	}
	if (keycode == XK_s || keycode == XK_Down)
	{
		move_player(game, 0, 1);
	}
	if (keycode == XK_a || keycode == XK_Left)
	{
		move_player(game, -1, 0);
	}
	if (keycode == XK_d || keycode == XK_Right)
	{
		move_player(game, 1, 0);
	}
	return (0);
}

t_game	*initialize_game(char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = initialize_map(game);
	game->move_count = 0;
	game->win = NULL;
	game->image = NULL;
	game->player = NULL;
	game->mlx = NULL;
	map_reader(argv[1], game);
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		clean(game);
	init_player(game);
	game->image = init_imgs(game->mlx, game);
	return (game);
}

int	close_win(t_game *game)
{
	clean(game);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc != 2)
	{
		ft_putstr_fd("Error Args\n", 2);
		exit(EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		file_name(argv[1]);
		game = initialize_game(argv);
		collect_num(game);
		map_check(game);
		init_win(game);
		if (!game)
			exit(EXIT_FAILURE);
		render_textures(game);
		redesign_player(game, game->mlx, game->win);
		mlx_hook(game->win, 2, 1L << 0, key_press, game);
		mlx_hook(game->win, 17, 0, close_win, game);
		mlx_loop(game->mlx);
	}
	return (0);
}
