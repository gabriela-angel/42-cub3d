/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:25:48 by gangel-a          #+#    #+#             */
/*   Updated: 2025/10/18 20:36:27 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_mlx		*g_mlx;
	t_player	*p;
	t_cube		*cube;
	char		**map;

	g_mlx = get_global_mlx();
	cube = (t_cube *)param;
	p = &(cube->player);
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
		ft_rotate_cam(p, ROT_SPEED);
	else if (keydata.key == RIGHT_KEY && keydata.action != 0)
		ft_rotate_cam(p, -ROT_SPEED);
}

//BONUS
void	cursor_hook(double xpos, double ypos, void *param)
{
	double		delta_x;
	t_cube	*cube;
	(void) ypos;
	cube = (t_cube *)param;
	if (cube->mouse_x < 0)
		cube->mouse_x = xpos;
	delta_x = xpos - cube->mouse_x;
	if (delta_x != 0)
		ft_rotate_cam(&cube->player, delta_x * MOUSE_SENSITIVITY);
	cube->mouse_x = xpos;
}
