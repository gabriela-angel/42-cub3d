/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:32:15 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/09 20:38:04 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_player
{
	t_point		position;
	char		direction;
}				t_player;

static t_point	*player_positions(t_map *map)
{
	size_t	i;
	size_t	j;
	size_t	count;
	t_point	*players;

	i = 0;
	count = 0;
	players = NULL;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (ft_strchr("NSEW", map->matrix[i][j]))
			{
				players = ft_recalloc(players, sizeof(t_point) * (count + 1));
				players[count] = (t_point){j, i};
				count++;
			}
			j++;
		}
		i++;
	}
	players = ft_recalloc(players, sizeof(t_point) * (count + 1));
	players[count] = (t_point){-1, -1};
	return (players);
}

static t_player	*get_player(t_map *map)
{
	size_t	count;
	t_point	*player_pos;

	player_pos = player_positions(map);
	count = 0;
	while (player_pos[count])
		count++;
	if (count == 0)
		ft_error(E_NO_PLAYER);
	if (count > 1)
	{
		ft_error(E_MULTIPLE_PLAYER);
	}
	ft_free(players);
}

void	init_player(void)
{
	get_player(&get_global_cube()->map);
}
