/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:17:56 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/09/23 22:24:43 by gangel-a         ###   ########.fr       */
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

// KEY BINDS
# define W MLX_KEY_W
# define A MLX_KEY_A
# define S MLX_KEY_S
# define D MLX_KEY_D
# define LEFT MLX_KEY_LEFT
# define RIGHT MLX_KEY_RIGHT
# define ESC MLX_KEY_ESCAPE
// missing mouse

typedef struct s_mlx
{
	mlx_t		*instance;
}			t_mlx;

t_mlx		*get_global_mlx(void);
void		ft_init_mlx(void);
void		ft_error(t_error code);

// HOOKS
void		key_hook(mlx_key_data_t keydata, void *param);
void		cursor_hook(double xpos, double ypos, void *param);


#endif
