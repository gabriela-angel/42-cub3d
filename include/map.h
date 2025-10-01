/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 21:15:06 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/01 19:46:33 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "cub3d.h"

typedef struct s_map
{
	size_t			height;
	size_t			width;
	char			*path;
	int				fd;
	int				**matrix;
	t_map_textures	textures;
}					t_map;

typedef struct s_map_textures
{
	uint32_t		floor;
	uint32_t		ceiling;
	t_hash_table	*paths;
}					t_map_textures;

void				ft_init_map(char *map_path);
void				valid_map_path(char *map_path);
char	*sanitize_string(char *line);

#endif
