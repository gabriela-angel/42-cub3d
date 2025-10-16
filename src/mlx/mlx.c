/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:45:32 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/16 19:13:26 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// TEST PURPOSE
// void	ft_init_cube(void)
// {
	//this would be to allocate all we need before starting
	// first of all, we have to get the map dimensions
	// then start the map struct with all dimensions + map read
	
	// we have to start the player struct
	// t_player *player;

	// player = (t_player *)ft_gc_malloc(1 * sizeof(t_player));
	// player->pos[X] = 22;
	// player->pos[Y] = 12;
	// player->dir[X] = -1;
	// player->dir[Y] = 0;
	// player->plane[X] = 0;
	// player->plane[Y] = 0.66;
// }

void	ft_init_mlx(void)
{
	t_mlx	*g_mlx;

	g_mlx = get_global_mlx();
	g_mlx->instance = mlx_init(WIDTH, HEIGHT, "Cub3d", false);
	if (!g_mlx->instance)
		ft_error(E_MLX_INIT_FAILED);
}
