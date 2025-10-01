/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:52:36 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/01 15:16:53 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void print_error(char *message)
{
	ft_printf_fd(2, C_RED C_BLD "Error: " C_RST C_RED "%s\n" C_RST, message);
}

void	ft_error(t_error code)
{
	if (code == E_MLX_INIT_FAILED)
		print_error("Failed to initialize MLX.");
	ft_map_destroy(get_global_cube()->map.textures.paths);
    ft_gc_clean_all();
	exit(EXIT_FAILURE);
}