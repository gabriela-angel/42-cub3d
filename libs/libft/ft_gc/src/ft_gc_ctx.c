/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_ctx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:38:00 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/08 15:18:19 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gc.h"
#include "ft_gc_utils.h"

static t_ctx	*get_global_ctx(void)
{
	static t_ctx	g_ctx;

	return (&g_ctx);
}

void	*gc_malloc_ctx(t_ctx *ctx, size_t size)
{
	void		*ptr;
	t_ptrs_list	*new_node;

	if (!ctx)
		ctx = get_global_ctx();
	ptr = ft_calloc(1, size);
	if (!ptr)
		return (NULL);
	new_node = ft_calloc(1, sizeof(t_ptrs_list));
	if (!new_node)
	{
		free(ptr);
		return (NULL);
	}
	new_node->ptr = ptr;
	new_node->next = ctx->ptrs;
	ctx->ptrs = new_node;
	ctx->list_size++;
	return (ptr);
}

void	gc_free_ctx(t_ctx *ctx, void *ptr)
{
	t_ptrs_list	*node;
	t_ptrs_list	*old;

	if (!ctx)
		ctx = get_global_ctx();
	node = ctx->ptrs;
	old = NULL;
	while (node)
	{
		if (node->ptr == ptr)
		{
			free(node->ptr);
			if (old)
				old->next = node->next;
			else
				ctx->ptrs = node->next;
			free(node);
			ctx->list_size--;
			break ;
		}
		old = node;
		node = node->next;
	}
	free(ptr);
}

void	gc_clean_all_ctx(t_ctx *ctx)
{
	t_ptrs_list	*node;
	t_ptrs_list	*old;

	if (!ctx)
		ctx = get_global_ctx();
	node = ctx->ptrs;
	while (node)
	{
		old = node;
		node = node->next;
		free(old->ptr);
		free(old);
	}
	ctx->ptrs = NULL;
	ctx->list_size = 0;
}

t_bool	gc_add_ctx(t_ctx *ctx, void *ptr)
{
	t_ptrs_list	*new_node;

	if (!ctx)
		ctx = get_global_ctx();
	new_node = ft_calloc(1, sizeof(t_ptrs_list));
	if (!new_node)
		return (FALSE);
	new_node->ptr = ptr;
	new_node->next = ctx->ptrs;
	ctx->ptrs = new_node;
	ctx->list_size++;
	return (TRUE);
}
