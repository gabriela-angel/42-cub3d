/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:28:14 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/03 13:30:57 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_error_context(char *message)
{
	ft_gc_add(message);
	get_global_cube()->error_context = message;
}

static void	print_error(char *message)
{
	ft_printf_fd(2, C_RED "%s" C_RST, message);
	if (get_global_cube()->error_context)
		ft_printf_fd(2, C_YEL "%s" C_RST, get_global_cube()->error_context);
	ft_printf_fd(2, "\n");
}

void	ft_error(t_error code)
{
	ft_printf_fd(2, C_RED C_BLD "Error.\n" C_RST);
	handle_generic_errors(code);
	handle_map_errors(code);
	ft_map_destroy(get_global_cube()->map.textures.paths);
	ft_gc_clean_all();
	exit(EXIT_FAILURE);
}
