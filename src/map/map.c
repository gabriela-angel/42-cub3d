/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:17:01 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/01 15:07:33 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	valid_map_path(map_path);
	parse_map(map_path);
}
