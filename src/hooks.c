/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:25:48 by gangel-a          #+#    #+#             */
/*   Updated: 2025/10/13 23:17:01 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_rotate_cam(t_player *p, char *map, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir[X];
	old_plane_x= p->plane[X];
	p->dir[X] = p->dir[X] * cos(rot_speed) - p->dir[Y] * sin(rot_speed);
	p->dir[Y] = old_dir_x * sin(rot_speed) + p->dir[Y] * cos(rot_speed);
	p->plane[X] = p->plane[X] * cos(rot_speed) - p->plane[Y] * sin(rot_speed);
	p->plane[Y] = old_plane_x * sin(rot_speed) + p->plane[Y] * cos(rot_speed);
}

static void	ft_strafe(t_player *p, char *map, keys_t key)
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
	if (map[(int)(p->pos[X] + plane[X] + offset)][(int)p->pos[Y]] == false)
		p->pos[X] += plane[X];
	if (plane[Y] > 0)
		offset = COLLISION_OFFSET;
	else
		offset = -COLLISION_OFFSET;
	if (map[(int)p->pos[X]][(int)(p->pos[Y] + plane[Y] + offset)] == false)
		p->pos[Y] += plane[Y];
}

static void	ft_move_backward(t_player *p, char *map)
{
	int		offset;
	double	dir[2];

	dir[X] = p->dir[X] * MOVE_SPEED;
	dir[Y] = p->dir[Y] * MOVE_SPEED;
	if (dir[X] > 0)
		offset = -COLLISION_OFFSET;
	else
		offset = COLLISION_OFFSET;
	if (map[(int)(p->pos[X] - dir[X] + offset)][(int)(p->pos[Y])] == false)
		p->pos[X] -= dir[X];
	if (dir[Y] > 0)
		offset = -COLLISION_OFFSET;
	else
		offset = COLLISION_OFFSET;
	if (map[(int)(p->pos[X])][(int)(p->pos[Y] - dir[Y] + offset)] == false)
		p->pos[Y] -= dir[Y];
}

static void	ft_move_forward(t_player *p, char *map)
{
	int		offset;
	double	dir[2];

	dir[X] = p->dir[X] * MOVE_SPEED;
	dir[Y] = p->dir[Y] * MOVE_SPEED;
	if (dir[X] > 0)
		offset = COLLISION_OFFSET;
	else
		offset = -COLLISION_OFFSET;
	if (map[(int)(p->pos[X] + dir[X] + offset)][(int)p->pos[Y]] == false)
		p->pos[X] += dir[X];
	if (dir[Y] > 0)
		offset = COLLISION_OFFSET;
	else
		offset = -COLLISION_OFFSET;
	if (map[(int)p->pos[X]][(int)(p->pos[Y] + dir[Y] + offset)] == false)
		p->pos[Y] += dir[Y];
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_mlx		*g_mlx;
	t_player	*p;
	t_cube		*cube;
	char		**map;

	g_mlx = get_global_mlx();
	cube = (t_cube *)param;
	p = &cube->player;
	map = cube->map.matrix;
	if (keydata.key == ESC && keydata.action != 0)
		mlx_close_window(g_mlx->instance);
	else if (keydata.key == W && keydata.action != 0)
		ft_move_forward(p, map);
	else if (keydata.key == S && keydata.action != 0)
		ft_move_backward(p, map);
	else if ((keydata.key == A || keydata.key == D) && keydata.action != 0)
		ft_strafe(p, map, keydata.key);
	else if (keydata.key == LEFT_KEY && keydata.action != 0)
		ft_move_cam(p, map, ROT_SPEED);
	else if (keydata.key == RIGHT_KEY && keydata.action != 0)
		ft_move_cam(p, map, -ROT_SPEED);
}

//BONUS
void	cursor_hook(double xpos, double ypos, void *param)
{
	int	delta_x;
	t_cube	*cube;
	// REMEMBER TO INIT MOUSE X POS TO NEGATIVE NO WHEN GAME STARTS
	(void) ypos;
	cube = (t_cube *)param;
	if (cube->mouse_x < 0)
		cube->mouse_x = xpos;
	delta_x = xpos - cube->mouse_x;
	if (delta_x != 0)
		rotate_direction(cube->player, delta_x * MOUSE_SENSITIVITY);
	cube->mouse_x = xpos;
}