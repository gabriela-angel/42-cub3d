/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:32:15 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/18 13:32:25 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_player
{
	t_point		position;
	char		direction;
}				t_player;

static void	player_positions(t_map *map, t_point **players)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	count = 0;
	*players = NULL;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (ft_strchr("NSEW", map->matrix[i][j]))
			{
				*players = ft_recalloc(*players, sizeof(t_point) * (count + 1));
				(*players)[count] = (t_point){j, i};
				count++;
			}
			j++;
		}
		i++;
	}
	*players = ft_recalloc(*players, sizeof(t_point) * (count + 1));
	(*players)[count] = (t_point){-1, -1};
}

static void get_player(t_map *map)
{
	size_t		count;
	t_point		*players;

	player_positions(map, &players);
	count = 0;
	while (players[count].x != (size_t)-1)
		count++;
	if (count == 0)
		ft_error(E_NO_PLAYER);
	if (count > 1)
	{
		gc_add(players);
		count = 0;
		while (players[count].x != (size_t)-1)
		{
			add_flood_invalid_char(players[count]);
			count++;
		}
		ft_error(E_MULTIPLE_PLAYER);
	}
	// Set player position and direction
	// plauyers[0] is the only player position
	ft_free(players);
}

void	init_player(void)
{
	get_player(&get_global_cube()->map);
}
