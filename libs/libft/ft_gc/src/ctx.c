/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 20:05:19 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/08 15:41:23 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gc.h"

t_ctx	*gc_create_ctx(t_bool auto_managed)
{
	t_ctx	*new_ctx;

	new_ctx = malloc(sizeof(t_ctx));
	if (!new_ctx)
		return (NULL);
	new_ctx->ptrs = NULL;
	new_ctx->list_size = 0;
	if (auto_managed)
		gc_add_ctx(get_ctx_list(), new_ctx);
	return (new_ctx);
}

void	gc_destroy_ctx(t_ctx *ctx)
{
	gc_clean_all_ctx(ctx);
	gc_free_ctx(get_ctx_list(), (void *)ctx);
}
