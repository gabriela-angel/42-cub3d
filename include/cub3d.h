/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:17:56 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/10/18 12:04:51 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/libft.h"
# include <math.h>
# include "error.h"
# include "map.h"
# include "mlx.h"
# include "player.h"
# include "settings.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

enum	e_axis
{
	X,
	Y
};

typedef struct s_cube
{
	t_map		map;
	t_player	player;
	int			mouse_x;
	char		*error_context;
}	t_cube;

typedef struct s_ray
{
	double	cam_x;
	int		map_pos[2];
	double	dir[2];
	double	side_dist[2];
	double	delta_dist[2];
	double	wall_dist;
	int step[2];
	int hit;
	int side;
	int line_height;
	int line_start;
	int line_end;
}	t_ray;


// CUBE
t_cube *get_global_cube(void);

// DRAW
void		draw_3d_map(void);
void		set_ray(t_player *player, t_ray *ray, int x);
void		dda(t_ray *ray, char **map);
void		calculate_wall_height(t_ray *ray);

// UTILS
uint32_t	rgb_to_int(char *str);
char	*trim(char *str);

#endif
