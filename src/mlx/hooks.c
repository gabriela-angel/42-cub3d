/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:25:48 by gangel-a          #+#    #+#             */
/*   Updated: 2025/10/20 16:02:17 by gangel-a         ###   ########.fr       */
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
	{
		printf("Key pressed: %d\n", keydata.key);
		ft_move_forward(p, map);
	}
	else if (keydata.key == S && keydata.action != 0)
		ft_move_backward(p, map);
	else if ((keydata.key == A || keydata.key == D) && keydata.action != 0)
		ft_strafe(p, map, keydata.key);
	else if (keydata.key == LEFT_KEY && keydata.action != 0)
		ft_rotate_cam(p, -ROT_SPEED);
	else if (keydata.key == RIGHT_KEY && keydata.action != 0)
		ft_rotate_cam(p, ROT_SPEED);
}

//BONUS
void	cursor_hook(double xpos, double ypos, void *param)
{
	double		angle;
	t_cube		*cube;

	cube = (t_cube *)param;
	(void) ypos;
	angle = xpos - (WIDTH / 2);
	if (fabs(angle) > 0.5)
		ft_rotate_cam(&cube->player, angle * MOUSE_SENSITIVITY);
	mlx_set_mouse_pos(get_global_mlx()->instance, WIDTH / 2, HEIGHT / 2);
}

// void	cursor_hook(void *param)
// {
// 	double		angle;
// 	t_cube		*cube;
// 	int			mouse_pos[2];

// 	cube = (t_cube *)param;
// 	mlx_get_mouse_pos(get_global_mlx()->instance, &mouse_pos[X], &mouse_pos[Y]);
// 	angle = mouse_pos[X] - (WIDTH / 2);
// 	if (fabs(angle) > 0.5)
// 		ft_rotate_cam(&cube->player, angle * MOUSE_SENSITIVITY);
// 	mlx_set_mouse_pos(get_global_mlx()->instance, WIDTH / 2, HEIGHT / 2);
// }
