/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:17:01 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/03 13:22:30 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_map_path(char *map_path)
{
	char	*tmp;
	int		fd;

	if (ft_strcmp(map_path + ft_strlen(map_path) - 4, ".cub") != 0)
		ft_error(E_INVALID_MAP_NAME);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		ft_error(E_OPEN_FAILED);
	tmp = get_next_line(fd);
	if (!tmp)
	{
		close(fd);
		ft_error(E_EMPTY_MAP_FILE);
	}
	free(tmp);
	close_and_clear(fd);
}

static void	parse_map(char *map_path)
{
	t_map	*map;

	map = &(get_global_cube()->map);
	map->path = map_path;
	map->textures.paths = ft_map_create(10);
	handle_map_textures(map);
	handle_map_matrix(map);
}

void	ft_init_map(char *map_path)
{
	check_map_path(map_path);
	parse_map(map_path);
}
