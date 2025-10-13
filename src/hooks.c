/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:25:48 by gangel-a          #+#    #+#             */
/*   Updated: 2025/10/12 23:07:47 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_rotate_cam()
{
	double oldDirX = dirX;
	dirX = dirX * cos(-COLLISION_OFFSET) - dirY * sin(-COLLISION_OFFSET);
	dirY = oldDirX * sin(-COLLISION_OFFSET) + dirY * cos(-COLLISION_OFFSET);
	double oldPlaneX = planeX;
	planeX = planeX * cos(-COLLISION_OFFSET) - planeY * sin(-COLLISION_OFFSET);
	planeY = oldPlaneX * sin(-COLLISION_OFFSET) + planeY * cos(-COLLISION_OFFSET);

	double oldDirX = dirX;
	dirX = dirX * cos(COLLISION_OFFSET) - dirY * sin(COLLISION_OFFSET);
	dirY = oldDirX * sin(COLLISION_OFFSET) + dirY * cos(COLLISION_OFFSET);
	double oldPlaneX = planeX;
	planeX = planeX * cos(COLLISION_OFFSET) - planeY * sin(COLLISION_OFFSET);
	planeY = oldPlaneX * sin(COLLISION_OFFSET) + planeY * cos(COLLISION_OFFSET);
}

// UNDERSTAND THIS BETTER
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
	char		**map;

	g_mlx = get_global_mlx();
	p = &get_global_cube()->player;
	map = get_global_cube()->map.matrix;
	if (keydata.key == ESC && keydata.action != 0)
		mlx_close_window(g_mlx->instance);
	else if (keydata.key == W && keydata.action != 0)
		ft_move_forward(p, map);
	else if (keydata.key == S && keydata.action != 0)
		ft_move_backward(p, map);
	else if ((keydata.key == A || keydata.key == D) && keydata.action != 0)
		ft_strafe(p, map, keydata.key);
	else if (keydata.key == LEFT_KEY && keydata.action != 0)
		ft_move_cam();
	else if (keydata.key == RIGHT_KEY && keydata.action != 0)
		ft_move_cam();
}

//BONUS
void	cursor_hook(double xpos, double ypos, void *param)
{
	// Parameters:
	// 	xpos – [in] The mouse x position.
	// 	ypos – [in] The mouse y position.
	// 	param – [in] Additional parameter to pass on to the function.

	// if the ypos changes, we have to rotate the cam
	(void) xpos;
	(void) ypos;
	(void) param;
}