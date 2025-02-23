/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralbliwi <ralbliwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:33:57 by ralbliwi          #+#    #+#             */
/*   Updated: 2025/02/18 18:10:39 by ralbliwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_flood_fill	*ft_fill(char **map, t_map *orig_map, int *collects)
{
	t_flood_fill	*f_data;

	f_data = malloc(sizeof(t_flood_fill));
	if (!f_data)
		return (NULL);
	f_data->mapi = map;
	f_data->original_map = orig_map;
	f_data->collectibles = collects;
	return (f_data);
}

int	flood_fill(t_flood_fill *fdata, int x, int y)
{
	if (x < 0 || y < 0 || x >= fdata->original_map->width
		|| y >= fdata->original_map->height)
		return (1);
	if (fdata->mapi[y][x] == '1' || fdata->mapi[y][x] == 'V')
		return (1);
	if (fdata->mapi[y][x] == 'C')
		(*fdata->collectibles)--;
	if (fdata->mapi[y][x] == 'E')
		fdata->original_map->exit_found = 1;
	fdata->mapi[y][x] = 'V';
	flood_fill(fdata, x + 1, y);
	flood_fill(fdata, x - 1, y);
	flood_fill(fdata, x, y + 1);
	flood_fill(fdata, x, y - 1);
	return (0);
}
