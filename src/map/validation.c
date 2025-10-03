/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:39:10 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/03 12:08:39 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_textures_present(t_map *map)
{
	if (!ft_map_search(map->textures.paths, "NO"))
		ft_error(E_TEX_NO_MISS);
	if (!ft_map_search(map->textures.paths, "SO"))
		ft_error(E_TEX_SO_MISS);
	if (!ft_map_search(map->textures.paths, "WE"))
		ft_error(E_TEX_WE_MISS);
	if (!ft_map_search(map->textures.paths, "EA"))
		ft_error(E_TEX_EA_MISS);
	if (!map->textures.floor)
		ft_error(E_F_MISS);
	if (!map->textures.ceiling)
		ft_error(E_C_MISS);
}

static void	check_texture_extensions(t_map *map)
{
	char	*path;
	ssize_t no_ext;

	path = ft_map_search(map->textures.paths, "NO");
	no_ext = ft_strlen(path) - 4;
	if (ft_strcmp(path + no_ext, ".png") != 0 && ft_strcmp(path + no_ext, ".xpm") != 0)
		ft_error(E_NO_INV_EXT);
	path = ft_map_search(map->textures.paths, "SO");
	no_ext = ft_strlen(path) - 4;
	if (ft_strcmp(path + no_ext, ".png") != 0 && ft_strcmp(path + no_ext, ".xpm") != 0)
		ft_error(E_SO_INV_EXT);
	path = ft_map_search(map->textures.paths, "WE");
	no_ext = ft_strlen(path) - 4;
	if (ft_strcmp(path + no_ext, ".png") != 0 && ft_strcmp(path + no_ext, ".xpm") != 0)
		ft_error(E_WE_INV_EXT);
	path = ft_map_search(map->textures.paths, "EA");
	no_ext = ft_strlen(path) - 4;
	if (ft_strcmp(path + no_ext, ".png") != 0 && ft_strcmp(path + no_ext, ".xpm") != 0)
		ft_error(E_EA_INV_EXT);
}

static int	try_open(char **paths)
{
	int	i;
	int	fd;

	i = 0;
	while (paths[i])
	{
		fd = open(paths[i], O_RDONLY);
		if (fd == -1)
			return (i + 1);
		close(fd);
		i++;
	}
	return (0);
}

static void	check_files_accessible(t_map *map)
{
	char	*paths[5];
	int		error;

	paths[0] = ft_map_search(map->textures.paths, "NO");
	paths[1] = ft_map_search(map->textures.paths, "SO");
	paths[2] = ft_map_search(map->textures.paths, "WE");
	paths[3] = ft_map_search(map->textures.paths, "EA");
	paths[4] = NULL;
	error = try_open(paths);
	if (error != 0)
		add_error_context(ft_strdup(strerror(errno)));
	if (error == 1)
		ft_error(E_NO_FILE);
	else if (error == 2)
		ft_error(E_SO_FILE);
	else if (error == 3)
		ft_error(E_WE_FILE);
	else if (error == 4)
		ft_error(E_EA_FILE);
}

void	valid_textures(t_map *map)
{
	check_textures_present(map);
	check_texture_extensions(map);
	check_files_accessible(map);
}

void	valid_map_path(char *map_path)
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
