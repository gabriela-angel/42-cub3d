/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:28:14 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/08 17:54:35 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_error_context(char *message)
{
	gc_add(message);
	get_global_cube()->error_context = message;
}

void	print_error(char *message)
{
	ft_printf_fd(2, C_RED "%s" C_RST, message);
	if (get_global_cube()->error_context)
		ft_printf_fd(2, C_YEL "%s" C_RST, get_global_cube()->error_context);
	ft_printf_fd(2, "\n");
}

void	ft_error(t_error code)
{
	t_cube	*cub;

	cub = get_global_cube();
	if (cub->map.fd)
		close_and_clear(&cub->map.fd);
	if (code > 0)
		ft_printf_fd(2, C_RED C_BLD "Error.\n" C_RST);
	handle_generic_errors(code);
	handle_map_errors(code);
	ft_map_destroy(get_global_cube()->map.textures.paths);
	if (get_global_mlx()->instance)
		mlx_terminate(get_global_mlx()->instance);
	terminate_gc();
	exit(code);
}
