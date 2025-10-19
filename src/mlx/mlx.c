/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:45:32 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/18 23:01:07 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_mlx(void)
{
	t_mlx	*g_mlx;

	g_mlx = get_global_mlx();
	g_mlx->instance = mlx_init(WIDTH, HEIGHT, "Cub3d", false);
	if (!g_mlx->instance)
		ft_error(E_MLX_INIT_FAILED);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	g_mlx->img = mlx_new_image(g_mlx->instance, WIDTH, HEIGHT);
	if (!g_mlx->img || mlx_image_to_window(g_mlx->instance, g_mlx->img, 0, 0) < 0)
		ft_error(E_MLX_IMG_INIT_FAILED);
}
