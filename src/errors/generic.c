/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:29:58 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/09 14:57:21 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_generic_errors(t_error code)
{
	if (code == E_INVALID_ARGS)
		print_error("\tUsage: ./cub3d <map.cub>");
	else if (code == E_INVALID_MAP_NAME)
		print_error("\tMap file must have a " C_YEL ".cub" C_RED " extension.");
	else if (code == E_EMPTY_MAP_FILE)
		print_error("\tMap file is empty.");
	else if (code == E_INVALID_FILE_CHAR)
		print_error("\tMap file contains no ASCII characters.");
	else if (code == E_EMPTY_MAP)
		print_error("\tWhere is the map? It's empty!");
	else if (code == E_INVALID_ELEMENT)
		print_error("\tMap file contains an invalid element: ");
	else if (code == E_INVALID_MAP_CHAR)
		print_flood_error("Map contains invalid character(s).");
	else if (code == E_MAP_NOT_LAST_ELEMENT)
		print_error("\tMap must be the last element in the file.");
	else if (code == E_OPEN_FAILED)
		print_error("\tFailed to open the map file.");
	else if (code == E_MLX_INIT_FAILED)
		print_error("\tFailed to initialize MLX.");
	else if (code == E_INVALID_RGB_VALUE)
		print_error("\tRGB color values must be in the range 0-255.");
	else if (code == E_INVALID_RGB_FIELDS)
		print_error("\tRGB color must have exactly 3 fields.");
}
