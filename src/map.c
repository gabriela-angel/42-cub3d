/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:17:01 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/25 20:08:24 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map(char *file)
{
	char	*tmp;
	int		fd;

	if (ft_strcmp(file + ft_strlen(file) - 4, ".cub") != 0)
		ft_error(E_INVALID_MAP_NAME);
	fd = open(file, O_RDONLY);
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
