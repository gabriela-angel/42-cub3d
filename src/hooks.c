/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:25:48 by gangel-a          #+#    #+#             */
/*   Updated: 2025/09/23 22:26:47 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_mlx *g_mlx;

	g_mlx = get_global_mlx();
	if (keydata.os_key == ESC && keydata.action != 0)
		mlx_close_window(g_mlx->instance);
	//  W A S D to move
	else if (keydata.key == W && keydata.action != 0)
		ft_move_player();
	else if (keydata.key == S && keydata.action != 0)
		ft_move_player();
	else if (keydata.key == A && keydata.action != 0)
		ft_move_player();
	else if (keydata.key == D && keydata.action != 0)
		ft_move_player();
	// left and right to look around	
	else if (keydata.key == LEFT && keydata.action != 0)
		ft_move_cam();
	else if (keydata.key == RIGHT && keydata.action != 0)
		ft_move_cam();
}

//BONUS
void	cursor_hook(double xpos, double ypos, void *param)
{
	// Parameters:
	// 	xpos – [in] The mouse x position.
	// 	ypos – [in] The mouse y position.
	// 	param – [in] Additional parameter to pass on to the function.

	// if the ypos changes, we have to rotate the cam
}
