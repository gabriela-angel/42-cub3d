/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:12:39 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/09 19:37:09 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t new_size)
{
	void	*new_ptr;
	size_t	cpy_size;
	size_t	old_size;

	old_size = ft_malloc_size(ptr);
	if (!ptr)
		return (ft_malloc(new_size));
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
	new_ptr = ft_malloc(new_size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, cpy_size);
	ft_free(ptr);
	return (new_ptr);
}
