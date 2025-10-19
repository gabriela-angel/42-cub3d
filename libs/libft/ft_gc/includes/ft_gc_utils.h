/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:13:27 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/08 15:22:14 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GC_UTILS_H
# define FT_GC_UTILS_H

// Linked list to hold the pointers
typedef struct s_ptrs_list
{
	void				*ptr;
	struct s_ptrs_list	*next;
}						t_ptrs_list;

// CTX structure to hold the list of pointers
typedef struct s_ctx
{
	t_ptrs_list			*ptrs;
	size_t				list_size;
}						t_ctx;

// Function to get the CTX list to be freed when terminate_gc is called
t_ctx	*get_ctx_list(void);

#endif