/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:22:28 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/09 14:59:30 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*colorize_line(const char *src, size_t row)
{
	size_t			j;
	char			*line;
	t_flood_errors	*errors;

	j = 0;
	line = ft_strdup(src);
	errors = get_global_flood_errors();
	while (j < errors->count)
	{
		if (errors->points[j].y == row)
			line = ft_iputcolor_free(line, errors->points[j].x, C_RED);
		j++;
	}
	return (line);
}

static char	*build_colored_matrix(t_map *map)
{
	char	*matrix;
	char	*line;
	size_t	i;

	matrix = ft_strdup("");
	i = 0;
	while (map->matrix[i])
	{
		line = colorize_line(map->matrix[i], i);
		matrix = ft_strjoin_with_free(matrix, line);
		free(line);
		matrix = ft_strjoin_with_free(matrix, "\n");
		i++;
	}
	return (matrix);
}

static void	postprocess_and_print_matrix(char *matrix_str)
{
	char	*c2;

	c2 = ft_strchr(matrix_str, '2');
	while (c2)
	{
		*c2 = ' ';
		c2 = ft_strchr(c2 + 1, '2');
	}
	ft_printf("Matrix:\n%s\n", matrix_str);
}

void	print_flood_error(char *message)
{
	t_map	*map;
	char	*matrix_str;

	ft_printf(C_CYA "\t%s\n" C_RST, message);
	map = &get_global_cube()->map;
	matrix_str = build_colored_matrix(map);
	print_errors();
	postprocess_and_print_matrix(matrix_str);
	free(matrix_str);
	free(get_global_flood_errors()->points);
}
