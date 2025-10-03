/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:28:47 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/03 13:32:54 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		print_error("\tNO texture file must be a "
			C_YEL ".png/.xpm" C_RED " file.");
	else if (code == E_SO_INV_EXT)
		print_error("\tSO texture file must be a "
			C_YEL ".png/.xpm" C_RED " file.");
	else if (code == E_WE_INV_EXT)
		print_error("\tWE texture file must be a "
			C_YEL ".png/.xpm" C_RED " file.");
	else if (code == E_EA_INV_EXT)
		print_error("\tEA texture file must be a "
			C_YEL ".png/.xpm" C_RED " file.");
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
