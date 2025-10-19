/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:17:56 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/10/18 22:15:41 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/libft.h"
# include <math.h>
# include "mlx.h"
# include "player.h"
# include "raycaster.h"
# include "map.h"
# include "error.h"
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
	char		*error_context;
}	t_cube;

// CUBE
t_cube *get_global_cube(void);

// UTILS
uint32_t	rgb_to_int(char *str);
char		*trim(char *str);

#endif
