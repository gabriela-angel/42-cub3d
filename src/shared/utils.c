/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 14:07:52 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/02 17:24:40 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*trim(char *str)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(str) - 1;
	while (str[start] == ' ' || str[start] == '\t')
		start++;
	while (end >= start && (str[end] == ' ' || str[end] == '\t'))
		end--;
	str[end + 1] = '\0';
	return (&str[start]);
}

static t_bool	is_valid_rgbs(char **rgb)
{
	int	i;
	int	value;

	i = 0;
	while (rgb[i])
	{
		value = ft_atoi(rgb[i]);
		if (value < 0 || value > 255)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

uint32_t	rgb_to_int(char *str)
{
	ssize_t		counter;
	uint32_t	color;
	char		**rgb;

	str[ft_strlen(str) - 1] = '\0';
	rgb = ft_split(str, ',');
	counter = 0;
	while (rgb && rgb[counter])
		counter++;
	if (counter != 3 || !is_valid_rgbs(rgb))
	{
		if (rgb)
			ft_free_matrix((void **)rgb, free);
		ft_error(E_INVALID_RGB);
	}
	color = (ft_atoi(rgb[0]) << 24) | (ft_atoi(rgb[1]) << 16) | (ft_atoi(rgb[2]) << 8) | 0xFF;
	ft_free_matrix((void **)rgb, free);
	return (color);
}
