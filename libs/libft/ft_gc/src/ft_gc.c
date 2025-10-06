/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:40:14 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/06 15:12:34 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gc.h"

static t_ctx	**get_global_ctx(void)
{
	static t_ctx	*g_ctx;

	return (&g_ctx);
}

void	*ft_gc_malloc(size_t size)
{
	t_ctx	*node;
	t_ctx	*new_node;
	void	*ptr;

	node = *get_global_ctx();
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
	new_node->next = node;
	*get_global_ctx() = new_node;
	return (ptr);
}

void	ft_gc_free(void *ptr)
{
	t_ctx	*node;
	t_ctx	*old;

	node = *get_global_ctx();
	old = NULL;
	while (node)
	{
		if (node->ptr == ptr)
		{
			free(node->ptr);
			if (old)
				old->next = node->next;
			else
				*get_global_ctx() = node->next;
			free(node);
			break ;
		}
		old = node;
		node = node->next;
	}
	free(ptr);
}

void	ft_gc_clean_all(void)
{
	t_ctx	*node;
	t_ctx	*old;

	node = *get_global_ctx();
	while (node)
	{
		old = node;
		node = node->next;
		free(old->ptr);
		free(old);
	}
	*get_global_ctx() = NULL;
}

t_bool	ft_gc_add(void *ptr)
{
	t_ctx	*node;
	t_ctx	*new_node;

	node = *get_global_ctx();
	new_node = ft_calloc(1, sizeof(t_ctx));
	if (!new_node)
		return (FALSE);
	new_node->ptr = ptr;
	new_node->next = node;
	*get_global_ctx() = new_node;
	return (TRUE);
}
