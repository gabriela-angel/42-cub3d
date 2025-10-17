/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:05:14 by gangel-a          #+#    #+#             */
/*   Updated: 2025/10/16 23:08:48 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "../libs/MLX/include/MLX42/MLX42.h"

typedef struct s_player
{
	double	pos[2];
	double	dir[2];
	double	plane[2];
}	t_player;

// PLAYER
void		ft_init_player(void);

// MOVEMENT
void		ft_move_forward(t_player *p, char **map);
void		ft_move_backward(t_player *p, char **map);
void		ft_strafe(t_player *p, char **map, keys_t key);
void		ft_rotate_cam(t_player *p, double rot_speed);

#endif