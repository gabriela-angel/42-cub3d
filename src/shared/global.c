/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:40:39 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/12 21:20:00 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_mlx *get_global_mlx(void)
{
    static t_mlx mlx_struct;

    return (&mlx_struct);
}

t_cube	*get_global_cube(void)
{
	static t_cube	cube_struct;

	return (&cube_struct);
}