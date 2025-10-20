/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:04:56 by gangel-a          #+#    #+#             */
/*   Updated: 2025/10/20 15:14:07 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rotate_cam(t_player *p, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir[X];
	old_plane_x = p->plane[X];
	p->dir[X] = p->dir[X] * cos(rot_speed) - p->dir[Y] * sin(rot_speed);
	p->dir[Y] = old_dir_x * sin(rot_speed) + p->dir[Y] * cos(rot_speed);
	p->plane[X] = p->plane[X] * cos(rot_speed) - p->plane[Y] * sin(rot_speed);
	p->plane[Y] = old_plane_x * sin(rot_speed) + p->plane[Y] * cos(rot_speed);
}

void	ft_strafe(t_player *p, char **map, keys_t key)
{
	int		offset;
	double	plane[2];

	if (key == A)
	{
		plane[X] = p->dir[Y] * MOVE_SPEED;
		plane[Y] = -p->dir[X] * MOVE_SPEED;
	}
	else if (key == D)
	{
		plane[X] = -p->dir[Y] * MOVE_SPEED;
		plane[Y] = p->dir[X] * MOVE_SPEED;
	}
	if (plane[X] > 0)
		offset = COLLISION_OFFSET;
	else
		offset = -COLLISION_OFFSET;
	if (map[(int)p->pos[Y]][(int)(p->pos[X] + plane[X] + offset)] == '0')
		p->pos[X] += plane[X];
	if (plane[Y] > 0)
		offset = COLLISION_OFFSET;
	else
		offset = -COLLISION_OFFSET;
	if (map[(int)(p->pos[Y] + plane[Y] + offset)][(int)p->pos[X]] == '0')
		p->pos[Y] += plane[Y];
}

void	ft_move_backward(t_player *p, char **map)
{
	int		offset;
	double	dir[2];

	dir[X] = p->dir[X] * MOVE_SPEED;
	dir[Y] = p->dir[Y] * MOVE_SPEED;
	if (dir[X] > 0)
		offset = -COLLISION_OFFSET;
	else
		offset = COLLISION_OFFSET;
	if (map[(int)(p->pos[Y])][(int)(p->pos[X] - dir[X] + offset)] == '0')
		p->pos[X] -= dir[X];
	if (dir[Y] > 0)
		offset = -COLLISION_OFFSET;
	else
		offset = COLLISION_OFFSET;
	if (map[(int)(p->pos[Y] - dir[Y] + offset)][(int)(p->pos[X])] == '0')
		p->pos[Y] -= dir[Y];
}

void	ft_move_forward(t_player *p, char **map)
{
	int		offset;
	double	dir[2];

	dir[X] = p->dir[X] * MOVE_SPEED;
	dir[Y] = p->dir[Y] * MOVE_SPEED;
	if (dir[X] > 0)
		offset = COLLISION_OFFSET;
	else
		offset = -COLLISION_OFFSET;
	if (map[(int)p->pos[Y]][(int)(p->pos[X] + dir[X] + offset)] == '0')
		p->pos[X] += dir[X];
	if (dir[Y] > 0)
		offset = COLLISION_OFFSET;
	else
		offset = -COLLISION_OFFSET;
	if (map[(int)(p->pos[Y] + dir[Y] + offset)][(int)p->pos[X]] == '0')
		p->pos[Y] += dir[Y];
}
