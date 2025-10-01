/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:25:48 by gangel-a          #+#    #+#             */
/*   Updated: 2025/09/30 22:52:44 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_move_cam()
{
	//this has to be angular"" a rotation
}

static void	ft_move_player(t_img *img, int x, int y)
{
	//remember to verify if a wall collision occurs!
	//move left and right
	img->player->instances[0].x = x;
	//move forward and back
	img->player->instances[0].y = y;
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_mlx *g_mlx;

	g_mlx = get_global_mlx();
	//figure out what params we will need
	t_img	*img;
	int		y;
	int		x;

	img = (t_img *)param;
	
	if (keydata.key == ESC && keydata.action != 0)
		mlx_close_window(g_mlx->instance);
	//  W A S D to move
	else if (keydata.key == W && keydata.action != 0)
		ft_move_player(img);
	else if (keydata.key == S && keydata.action != 0)
		ft_move_player(img);
	else if (keydata.key == A && keydata.action != 0)
		ft_move_player(img);
	else if (keydata.key == D && keydata.action != 0)
		ft_move_player(img);
	// left and right to look around	
	else if (keydata.key == LEFT_KEY && keydata.action != 0)
		ft_move_cam();
	else if (keydata.key == RIGHT_KEY && keydata.action != 0)
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
	(void) xpos;
	(void) ypos;
	(void) param;
}