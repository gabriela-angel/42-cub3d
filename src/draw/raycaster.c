/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:39:31 by gangel-a          #+#    #+#             */
/*   Updated: 2025/10/21 12:12:28 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_wall_height(t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_dist = ray->side_dist[X] - ray->delta_dist[X];
	else
		ray->wall_dist = ray->side_dist[Y] - ray->delta_dist[Y];
	// printf("Ray side: %d\n", ray->side);
	// printf("Ray side_dist X: %f, side_dist Y: %f\n", ray->side_dist[X], ray->side_dist[Y]);
	// printf("Ray delta_dist X: %f, delta_dist Y: %f\n", ray->delta_dist[X], ray->delta_dist[Y]);
	// printf("Wall dist: %f\n", ray->wall_dist);
	ray->line_height = (int)(HEIGHT / ray->wall_dist);
	ray->line_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->line_start < 0)
		ray->line_start = 0;
	ray->line_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->line_end >= HEIGHT)
		ray->line_end = HEIGHT - 1;
}

void	dda(t_ray *ray, char **map)
{
	char	m_cell;
	
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
		m_cell = map[ray->map_pos[Y]][ray->map_pos[X]];
		if (m_cell > '0' && m_cell <= '9')
			ray->hit = 1;
	}
}

static void	calc_step_and_side(t_ray *ray, t_player *player)
{
	if (ray->dir[X] < 0)
	{
		ray->step[X] = -1;
		ray->side_dist[X] = (player->pos[X] - ray->map_pos[X])
			* ray->delta_dist[X];
	}
	else
	{
		ray->step[X] = 1;
		ray->side_dist[X] = (ray->map_pos[X] + 1 - player->pos[X])
			* ray->delta_dist[X];
	}
	if (ray->dir[Y] < 0)
	{
		ray->step[Y] = -1;
		ray->side_dist[Y] = (player->pos[Y] - ray->map_pos[Y])
			* ray->delta_dist[Y];
	}
	else
	{
		ray->step[Y] = 1;
		ray->side_dist[Y] = (ray->map_pos[Y] + 1 - player->pos[Y])
			* ray->delta_dist[Y];
	}
}

void	set_ray(t_player *player, t_ray *ray, int x)
{
	ray->cam_x = 2 * x / (double) WIDTH - 1;
	ray->map_pos[X] = (int) player->pos[X];
	ray->map_pos[Y] = (int) player->pos[Y];
	ray->dir[X] = player->dir[X] + player->plane[X] * ray->cam_x;
	ray->dir[Y] = player->dir[Y] + player->plane[Y] * ray->cam_x;
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
