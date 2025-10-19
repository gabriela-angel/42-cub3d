/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:32:15 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/19 01:46:05 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	player_positions(t_map *map, t_point **players)
{
	size_t	i;
	size_t	j;
	size_t	count;
	char	direction;

	i = 0;
	count = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (ft_strchr("NSEW", map->matrix[i][j]))
			{
				*players = ft_recalloc(*players, sizeof(t_point) * (count + 1));
				(*players)[count++] = (t_point){j, i};
				direction = map->matrix[i][j];
			}
			j++;
		}
		i++;
	}
	*players = ft_recalloc(*players, sizeof(t_point) * (count + 1));
	(*players)[count] = (t_point){-1, -1};
	return (direction);
}

static void	set_player(t_map *map, t_point position, char direction)
{
	t_player	*player;

	player = &get_global_cube()->player;
	player->pos[0] = (double)position.x + 0.5;
	player->pos[1] = (double)position.y + 0.5;
	player->dir[X] = 0;
	player->dir[Y] = 0;
	player->plane[X] = 0;
	player->plane[Y] = 0;
	if (direction == 'N')
		player->dir[Y] = -1;
	else if (direction == 'S')
		player->dir[Y] = 1;
	else if (direction == 'E')
		player->dir[X] = 1;
	else if (direction == 'W')
		player->dir[X] = -1;
}

static void	get_player(t_map *map)
{
	size_t	count;
	t_point	*players;
	char	direction;

	players = NULL;
	direction = player_positions(map, &players);
	count = 0;
	while (players[count].x != (size_t)-1)
		count++;
	gc_add(players);
	if (count == 0)
		ft_error(E_NO_PLAYER);
	if (count > 1)
	{
		count = 0;
		while (players[count].x != (size_t)-1)
		{
			add_flood_invalid_char(players[count]);
			count++;
		}
		ft_error(E_MULTIPLE_PLAYER);
	}
	set_player(map, players[0], direction);
	ft_free(players);
}

void	init_player(void)
{
	get_player(&get_global_cube()->map);
}
