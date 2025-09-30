/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:17:01 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/28 12:33:48 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*sanitize_string(char *line)
{
	size_t	i;

	i = 0;
	line = trim(line);
	while (line[i])
	{
		if (!ft_isascii(line[i]))
			ft_error(E_INVALID_FILE_CHAR);
		i++;
	}
	return (line);
}

void	set_texture(char *key, t_map *map, char *line)
{
	if (ft_strncmp(line, key, 2) == 0)
	{
		if (ft_map_search(map->textures.paths, key))
			ft_error(E_TEX_DUP);
		ft_map_insert(map->textures.paths, key, trim(line + 2));
	}
}

void	fill_texture_paths(t_map *map)
{
	char	*line;
	char	*tmp;
	char	*path;

	map->fd = open(map->path, O_RDONLY);
	if (map->fd < 0)
		ft_error(E_OPEN_FAILED);
	while (1)
	{
		line = get_next_line(map->fd);
		if (!line)
			break ;
		tmp = line;
		line = sanitize_string(line);
		set_texture("NO", map, line);
		set_texture("SO", map, line);
		set_texture("WE", map, line);
		set_texture("EA", map, line);
		free(tmp);
	}
	close_and_clear(map->fd);
}

void	test(char *line, t_map *map)
{
	if (ft_strncmp(line, "F", 1) == 0)
	{
		if (map->textures.floor)
			ft_error(E_F_DUP);
		map->textures.floor = rgb_to_int(trim(line + 1));
	}
	if (ft_strncmp(line, "C", 1) == 0)
	{
		if (map->textures.ceiling)
			ft_error(E_C_DUP);
		map->textures.ceiling = rgb_to_int(trim(line + 1));
	}
}

void	test2(char *line, t_map *map)
{
	if (ft_strncmp(line, "F", 1) == 0)
	{
		if (map->textures.floor)
			ft_error(E_F_DUP);
		map->textures.floor = rgb_to_int(trim(line + 1));
	}
	if (ft_strncmp(line, "C", 1) == 0)
	{
		if (map->textures.ceiling)
			ft_error(E_C_DUP);
		map->textures.ceiling = rgb_to_int(trim(line + 1));
	}
}

void	fill_ceiling_and_floor(t_map *map)
{
	char	*line;
	char	*tmp;
	char	*path;

	map->fd = open(map->path, O_RDONLY);
	if (map->fd < 0)
		ft_error(E_OPEN_FAILED);
	while (1)
	{
		line = get_next_line(map->fd);
		if (!line)
			break ;
		tmp = line;
		line = sanitize_string(line);
		test(line, map);
		free(tmp);
	}
	close_and_clear(map->fd);
}

void	fill_map_matrix(t_map *map)
{
	char	*line;
	char	*tmp;
	char	*path;

	map->fd = open(map->path, O_RDONLY);
	if (map->fd < 0)
		ft_error(E_OPEN_FAILED);
	while (1)
	{
		line = get_next_line(map->fd);
		if (!line)
			break ;
		tmp = line;
		line = sanitize_string(line);
		test2(line, map);
		free(tmp);
	}
	close_and_clear(map->fd);
}

void	fill_map_struct(t_map *map)
{
	char	*line;

	fill_texture_paths(map);
	fill_ceiling_and_floor(map);
	fill_map_matrix(map);
	// Check if all textures and colors are set
}

void	parse_map(char *map_path)
{
	t_map	*map;

	map = &(get_global_cube()->map);
	map->path = map_path;
	map->textures.paths = ft_map_create(10);
	fill_map_struct(map);
}

void	ft_init_map(char *map_path)
{
	valid_map_path(map_path);
	parse_map(map_path);
}
