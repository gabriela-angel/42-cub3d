/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:10:08 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/08 15:26:02 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	has_map_char(char *line)
{
	char	c;

	if (!line)
		return (FALSE);
	c = trim(line)[0];
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
		map->matrix[i] = gc_malloc(map->width + 1);
		ft_memmove(map->matrix[i], line, ft_strlen(line) - 1);
		free(line); // Free the current line before getting the next one
		i++;
		if (i < map->height) // Only get next line if we need it
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

static char	**clone_matrix(char **matrix)
{
	size_t	i;
	size_t	height;
	size_t	width;
	char	**clone;

	height = 0;
	while (matrix[height])
		height++;
	width = ft_strlen(matrix[0]);
	clone = gc_malloc(sizeof(char *) * (height + 1));
	i = 0;
	while (i < height)
	{
		clone[i] = gc_malloc(sizeof(char) * (width + 1));
		ft_memmove(clone[i], matrix[i], width);
		i++;
	}
	clone[i] = NULL;
	return (clone);
}

t_flood_errors	*get_global_flood_errors(void)
{
	static t_flood_errors	errors;

	return (&errors);
}

static t_bool	already_recorded(t_point point)
{
	t_flood_errors	*errors;
	size_t			i;

	errors = get_global_flood_errors();
	i = 0;
	while (i < errors->count)
	{
		if (errors->points[i].x == point.x && errors->points[i].y == point.y)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static void	add_flood_invalid_char(t_point point)
{
	t_flood_errors	*errors;

	if (already_recorded(point))
		return ;
	errors = get_global_flood_errors();
	errors->points = ft_recalloc(errors->points, sizeof(t_point)
			* (errors->count + 1), sizeof(t_point) * errors->count);
	errors->points[errors->count] = point;
	errors->count++;
}

static void	flood_fill(char **matrix, size_t width, size_t height,
		t_point start)
{
	if (start.x >= width || start.y >= height)
		return ;
	if (matrix[start.y][start.x] == '1' || matrix[start.y][start.x] == '3')
		return ;
	if (matrix[start.y][start.x] == '0')
	{
		add_flood_invalid_char(start);
		return ;
	}
	matrix[start.y][start.x] = '3';
	if (start.x > 0)
		flood_fill(matrix, width, height, (t_point){start.x - 1, start.y});
	if (start.x < width - 1)
		flood_fill(matrix, width, height, (t_point){start.x + 1, start.y});
	if (start.y > 0)
		flood_fill(matrix, width, height, (t_point){start.x, start.y - 1});
	if (start.y < height - 1)
		flood_fill(matrix, width, height, (t_point){start.x, start.y + 1});
}

static void	generate_flood_error_context(void)
{
	t_map			*map;
	char			*line;
	size_t			i;
	size_t			j;
	t_flood_errors	*errors;
	char			*matrix;
	char			*c2;

	errors = get_global_flood_errors();
	map = &get_global_cube()->map;
	i = 0;
	matrix = ft_strdup("");
	while (map->matrix[i])
	{
		j = 0;
		line = ft_strdup(map->matrix[i]);
		while (j < errors->count)
		{
			if (errors->points[j].y == i)
				line = ft_iputcolor_free(line, errors->points[j].x, C_RED);
			j++;
		}
		matrix = ft_strjoin_with_free(matrix, line);
		free(line);
		matrix = ft_strjoin_with_free(matrix, "\n");
		i++;
	}
	c2 = NULL;
	while ((c2 = ft_strchr(matrix, '2')))
		*c2 = ' ';
	printf("Matrix: \n%s\n", matrix);
}

static void	print_errors(void)
{
	t_flood_errors	*errors;
	size_t			i;

	errors = get_global_flood_errors();
	printf(C_RED "Map validation errors (%zu):\n" C_RST, errors->count);
	i = 0;
	while (i < errors->count)
	{
		printf(C_YEL " - Invalid map character at (x: %zu, y: %zu)\n" C_RST,
			errors->points[i].x, errors->points[i].y);
		i++;
	}
}

static void	flood_fill_borders(char **matrix, size_t width, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		if (matrix[i][0] != '1')
			flood_fill(matrix, width, height, (t_point){0, i});
		if (matrix[i][width - 1] != '1')
			flood_fill(matrix, width, height, (t_point){width - 1, i});
		i++;
	}
	i = 0;
	while (i < width)
	{
		if (matrix[0][i] != '1')
			flood_fill(matrix, width, height, (t_point){i, 0});
		if (matrix[height - 1][i] != '1')
			flood_fill(matrix, width, height, (t_point){i, height - 1});
		i++;
	}
	if (get_global_flood_errors()->count > 0)
	{
		print_errors();
		generate_flood_error_context();
		ft_error(E_SUCCESS);
		// ft_error(E_WALLS_NOT_CLOSED);
	}
}

static void	validate_map_walls(t_map *map)
{
	map->flood_fill = clone_matrix(map->matrix);
	flood_fill_borders(map->flood_fill, map->width, map->height);
}

static void	print_map(t_map *map)
{
	size_t	i;

	printf(C_BLU "Map matrix (%zux%zu):\n" C_RST, map->width, map->height);
	i = 0;
	while (i < map->height)
	{
		printf(C_CYA "%s\n" C_RST, map->matrix[i]);
		i++;
	}
}

void	handle_map_matrix(t_map *map)
{
	map->matrix = gc_malloc(sizeof(char *) * (map->height + 1));
	fill_matrix(map);
	validate_map_chars(map->matrix);
	normalize_map_matrix(map);
	print_map(map);
	validate_map_walls(map);
	// init_sprites(map);
}
