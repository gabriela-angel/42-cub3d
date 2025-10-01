/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:39:31 by gangel-a          #+#    #+#             */
/*   Updated: 2025/09/30 22:46:23 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda(t_ray *ray)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_dist[X] < ray->side_dist[Y])
		{
			ray->side_dist[X] += ray->delta_dist[X];
			ray->map_pos[X] += ray->step[X];
			ray->side = 0;
		}
		else
		{
			ray->side_dist[Y] += ray->delta_dist[Y];
			ray->map_pos[Y] += ray->step[Y];
			ray->side = 1;
		}
		//Check if ray has hit a wall
		// Remember to change this to the actual map variable later
		if (0) // if (worldMap[ray->map_pos[X]][ray->map_pos[Y]] > 0)
			ray->hit = 1;
	}
}

void	calc_step_and_side(t_ray *ray, t_player *player)
{
	if (ray->dir[X] < 0)
	{
		ray->step[X] = -1;
		ray->side_dist[X] = (player->pos[X] - ray->map_pos[X]) * ray->delta_dist[X];
	}
	else
	{
		ray->step[X] = 1;
		ray->side_dist[X] = (ray->map_pos[X] + 1.0 - player->pos[X]) * ray->delta_dist[X];
	}
	if (ray->dir[Y] < 0)
	{
		ray->step[Y] = -1;
		ray->side_dist[Y] = (player->pos[Y] - ray->map_pos[Y]) * ray->delta_dist[Y];
	}
	else
	{
		ray->step[Y] = 1;
		ray->side_dist[Y] = (ray->map_pos[Y] + 1.0 - player->pos[Y]) * ray->delta_dist[Y];
	}
}

void	set_ray(t_player *player, t_ray *ray, int x)
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
	int		x;
	t_ray	ray;

	x = 0;
	// the player has to be set beforehand, but for now I will set it here using the example in the guide
	t_player *player;

	player = (t_player *)ft_gc_malloc(1 * sizeof(t_player));
	player->pos[X] = 22;
	player->pos[Y] = 12;
	player->dir[X] = -1;
	player->dir[Y] = 0;
	player->plane[X] = 0;
	player->plane[Y] = 0.66;
	
	// this can stay
	while (x < WIDTH)
	{
		set_ray(player, &ray, x);
		dda(&ray);
		x++;
	}
}
