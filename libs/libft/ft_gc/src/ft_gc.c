/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:40:14 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/03 13:14:01 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gc.h"

static t_ctx	*get_global_ctx(void)
{
	static t_ctx	g_ctx;

	return (&g_ctx);
}

void	*ft_gc_malloc(size_t size)
{
	t_ctx	*ctx;
	t_ctx	*new_node;
	void	*ptr;

	ctx = get_global_ctx();
	ptr = ft_calloc(1, size);
	if (!ptr)
		return (NULL);
	new_node = ft_calloc(1, sizeof(t_ctx));
	if (!new_node)
	{
		free(ptr);
		return (NULL);
	}
	new_node->ptr = ptr;
	new_node->next = ctx->next;
	ctx->next = new_node;
	return (ptr);
}

void	ft_gc_free(void *ptr)
{
	t_ctx	*ctx;
	t_ctx	*tmp;

	ctx = get_global_ctx();
	while (ctx->next)
	{
		if (ctx->ptr == ptr)
		{
			tmp = ctx->next;
			ctx->ptr = tmp->ptr;
			ctx->next = tmp->next;
			free(tmp);
			break ;
		}
		ctx = ctx->next;
	}
	free(ptr);
}

void	ft_gc_clean_all(void)
{
	t_ctx	*ctx;
	t_ctx	*tmp;

	ctx = get_global_ctx();
	while (ctx->next)
	{
		free(ctx->ptr);
		tmp = ctx->next;
		ctx->ptr = tmp->ptr;
		ctx->next = tmp->next;
		free(tmp);
	}
	get_global_ctx()->ptr = NULL;
	get_global_ctx()->next = NULL;
}

t_bool	ft_gc_add(void *ptr)
{
	t_ctx	*ctx;
	t_ctx	*new_node;

	ctx = get_global_ctx();
	new_node = ft_calloc(1, sizeof(t_ctx));
	if (!new_node)
	{
		free(ptr);
		return (FALSE);
	}
	new_node->ptr = ptr;
	new_node->next = ctx->next;
	ctx->next = new_node;
	return (TRUE);
}
