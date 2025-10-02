/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:06:00 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/02 16:46:05 by lhenriqu         ###   ########.fr       */
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

static void	set_texture(char *key, t_map *map, char *line)
{
	if (ft_strncmp(line, key, 2) == 0)
	{
		if (ft_map_search(map->textures.paths, key))
			ft_error(E_TEX_DUP);
		ft_map_insert(map->textures.paths, key, trim(line + 2));
	}
}

static void	set_ceiling_and_floor(char *line, t_map *map)
{
	if (line[0] == 'F')
	{
		if (map->textures.floor)
			ft_error(E_F_DUP);
		map->textures.floor = rgb_to_int(trim(line + 1));
	}
	if (line[0] == 'C')
	{
		if (map->textures.ceiling)
			ft_error(E_C_DUP);
		map->textures.ceiling = rgb_to_int(trim(line + 1));
	}
}

static void valid_line(char *line, t_bool map_end)
{
	if (line[0] == '\n')
		return ;
	if (ft_strncmp(line, "NO", 2)
		&& ft_strncmp(line, "SO", 2)
		&& ft_strncmp(line, "WE", 2)
		&& ft_strncmp(line, "EA", 2)
		&& line[0] != 'F'
		&& line[0] != 'C')
	{
		add_error_context(ft_strdup(line));
		ft_error(E_INVALID_ELEMENT);
	}
	if (map_end)
		ft_error(E_MAP_NOT_LAST_ELEMENT);
}

static void	fill_texture_paths(t_map *map)
{
	char	*line;
	char	*tmp;
	t_bool	map_end;

	map_end = FALSE;
	while (1)
	{
		line = get_next_line(map->fd);
		if (!line)
			break ;
		tmp = line;
		line = sanitize_string(line);
		valid_line(line, map_end);
		set_texture("NO", map, line);
		set_texture("SO", map, line);
		set_texture("WE", map, line);
		set_texture("EA", map, line);
		set_ceiling_and_floor(line, map);
		if (!map_end && has_map_char(tmp))
			map->height++;
		else if (map->height)
			map_end = TRUE;
		free(tmp);
	}
}

void	handle_map_textures(t_map *map)
{
	char	*line;

	map->fd = open(map->path, O_RDONLY);
	if (map->fd < 0)
		ft_error(E_OPEN_FAILED);
	fill_texture_paths(map);
	close_and_clear(map->fd);
	map->fd = 0;
	valid_textures(map);
}
