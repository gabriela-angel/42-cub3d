/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:39:31 by gangel-a          #+#    #+#             */
/*   Updated: 2025/10/13 23:17:44 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
{
	ray->cam_x = 2 * x / (double) WIDTH - 1;
	ray->dir[X] = player->dir[X] + player->plane[X] * ray->cam_x;
	ray->dir[Y] = player->dir[Y] + player->plane[Y] * ray->cam_x;
	ray->map_pos[X] = (int) player->pos[X];
	ray->map_pos[Y] = (int) player->pos[Y];
	if (ray->dir[X] == 0)
		ray->delta_dist[X] = 1e30;
	else
		ray->delta_dist[X] = fabs(1 / ray->dir[X]);
	if (ray->dir[Y] == 0)
		ray->delta_dist[Y] = 1e30;
	else
		ray->delta_dist[Y] = fabs(1 / ray->dir[Y]);
	calc_step_and_side(ray, player);
}

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
		dda(&ray);
		calculate_wall_height(&ray);
		// on this part, we will determine the texture of the walls, to be drawn, and another to draw the texture of the floor/ceiling
		//draw_textures(&ray, x, NULL); // null is a place holder for thw texture info
		x++;
	}
}
