/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:29:18 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/08 15:21:20 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gc.h"
#include "ft_gc_utils.h"

t_ctx	*get_ctx_list(void)
{
	static t_ctx	ctx_list;

	return (&ctx_list);
}

void	terminate_gc(void)
{
	t_ptrs_list	*ptrs;

	ptrs = get_ctx_list()->ptrs;
	while (ptrs)
	{
		gc_destroy_ctx((t_ctx *)ptrs->ptr);
		ptrs = ptrs->next;
	}
	get_ctx_list()->ptrs = NULL;
	get_ctx_list()->list_size = 0;
	gc_clean_all();
}
