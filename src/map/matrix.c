/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:10:08 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/06 13:47:45 by lhenriqu         ###   ########.fr       */
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

static void	validate_map_chars(char **matrix)
{
	size_t	i;
	size_t	j;
	char	*error;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j] != '\n' && matrix[i][j] != '\0')
		{
			if (!ft_strchr("\t 01NSEW", matrix[i][j]))
			{
				error = ft_strdup("Invalid character: '" C_YEL "x" C_RED "'.");
				error[27] = matrix[i][j];
				add_error_context(error);
				ft_error(E_INVALID_MAP_CHAR);
			}
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
		map->matrix[i] = ft_gc_malloc(map->width + 1);
		ft_memmove(map->matrix[i], line, ft_strlen(line) - 1);
		free(line);  // Free the current line before getting the next one
		i++;
		if (i < map->height)  // Only get next line if we need it
			line = get_next_line(map->fd);
	}
	close_and_clear(map->fd);
}

void	normalize_map_matrix(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (ft_strchr(" \t", map->matrix[i][j]))
				map->matrix[i][j] = '2';
			j++;
		}
		i++;
	}
}

// static void validate_map_walls(t_map *map)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	while (i < map->height)
// 	{
// 		j = ft_strlen(map->matrix[i]);
// 		while (j < map->width)
// 		{
// 			if (ft_strchr("\t ", map->matrix[i][j]))
// 				map->matrix[i][j] = '2';
// 			j++;
// 		}
// 		map->matrix[i][j] = '\0';
// 		i++;
// 	}
// }

static void print_map(t_map *map)
{
	size_t	i;

	ft_printf(C_BLU "Map matrix (%zux%zu):\n" C_RST, map->width, map->height);
	i = 0;
	while (i < map->height)
	{
		ft_printf(C_CYA "%s\n" C_RST, map->matrix[i]);
		i++;
	}
}

void	handle_map_matrix(t_map *map)
{
	map->matrix = ft_gc_malloc(sizeof(char *) * (map->height + 1));
	fill_matrix(map);
	validate_map_chars(map->matrix);
	normalize_map_matrix(map);
	print_map(map);
	// validate_map_walls(map);
	// init_sprites(map);
}
