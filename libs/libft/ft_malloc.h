/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:12:56 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/09 19:30:18 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

/*
	Allocates memory and stores the size of the allocation.
	- WARNING: The returned pointer must be freed with [ft_free].
*/
void	*ft_malloc(size_t size);

/*
	Allocates memory for an array of [count] elements of [size] bytes each
	and initializes all bytes to zero.
	- WARNING: The returned pointer must be freed with [ft_free].
*/
void	*ft_calloc(size_t count, size_t size);

/*
	Reallocates the memory coppiyng the old content to the new allocation.
	- If [ptr] is NULL, this function is equivalent to [ft_malloc(new_size)].
	WARNINGs:
	- This only works for pointers allocated with [ft_malloc] or [ft_calloc].
	- The returned pointer must be freed with [ft_free].
*/
void	*ft_realloc(void *ptr, size_t new_size);

/*
	Reallocates the memory coppiyng the old content to the new allocation.
	- If [ptr] is NULL, this function is equivalent to [ft_calloc(new_size)].
	WARNINGs:
	- This only works for pointers allocated with [ft_malloc] or [ft_calloc].
	- The returned pointer must be freed with [ft_free].
*/
void	*ft_recalloc(void *ptr, size_t new_size);

/*
	Frees the memory allocated by this functions:
	- ft_malloc
	- ft_calloc
	- ft_realloc
	- ft_recalloc
*/
void	ft_free(void *ptr);

/*
	Returns the size of the allocated memory block pointed to by [ptr].
	- If [ptr] is NULL, the function returns 0.
	- This only works for pointers allocated with [ft_malloc] or [ft_calloc].
*/
size_t	ft_malloc_size(void *ptr);

#endif