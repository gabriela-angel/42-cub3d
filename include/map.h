/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 21:15:06 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/18 20:38:15 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "cub3d.h"
# include <stdint.h>

typedef struct s_point
{
	size_t	x;
	size_t	y;
}	t_point;

enum e_texture_index
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

typedef struct s_texture
{
	void			*tex;
	int				width;
	int				height;
	int				bpp;
	int				line_size;
}					t_texture;

typedef struct s_map_textures
{
	uint32_t		floor;
	uint32_t		ceiling;
	t_hash_table	*paths;
	t_texture		textures[4];
}					t_map_textures;

typedef struct s_map
{
	size_t			height;
	size_t			width;
	char			*path;
	int				fd;
	char			**flood_fill;
	char			**matrix;
	t_map_textures	textures;
}					t_map;

void				ft_init_map(char *map_path);
void				handle_map_textures(t_map *map);
void				handle_map_matrix(t_map *map);
t_bool				has_map_char(char *line);
void				valid_textures(t_map *map);
t_bool				has_image_extension(char *path);
void				update_width_and_height(t_map *map, size_t line_length);
void				ft_render_img(void);


#endif
