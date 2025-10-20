/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:05:28 by gangel-a          #+#    #+#             */
/*   Updated: 2025/10/20 12:50:48 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player_pos_dir(t_player *p, char **m, int x_pos, int y_pos)
{
	p->pos[X] = x_pos + 0.5;
	p->pos[Y] = y_pos + 0.5;
	if (m[y_pos][x_pos] == 'N')
	{
		p->dir[Y] = -1;
		p->plane[X] = 0.66;
	}
	else if (m[y_pos][x_pos] == 'S')
	{
		p->dir[Y] = 1;
		p->plane[X] = -0.66;
	}
	else if (m[y_pos][x_pos] == 'E')
	{
		p->dir[X] = 1;
		p->plane[Y] = 0.66;
	}
	else if (m[y_pos][x_pos] == 'W')
	{
		p->dir[X] = -1;
		p->plane[Y] = -0.66;
	}
	return ;
}

void	ft_init_player(void)
{
	t_player	*player;
	t_map		*map;
	int			x_pos;
	int			y_pos;

	player = &get_global_cube()->player;
	map = &get_global_cube()->map;
	ft_bzero(player, sizeof(t_player));
	x_pos = 0;
	while ((size_t)x_pos < map->height)
	{
		y_pos = 0;
		while ((size_t)y_pos < map->width)
		{
			if (ft_strchr("NSEW", map->matrix[y_pos][x_pos]))
			{
				set_player_pos_dir(player,  map->matrix, x_pos, y_pos);
				return ;
			}
			y_pos++;
		}
		x_pos++;
	}
}
