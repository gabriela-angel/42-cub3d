/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:39:31 by gangel-a          #+#    #+#             */
/*   Updated: 2025/10/21 09:37:50 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_ceiling_and_floor(t_map_textures *m_tex, t_ray *ray, int x)
{
	int			y;
	mlx_image_t	*img;

	y = 0;
	img = get_global_mlx()->img;
	// DEBUG
	if (ray->line_start < 0 || ray->line_start > HEIGHT || ray->line_end < 0 || ray->line_end > HEIGHT)
	{
		printf("Wall dist: %f\n", ray->wall_dist);
		printf("Line start: %d, line end: %d\n", ray->line_start, ray->line_end);
	}
	while (y < ray->line_start)
	{
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

void	draw_3d_map(void)
{
	int			x;
	t_ray		ray;
	t_player	player;

	x = 0;
	player = get_global_cube()->player;
	ft_bzero(&ray, sizeof(t_ray));
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
