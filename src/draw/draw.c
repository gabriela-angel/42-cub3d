/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:39:31 by gangel-a          #+#    #+#             */
/*   Updated: 2025/10/16 19:42:46 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_3d_map()
{
	int			x;
	t_ray		ray;
	t_player	player;

	x = 0;
	player = get_global_cube()->player;
	while (x < WIDTH)
	{
		set_ray(&player, &ray, x);
		dda(&ray, get_global_cube()->map.matrix);
		calculate_wall_height(&ray);
		// on this part, we will determine the texture of the walls, to be drawn, and another to draw the texture of the floor/ceiling
		//draw_textures(&ray, x, NULL); // null is a place holder for thw texture info
		x++;
	}
}
