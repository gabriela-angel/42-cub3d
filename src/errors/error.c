/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:28:14 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/18 23:27:48 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_error_context(char *message)
{
	ft_gc_add(message);
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
	int	i;

	i = -1;
	if (code > 0)
		ft_printf_fd(2, C_RED C_BLD "Error.\n" C_RST);
	handle_generic_errors(code);
	handle_map_errors(code);
	ft_map_destroy(get_global_cube()->map.textures.paths);
	while (++i < 4)
		if (get_global_cube()->map.textures.tex_arr[i])
			mlx_delete_texture(get_global_cube()->map.textures.tex_arr[i]);
	if (get_global_mlx()->img)
		mlx_delete_image(get_global_mlx()->instance, get_global_mlx()->img);
	if (get_global_mlx()->instance)
		mlx_terminate(get_global_mlx()->instance);
	ft_gc_clean_all();
	if (code == E_SUCCESS)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}
