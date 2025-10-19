/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 08:15:36 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/18 23:14:56 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	main_loop(void *param)
{
	// t_mlx		*g_mlx;
	// t_cube		*cube;
	
	// g_mlx = get_global_mlx()->instance;
	// cube = (t_cube *)param;
	// //BONUS: mouse movement
	// mlx_cursor_hook(g_mlx, cursor_hook, cube);
	(void)param;
	draw_3d_map();
}

void	set_mlx_hooks(void)
{
	mlx_t	*g_mlx;

	g_mlx = get_global_mlx()->instance;
	mlx_set_cursor_mode(g_mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(get_global_mlx()->instance, WIDTH / 2, HEIGHT / 2);
	mlx_key_hook(g_mlx, key_hook, get_global_cube());
	//BONUS: mouse movement
	mlx_cursor_hook(g_mlx, cursor_hook, get_global_cube());
	mlx_loop_hook(g_mlx, main_loop, get_global_cube());
}

int	main(int ac, char *av[])
{
	t_mlx	*g_mlx;

	if (ac != 2)
		ft_error(E_INVALID_ARGS);
	ft_init_map(av[1]);
	ft_init_mlx();
	ft_init_player();
	ft_init_textures(&(get_global_cube()->map.textures));
	g_mlx = get_global_mlx();
	set_mlx_hooks();
	mlx_loop(g_mlx->instance);
	ft_error(E_SUCCESS);
	
	return (0);
}
