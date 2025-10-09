/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:12:52 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/08 21:48:33 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_nl_address(const char *s)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == '\n')
			return ((char *)s);
		s++;
	}
	return (NULL);
}

void	close_and_clear(int *fd)
{
	if (fd && *fd >= 0 && *fd < FD_MAX)
	{
		clear_gnl_buffer(*fd);
		close(*fd);
		gc_destroy_ctx(get_gnl_ctx(*fd));
		clear_gnl_ctx(*fd);
		*fd = 0;
	}
}

void	clear_gnl_buffer(int fd)
{
	char	**buffer;
	int		i;

	buffer = get_gnl_buffer();
	if (fd >= 0 && fd < FD_MAX)
	{
		if (buffer[fd])
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
		}
	}
	if (fd == CLEAR_ALL)
	{
		i = 0;
		while (i < FD_MAX)
		{
			if (buffer[i])
			{
				free(buffer[i]);
				buffer[i] = NULL;
			}
			i++;
		}
	}
}

char	**get_gnl_buffer(void)
{
	static char	*buffer[FD_MAX];

	return ((char **)buffer);
}
