/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:45:32 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/30 18:55:35 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// TEST PURPOSE ONLY
static int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

// TEST PURPOSE ONLY
static void ft_randomize(void* param)
{
	mlx_image_t* image;
	
	image = param;
	for (uint32_t i = 0; i < image->width; ++i)
	{
		for (uint32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				0xFF, // R
				0x00, // G
				0xff, // B
				0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

// TEST PURPOSE ONLY
t_img	*start_img()
{
	t_img *img;
	t_mlx *g_mlx;

	g_mlx = get_global_mlx();
	
	img->bg = mlx_new_image(g_mlx->instance, WIDTH, HEIGHT);
	if (!img->bg || (mlx_image_to_window(g_mlx->instance, img->bg, 0, 0) < 0))
		ft_error(1);

	//now for this part, in the actual project we have to init the textures
	// for now I only added 2 rectangles
	img->rect_1 = mlx_new_image(g_mlx->instance, 100, 100);
	if (!img->rect_1 || (mlx_image_to_window(g_mlx->instance, img->rect_1, 200, 230) < 0))
		ft_error(1);
	img->rect_2 = mlx_new_image(g_mlx->instance, 100, 100);
	if (!img->rect_2 || (mlx_image_to_window(g_mlx->instance, img->rect_2, 500, 230) < 0))
		ft_error(1);

	// img hooks, wee might have to move elsewhere
	mlx_loop_hook(g_mlx->instance, ft_randomize, img->rect_1);
	mlx_loop_hook(g_mlx->instance, ft_randomize, img->rect_2);

	return img;
}
// TEST PURPOSE
// void	ft_init_game(void)
// {
	//this would be to allocate all we need before starting
	// first of all, we have to get the map dimensions
	// then start the map struct with all dimensions + map read
	
	// we have to start the player struct
	// will we have to allocate memory?
// 	t_player *player;
// 	player = 
// }

void	ft_init_mlx(void)
{
	t_mlx *g_mlx;

	g_mlx = get_global_mlx();
	g_mlx->instance = mlx_init(WIDTH, HEIGHT, "Cub3d", false);
	if (!g_mlx->instance)
		ft_error(E_MLX_INIT_FAILED);

	// only for test purpose, but we gotta start the images
	t_img *img;
	img = start_img();

	//here we render imgs
	// inside this function just for now, must move outside later
	draw_3d_map();
	
	// ok now this we maintain, but this "img" param is unsure
	// we might need to move this part outside of this func
	mlx_key_hook(g_mlx->instance, key_hook, img);
	mlx_cursor_hook(g_mlx->instance, cursor_hook, img);

	return ;
}
