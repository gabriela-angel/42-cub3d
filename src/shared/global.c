/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:40:39 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/03 13:31:06 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_mlx	*get_global_mlx(void)
{
	static t_mlx	mlx_struct;

	return (&mlx_struct);
}

t_cube	*get_global_cube(void)
{
	static t_cube	cube_struct;

	return (&cube_struct);
}
