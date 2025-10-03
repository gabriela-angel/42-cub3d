/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:52:36 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/03 12:06:32 by lhenriqu         ###   ########.fr       */
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

static void	handle_generic_errors(t_error code)
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
		print_error("\tAllowed map characters: " C_YEL "01NSEW" C_RED ". ");
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

static void	handle_texture_miss(t_error code)
{
	if (code == E_TEX_NO_MISS)
		print_error("\tMissing texture path for South (NO).");
	else if (code == E_TEX_SO_MISS)
		print_error("\tMissing texture path for South (SO).");
	else if (code == E_TEX_WE_MISS)
		print_error("\tMissing texture path for West (WE).");
	else if (code == E_TEX_EA_MISS)
		print_error("\tMissing texture path for East (EA).");
	else if (code == E_F_MISS)
		print_error("\tMissing floor color.");
	else if (code == E_C_MISS)
		print_error("\tMissing ceiling color.");
}

static void	handle_texture_dup(t_error code)
{
	if (code == E_TEX_DUP)
		print_error("\tDuplicate texture path definition: ");
	else if (code == E_F_DUP)
		print_error("\tDuplicate floor color definition.");
	else if (code == E_C_DUP)
		print_error("\tDuplicate ceiling color definition.");
}

static void	handle_texture_file_errors(t_error code)
{
	if (code == E_NO_INV_EXT)
		print_error("\tNO texture file must be a " C_YEL ".png/.xpm" C_RED " file.");
	else if (code == E_SO_INV_EXT)
		print_error("\tSO texture file must be a " C_YEL ".png/.xpm" C_RED " file.");
	else if (code == E_WE_INV_EXT)
		print_error("\tWE texture file must be a " C_YEL ".png/.xpm" C_RED " file.");
	else if (code == E_EA_INV_EXT)
		print_error("\tEA texture file must be a " C_YEL ".png/.xpm" C_RED " file.");
	else if (code == E_NO_FILE)
		print_error("\tNO texture file could not be opened: ");
	else if (code == E_SO_FILE)
		print_error("\tSO texture file could not be opened: ");
	else if (code == E_WE_FILE)
		print_error("\tWE texture file could not be opened: ");
	else if (code == E_EA_FILE)
		print_error("\tEA texture file could not be opened: ");
}

static void	handle_map_errors(t_error code)
{
	handle_texture_miss(code);
	handle_texture_dup(code);
	handle_texture_file_errors(code);
	// handle_map_content_errors(code);
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