/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 08:15:36 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/21 00:47:46 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
