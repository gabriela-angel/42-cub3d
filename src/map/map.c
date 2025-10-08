/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:17:01 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/08 18:31:00 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_width_and_height(t_map *map, size_t line_length) // map_utils
{
	size_t	new_width;

	new_width = line_length - 1;
	if (new_width > map->width)
		map->width = new_width;
	map->height++;
}

static void	check_file_content(char *map_path)
{
	char	*line;
	int		fd;
	size_t	i;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		ft_error(E_OPEN_FAILED);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		ft_error(E_EMPTY_MAP_FILE);
	}
	while (line)
	{
		i = 0;
		while (line[i])
		{
			if (!ft_isascii(line[i]))
				ft_error(E_INVALID_FILE_CHAR);
			i++;
		}
		line = get_next_line(fd);
	}
	close_and_clear(&fd);
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
	if (ft_strcmp(map_path + ft_strlen(map_path) - 4, ".cub") != 0)
		ft_error(E_INVALID_MAP_NAME);
	check_file_content(map_path);
	parse_map(map_path);
}
