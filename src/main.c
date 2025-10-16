/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 08:15:36 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/16 19:17:07 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char *av[])
{
	t_mlx	*g_mlx;

	if (ac != 2)
		ft_error(E_INVALID_ARGS);
	// validate agrs and file extension, parse
	ft_init_map(av[1]);
	// init allocation for the game struct, map missing
	ft_init_mlx();
	ft_error(E_SUCCESS);
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
