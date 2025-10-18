/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 08:15:36 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/18 14:35:50 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_mouse(void)
{
	t_cube	*cube;

	cube = get_global_cube();
	cube->mouse_x = -1;
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
	ft_render_img();
	g_mlx = get_global_mlx();
	mlx_key_hook(g_mlx->instance, key_hook, get_global_cube());
	//BONUS: mouse movement
	mlx_cursor_hook(g_mlx->instance, cursor_hook, get_global_cube());
	mlx_loop(g_mlx->instance);
	ft_error(E_SUCCESS);
	
	return (0);
}
