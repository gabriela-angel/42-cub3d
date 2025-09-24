/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:45:32 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/23 22:23:12 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_mlx(void)
{
	t_mlx *g_mlx;

	g_mlx = get_global_mlx();
	g_mlx->instance = mlx_init(WIDTH, HEIGHT, "Cub3d", false);
	if (!g_mlx->instance)
		ft_error(E_MLX_INIT_FAILED);

	// only for test purpose, but we gotta start the images
	mlx_image_t	*img;
	img = mlx_new_image(g_mlx->instance, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(g_mlx->instance, img, 0, 0) < 0))
		ft_error(1);

	// ok now this we maintain
	mlx_key_hook(g_mlx->instance, key_hook, NULL);
	mlx_cursor_hook(g_mlx->instance, cursor_hook, NULL);

	return ;
}
