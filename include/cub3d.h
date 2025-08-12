/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:17:56 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/08/11 22:04:50 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/MLX/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"

// Error codes for the application
typedef enum e_error
{
	E_MLX_INIT_FAILED,
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
