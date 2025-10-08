/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:20:33 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/08 19:33:15 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	has_map_char(char *line)
{
	char	c;

	if (!line)
		return (FALSE);
	c = trim(line)[0];
	if (c == 'F' || c == 'C')
		return (FALSE);
	return (ft_strchr(line, '1') || ft_strchr(line, '0'));
}

char	**clone_matrix(char **matrix)
{
	size_t	i;
	size_t	height;
	size_t	width;
	char	**clone;

	height = 0;
	while (matrix[height])
		height++;
	width = ft_strlen(matrix[0]);
	clone = gc_malloc(sizeof(char *) * (height + 1));
	i = 0;
	while (i < height)
	{
		clone[i] = gc_malloc(sizeof(char) * (width + 1));
		ft_memmove(clone[i], matrix[i], width);
		i++;
	}
	clone[i] = NULL;
	return (clone);
}

void	flood_fill(char **mtx, size_t wdt, size_t hgt, t_point start)
{
	if (start.x >= wdt || start.y >= hgt)
		return ;
	if (mtx[start.y][start.x] == '1' || mtx[start.y][start.x] == '3')
		return ;
	if (mtx[start.y][start.x] == '0')
	{
		add_flood_invalid_char(start);
		return ;
	}
	mtx[start.y][start.x] = '3';
	if (start.x > 0)
		flood_fill(mtx, wdt, hgt, (t_point){start.x - 1, start.y});
	if (start.x < wdt - 1)
		flood_fill(mtx, wdt, hgt, (t_point){start.x + 1, start.y});
	if (start.y > 0)
		flood_fill(mtx, wdt, hgt, (t_point){start.x, start.y - 1});
	if (start.y < hgt - 1)
		flood_fill(mtx, wdt, hgt, (t_point){start.x, start.y + 1});
}

void	normalize_map_matrix(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (ft_strchr(" \t", map->matrix[i][j]))
				map->matrix[i][j] = '2';
			j++;
		}
		i++;
	}
}
