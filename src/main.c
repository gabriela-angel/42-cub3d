/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 08:15:36 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/18 12:37:54 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_mouse(void)
{
	t_cube	*cube;

	cube = get_global_cube();
	cube->mouse_x = -1;
}

void	ft_render_img(void)
{
	t_mlx	*mlx;

	mlx = get_global_mlx();
	mlx->img = mlx_new_image(mlx->instance, WIDTH, HEIGHT);
	if (!mlx->img || mlx_image_to_window(mlx->instance, mlx->img, 0, 0) < 0)
		ft_error(E_MLX_IMG_INIT_FAILED);
	draw_3d_map();
}

int	main(int ac, char *av[])
{
	t_mlx	*g_mlx;

	if (ac != 2)
		ft_error(E_INVALID_ARGS);
	ft_init_map(av[1]);
	ft_init_mlx();
	ft_init_player();
	// BONUS: mouse movement
	ft_init_mouse();
	ft_render_img();	//this includes the draw_3d_map() function, NOT DONE YET
	g_mlx = get_global_mlx();
	mlx_key_hook(g_mlx->instance, key_hook, get_global_cube());
	//BONUS: mouse movement
	mlx_cursor_hook(g_mlx->instance, cursor_hook, get_global_cube());
	mlx_loop(g_mlx->instance);
	mlx_terminate(g_mlx->instance);
	ft_error(E_SUCCESS);
	
	return (0);
}
