/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:19:59 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/08 19:06:42 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_map_chars(char **matrix)
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

void	validate_map_walls(t_map *map)
{
	flood_fill_borders(clone_matrix(map->matrix), map->width, map->height);
	if (get_global_flood_errors()->count > 0)
		ft_error(E_MAP_NOT_CLOSED);
}
