/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 08:15:36 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/30 18:54:27 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_mlx *g_mlx;

	// validate agrs and file extension
	// init allocation for the game struct, map
	// ft_init_game();
	//parse
	ft_init_mlx();
	//init textures
	//render imgs
	g_mlx = get_global_mlx();
	mlx_loop(g_mlx->instance);
	mlx_terminate(g_mlx->instance);
	
	return (0);
}
