/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:35:45 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/09 19:51:24 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_recalloc(void *ptr, size_t new_size)
{
	void	*new_ptr;
	size_t	cpy_size;
	size_t	old_size;

	old_size = ft_malloc_size(ptr);
	if (!ptr)
		return (ft_calloc(1, new_size));
	if (new_size == old_size)
		return (ptr);
	if (new_size == 0)
	{
		ft_free(ptr);
		return (NULL);
	}
	if (new_size < old_size)
		cpy_size = new_size;
	else
		cpy_size = old_size;
	new_ptr = ft_calloc(1, new_size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, cpy_size);
	ft_free(ptr);
	return (new_ptr);
}
