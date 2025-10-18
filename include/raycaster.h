/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:32:27 by gangel-a          #+#    #+#             */
/*   Updated: 2025/10/18 20:34:46 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# include "player.h"

typedef struct s_ray
{
	double	cam_x;
	int		map_pos[2];
	double	dir[2];
	double	side_dist[2];
	double	delta_dist[2];
	double	wall_dist;
	int step[2];
	int hit;
	int side;
	int line_height;
	int line_start;
	int line_end;
}	t_ray;

// DRAW
void		set_ray(t_player *player, t_ray *ray, int x);
void		dda(t_ray *ray, char **map);
void		calculate_wall_height(t_ray *ray);

#endif