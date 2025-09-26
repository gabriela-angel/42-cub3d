/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:17:56 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/09/25 21:07:43 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/MLX/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"

#include <fcntl.h>
#include <unistd.h>

// Error codes for the application
typedef enum e_error
{
	E_EMPTY_MAP = 1,
	E_OPEN_FAILED,
	E_INVALID_ARGS,
	E_MLX_INIT_FAILED,
	E_INVALID_MAP_NAME,
}			t_error;

// Constants for window dimensions
# define WIDTH 800
# define HEIGHT 600

typedef struct s_mlx
{
	mlx_t	*instance;
}			t_mlx;

t_mlx		*get_global_mlx(void);
void		ft_init_mlx(void);
void		ft_error(t_error code);

#endif
