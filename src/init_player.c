/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:05:28 by gangel-a          #+#    #+#             */
/*   Updated: 2025/10/16 22:06:44 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	set_player_pos_dir(int x_pos, int y_pos)
{
	t_player	*player;
	t_map		*map;
	
	player = &get_global_cube()->player;
	map = &get_global_cube()->map;
	if (ft_strchr("NSEW", map->matrix[x_pos][y_pos]))
	{
		player->pos[X] = x_pos + 0.5;
		player->pos[Y] = y_pos + 0.5;
		if (map->matrix[x_pos][y_pos] == 'N')
			player->dir[Y] = -1;
		else if (map->matrix[x_pos][y_pos] == 'S')
			player->dir[Y] = 1;
		else if (map->matrix[x_pos][y_pos] == 'E')
			player->dir[X] = 1;
		else if (map->matrix[x_pos][y_pos] == 'W')
			player->dir[X] = -1;
		return (TRUE);
	}
	return (FALSE);
}

void	ft_init_player(void)
{
	t_player	*player;
	t_map		*map;
	int			x_pos;
	int			y_pos;

	player = &get_global_cube()->player;
	map = &get_global_cube()->map;
	player->plane[X] = 0;
	player->plane[Y] = 0.66;
	player->dir[X] = 0;
	player->dir[Y] = 0;
	x_pos = 0;
	while (x_pos < map->height)
	{
		y_pos = 0;
		while (y_pos < map->width)
		{
			if (set_player_pos_dir(x_pos, y_pos))
				return ;
			y_pos++;
		}
		x_pos++;
	}
}