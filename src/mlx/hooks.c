/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:25:48 by gangel-a          #+#    #+#             */
/*   Updated: 2025/10/21 17:29:17 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	key_hook(mlx_key_data_t keydata, void *param)
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
	if (keydata.key == W && keydata.action != 0)
		ft_move_forward(p, map);
	if (keydata.key == S && keydata.action != 0)
		ft_move_backward(p, map);
	if (keydata.key == A && keydata.action != 0)
		ft_strafe_left(p, map);
	if (keydata.key == D && keydata.action != 0)
		ft_strafe_right(p, map);
	if (keydata.key == LEFT_KEY && keydata.action != 0)
		ft_rotate_cam(p, -ROT_SPEED);
	if (keydata.key == RIGHT_KEY && keydata.action != 0)
		ft_rotate_cam(p, ROT_SPEED);
}

// BONUS
static void	cursor_hook(double xpos, double ypos, void *param)
{
	double	angle;
	t_cube	*cube;
	mlx_t	*g_mlx;

	g_mlx = get_global_mlx()->instance;
	cube = (t_cube *)param;
	(void)ypos;
	angle = xpos - (WIDTH / 2);
	if (fabs(angle) > 0.5)
		ft_rotate_cam(&cube->player, angle * MOUSE_SENSITIVITY);
	mlx_set_mouse_pos(g_mlx, WIDTH / 2, HEIGHT / 2);
}

static void	main_loop(void *param)
{
	(void)param;
	draw_3d_map();
}

void	set_mlx_hooks(void)
{
	mlx_t	*g_mlx;

	g_mlx = get_global_mlx()->instance;
	mlx_set_cursor_mode(g_mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(g_mlx, WIDTH / 2, HEIGHT / 2);
	mlx_key_hook(g_mlx, key_hook, get_global_cube());
	mlx_cursor_hook(g_mlx, cursor_hook, get_global_cube());
	mlx_loop_hook(g_mlx, main_loop, get_global_cube());
}
