/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralbliwi <ralbliwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:13:33 by ralbliwi          #+#    #+#             */
/*   Updated: 2025/02/20 15:15:56 by ralbliwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_textures(t_game *game, t_image *image)
{
	if (image->floor)
		mlx_destroy_image(game->mlx, image->floor);
	if (image->collect)
		mlx_destroy_image(game->mlx, image->collect);
	if (image->exit)
		mlx_destroy_image(game->mlx, image->exit);
	if (image->player)
		mlx_destroy_image(game->mlx, image->player);
	if (image->wall)
		mlx_destroy_image(game->mlx, image->wall);
	free(image);
}

void	check_textures(t_game *game, t_image *image)
{
	free_textures(game, image);
	ft_putstr_fd("Error\ninvalid texture\n", 2);
	clean(game);
}
