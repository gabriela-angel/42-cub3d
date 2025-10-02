/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:52:36 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/02 16:47:25 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void add_error_context(char *message)
{
	t_cube	*cube;

	cube = get_global_cube();
	if (cube->error_context)
		free(cube->error_context);
	cube->error_context = message;
}

static void print_error(char *message)
{
	ft_printf_fd(2, C_RED C_BLD "Error: " C_RST C_RED "%s\n" C_RST, message);
}

void	ft_error(t_error code)
{
	print_error("Error.");
	if (code == E_MLX_INIT_FAILED)
		print_error("Failed to initialize MLX.");
	ft_map_destroy(get_global_cube()->map.textures.paths);
    ft_gc_clean_all();
	exit(EXIT_FAILURE);
}