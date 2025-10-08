/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:31:00 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/08 15:12:10 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GC_H
# define FT_GC_H

# include "../../ft_bool.h"
# include "../../libft.h"
# include "ft_gc_ctx.h"
# include "ft_gc_utils.h"

/*
	Malloc memory and add it to the internal CTX of the GC.

	CTX ->			a group/buffer that can hold multiple pointers
	GC ->			Garbage Collector
	internal CTX ->	the CTX internally managed by the GC
*/
void	*gc_malloc(size_t size);

/*
	Free ptr and remove it from the internal CTX of the GC. (low performance)

	CTX ->			a group/buffer that can hold multiple pointers
	GC ->			Garbage Collector
	internal CTX ->	the CTX internally managed by the GC
*/
void	gc_free(void *ptr);

/*
	Free all the pointers stored in the internal CTX of the GC.

	CTX ->			a group/buffer that can hold multiple pointers
	GC ->			Garbage Collector
	internal CTX ->	the CTX internally managed by the GC
*/
void	gc_clean_all(void);

/*
	Add a pointer to the internal CTX of the GC.

	CTX ->			a group/buffer that can hold multiple pointers
	GC ->			Garbage Collector
	internal CTX ->	the CTX internally managed by the GC
*/
t_bool	gc_add(void *ptr);

/*
	Create a custom new CTX that can hold multiple pointers.
	You can manage the pointers in this CTX using the functions:
	- gc_malloc_ctx
	- gc_add_ctx
	- gc_free_ctx
	- gc_clean_all_ctx
*/
t_ctx	*gc_create_ctx(void);

/*
	Destroy a custom CTX created with gc_create_ctx.
	This will free all the pointers stored in this CTX.
*/
void	gc_destroy_ctx(t_ctx *ctx);

/*
	Free all CTXs and their pointers, including the internal CTX.
	After calling this function, the GC is reseted and can be used again.
*/
void	terminate_gc(void);

#endif