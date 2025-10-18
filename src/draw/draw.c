/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:39:31 by gangel-a          #+#    #+#             */
/*   Updated: 2025/10/18 20:34:37 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_ceiling_and_floor(t_map_textures *m_tex, t_ray *ray, int x)
{
	int	y;
	mlx_image_t	*img;

	y = 0;
	img = get_global_mlx()->img;
	while (y < ray->line_start)
	{
		// INTERPOLATE COLORS FOR A SMOOTH TRANSITION - NOT DONE YET
		mlx_put_pixel(img, x, y, m_tex->ceiling);
		y++;
	}
	y = ray->line_end;
	while (y < HEIGHT)
	{
		mlx_put_pixel(img, x, y, m_tex->floor);
		y++;
	}
}

static void	draw_3d_map()
{
	int			x;
	t_ray		ray;
	t_player	player;

	x = 0;
	player = get_global_cube()->player;
	while (x < WIDTH)
	{
		set_ray(&player, &ray, x);
		dda(&ray, get_global_cube()->map.matrix);
		calculate_wall_height(&ray);
		draw_textures(&player, &ray, x);
		draw_ceiling_and_floor(&(get_global_cube()->map.textures), &ray, x);
		x++;
	}
}

void	ft_render_img(void)
{
	t_mlx	*mlx;

	mlx = get_global_mlx();
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx->img = mlx_new_image(mlx->instance, WIDTH, HEIGHT);
	if (!mlx->img || mlx_image_to_window(mlx->instance, mlx->img, 0, 0) < 0)
		ft_error(E_MLX_IMG_INIT_FAILED);
	draw_3d_map();
}