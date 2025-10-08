/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:31:54 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/08 15:44:25 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_ctx	**get_gnl_ctx_list(void)
{
	static t_ctx	*ctx_list[FD_MAX];

	return ((t_ctx **)ctx_list);
}

t_ctx	*get_gnl_ctx(int fd)
{
	t_ctx	**ctx_list;

	ctx_list = get_gnl_ctx_list();
	if (fd < 0 || fd >= FD_MAX)
		return (NULL);
	if (ctx_list[fd] == NULL)
		ctx_list[fd] = gc_create_ctx(FALSE);
	return (ctx_list[fd]);
}
