/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 16:06:24 by gangel-a          #+#    #+#             */
/*   Updated: 2025/10/18 20:24:22 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// This function returns the texture that will be used based on the side hit
static t_texture	*get_side_texture(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir[X] > 0)
			return (ft_map_search(map->textures.paths, "EA")); //find where these are defined
		return (ft_map_search(map->textures.paths, "WE"));
	}
	else
	{
		if (ray->dir[Y] > 0)
			return (ft_map_search(map->textures.paths, "SO"));
		return (ft_map_search(map->textures.paths, "NO"));
	}
}

static int	define_tex_x(t_texture *tex, t_player *player, t_ray *ray)
{
	double		wall_x;
	int			tex_x;
	
	if (ray->side == 0)
		wall_x = player->pos[Y] + ray->wall_dist * ray->dir[Y];
	else
		wall_x = player->pos[X] + ray->wall_dist * ray->dir[X];
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)(tex->width));
	if (ray->side == 0 && ray->dir[X] > 0)
		tex_x = tex->width - tex_x - 1;
	if (ray->side == 1 && ray->dir[Y] < 0)
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

static uint32_t	get_px_color(t_texture *tex, int x, int y)
{
	uint8_t	*pixel_addr;
	uint32_t	color;

	color = *(int *)(tex->tex_addr + y * tex->line_size + x * (tex->bpp / 8));
	return (color);
}

void	draw_textures(t_player *player, t_ray *ray, int x)
{
	t_texture	*tex;
	int			y;
	int			tex_pos[2];
	double		step;
	double		curr_tex_pos;

	tex = get_side_texture(ray);
	tex_pos[X] = define_tex_x(tex, player, ray);
	step = 1.0 * tex->height / ray->line_height;
	//tbh from here on it is kinda confusing
	curr_tex_pos = (ray->line_start - HEIGHT / 2 + ray->line_height / 2) * step;
	y = ray->line_start;
	while (y < ray->line_end)
	{
		tex_pos[Y] = (int)curr_tex_pos & (tex->height - 1);
		curr_tex_pos += step;
		mlx_put_pixel(get_global_mlx()->img, x, y, get_px_color(tex, tex_pos[X], tex_pos[Y]));
		y++;
	}
}
