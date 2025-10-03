/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:17:56 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/10/03 11:00:36 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/libft.h"
# include "error.h"
# include "map.h"
# include "mlx.h"
# include "settings.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_cube
{
	t_map		map;
	char		*error_context;
}	t_cube;

t_cube *get_global_cube(void);
uint32_t	rgb_to_int(char *str);
char	*trim(char *str);

#endif
