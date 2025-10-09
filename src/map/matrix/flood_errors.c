/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:45:10 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/08 19:46:23 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	add_flood_invalid_char(t_point point)
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

void	print_errors(void)
{
	t_flood_errors	*errors;
	size_t			i;

	errors = get_global_flood_errors();
	ft_printf(C_RED "\tMap validation errors (%i):\n" C_RST, errors->count);
	i = 0;
	while (i < errors->count)
	{
		ft_printf(C_YEL "\t - Invalid map character at (x: %i, y: %i)\n" C_RST,
			errors->points[i].x, errors->points[i].y);
		i++;
	}
}
