/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:06:00 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/01 18:52:06 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*sanitize_string(char *line)
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
