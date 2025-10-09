/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:29:34 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/09 19:29:59 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_malloc_size(void *ptr)
{
	size_t	*size_ptr;

	if (!ptr)
		return (0);
	size_ptr = (size_t *)ptr - 1;
	return (*size_ptr);
}
