/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:57:24 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/08 21:48:21 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_UTILS_H
# define GET_NEXT_LINE_UTILS_H

# include "get_next_line.h"

# define CLEAR_ALL -1

typedef struct s_ctx	t_ctx;

// Returns the address of the first '\n' character in the string s
char					*get_nl_address(const char *s);

// Returns the static buffer of GNL
char					**get_gnl_buffer(void);

// Clears static buffer of GNL for the specified fd or all if fd == CLEAR_ALL
void					clear_gnl_buffer(int fd);

// Returns the garbage collector CTX for the specified fd.
// If it does not exist, it creates a new one.
// Returns NULL if fd is invalid.
t_ctx					*get_gnl_ctx(int fd);

// Clears the garbage collector CTX pointer for the specified fd.
void					clear_gnl_ctx(int fd);

#endif