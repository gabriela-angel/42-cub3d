/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:44:39 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/27 13:48:09 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_H
# define MLX_H

# include "../libs/MLX/include/MLX42/MLX42.h"

typedef struct s_mlx
{
	mlx_t	*instance;
}			t_mlx;

t_mlx		*get_global_mlx(void);
void		ft_init_mlx(void);

#endif
