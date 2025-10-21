/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:40:14 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/08 13:23:30 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gc.h"
#include "ft_gc_utils.h"

void	*gc_malloc(size_t size)
{
	return (gc_malloc_ctx(NULL, size));
}

void	gc_free(void *ptr)
{
	return (gc_free_ctx(NULL, ptr));
}

void	gc_clean_all(void)
{
	return (gc_clean_all_ctx(NULL));
}

t_bool	gc_add(void *ptr)
{
	return (gc_add_ctx(NULL, ptr));
}
