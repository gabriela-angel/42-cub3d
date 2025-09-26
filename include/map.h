/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 21:15:06 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/25 21:16:19 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "cub3d.h"

typedef struct s_map
{
	int			start_map;
	size_t		height;
	size_t		width;
	char		*name;
	int			fd;
	int			**matrix;
}				t_map;

typedef struct s_file
{
	uint32_t	floor;
	uint32_t	ceiling;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
}				t_file;

void			ft_init_map(char *name);

#endif
