/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:10:08 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/08 19:40:21 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_matrix(t_map *map)
{
	size_t	i;
	char	*line;

	map->fd = open(map->path, O_RDONLY);
	while (1)
	{
		line = get_next_line(map->fd);
		if (has_map_char(line))
			break ;
	}
	i = 0;
	while (i < map->height)
	{
		map->matrix[i] = gc_malloc(map->width + 1);
		ft_memmove(map->matrix[i], line, ft_strlen(line) - 1);
		i++;
		if (i < map->height)
			line = get_next_line(map->fd);
	}
	close_and_clear(&map->fd);
}

void	flood_fill_borders(char **mtrx, size_t wdt, size_t hgt)
{
	size_t	i;

	i = 0;
	while (i < hgt)
	{
		if (mtrx[i][0] != '1')
			flood_fill(mtrx, wdt, hgt, (t_point){0, i});
		if (mtrx[i][wdt - 1] != '1')
			flood_fill(mtrx, wdt, hgt, (t_point){wdt - 1, i});
		i++;
	}
	i = 0;
	while (i < wdt)
	{
		if (mtrx[0][i] != '1')
			flood_fill(mtrx, wdt, hgt, (t_point){i, 0});
		if (mtrx[hgt - 1][i] != '1')
			flood_fill(mtrx, wdt, hgt, (t_point){i, hgt - 1});
		i++;
	}
}

void	handle_map_matrix(t_map *map)
{
	map->matrix = gc_malloc(sizeof(char *) * (map->height + 1));
	fill_matrix(map);
	validate_map_chars(map->matrix);
	normalize_map_matrix(map);
	validate_map_walls(map);
	// init_sprites(map);
	// init_player(map);
}
