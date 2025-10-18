/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:45:32 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/18 14:06:12 by gangel-a         ###   ########.fr       */
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
	g_mlx->img = NULL;
}
