/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_ctx.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:21:15 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/08 15:19:55 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GC_CTX_H
# define FT_GC_CTX_H

# include "ft_gc_utils.h"

/*
	Malloc memory and add it to the specified CTX.

	CTX ->			a group/buffer that can hold multiple pointers
*/
void	*gc_malloc_ctx(t_ctx *ctx, size_t size);

/*
	Free ptr and remove it from the specified CTX. (low performance)

	CTX ->			a group/buffer that can hold multiple pointers
*/
void	gc_free_ctx(t_ctx *ctx, void *ptr);

/*
	Free all the pointers stored in the specified CTX.

	CTX ->			a group/buffer that can hold multiple pointers
*/
void	gc_clean_all_ctx(t_ctx *ctx);

/*
	Add a pointer to the specified CTX.
	Returns TRUE on success, FALSE on failure.

	CTX ->			a group/buffer that can hold multiple pointers
*/
t_bool	gc_add_ctx(t_ctx *ctx, void *ptr);

#endif