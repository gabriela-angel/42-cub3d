/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:10:08 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/02 16:48:19 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	has_map_char(char *line)
{
	char	c;

	if (!line)
		return (FALSE);
	c = sanitize_string(line)[0];
	if (c == 'F' || c == 'C')
		return (FALSE);
	return (ft_strchr(line, '1') || ft_strchr(line, '0'));
}

static void	validate_map_matrix(char **matrix)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (!ft_strchr("\t 01NSEW", matrix[i][j]))
				ft_error(E_INVALID_MAP_CHAR);
			j++;
		}
		i++;
	}
}

static void	fill_matrix(t_map *map)
{
	size_t	i;
	char	*line;

	map->fd = open(map->path, O_RDONLY);
	if (map->fd < 0)
		ft_error(E_OPEN_FAILED);
	while (1)
	{
		line = get_next_line(map->fd);
		if (has_map_char(line))
			break ;
		free(line);
	}
	i = 0;
	while (i < map->height)
	{
		ft_gc_add(line);
		map->matrix[i] = line;
		i++;
		line = get_next_line(map->fd);
	}
	free(line);
	close_and_clear(map->fd);
}

void	handle_map_matrix(t_map *map)
{
	if (!map->height)
		ft_error(E_EMPTY_MAP);
	map->matrix = ft_gc_malloc(sizeof(char *) * (map->height + 1));
	fill_matrix(map);
	validate_map_matrix(map->matrix);
}
