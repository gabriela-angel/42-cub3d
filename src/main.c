/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 08:15:36 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/16 19:02:11 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_mlx	*g_mlx;

	// validate agrs and file extension
	// init allocation for the game struct, map
	//parse
	ft_init_mlx();
	// ft_init_cube();
	//init textures
	//render imgs
	//this includes the draw_3d_map() function
	g_mlx = get_global_mlx();
	mlx_key_hook(g_mlx->instance, key_hook, get_global_cube());
	mlx_cursor_hook(g_mlx->instance, cursor_hook, get_global_cube());
	mlx_loop(g_mlx->instance);
	mlx_terminate(g_mlx->instance);
	
	return (0);
}
