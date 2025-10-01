/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:39:10 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/27 13:40:23 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	valid_map_path(char *map_path)
{
	char	*tmp;
	int		fd;

	if (ft_strcmp(map_path + ft_strlen(map_path) - 4, ".cub") != 0)
		ft_error(E_INVALID_MAP_NAME);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		ft_error(E_OPEN_FAILED);
	tmp = get_next_line(fd);
	if (!tmp)
	{
		close(fd);
		ft_error(E_EMPTY_MAP);
	}
	free(tmp);
	close_and_clear(fd);
}
