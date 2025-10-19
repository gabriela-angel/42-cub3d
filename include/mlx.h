/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:44:39 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/18 23:14:01 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_H
# define MLX_H

# include "../libs/MLX/include/MLX42/MLX42.h"

typedef struct s_mlx
{
	mlx_t		*instance;
	mlx_image_t	*img;
}			t_mlx;

t_mlx		*get_global_mlx(void);
void		ft_init_mlx(void);

// HOOKS
void		key_hook(mlx_key_data_t keydata, void *param);
void		cursor_hook(double x, double y, void *param);

#endif
