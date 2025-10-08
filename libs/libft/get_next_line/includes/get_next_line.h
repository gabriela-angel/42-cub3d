/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:30:48 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/08 16:17:46 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "../../libft.h"
# include "get_next_line_utils.h"
# include <stdlib.h>
# include <unistd.h>

# define FD_MAX 1024

// get the next line from specified file descriptor.
// Returns NULL if there is nothing else to read or an error occurs.
// The returned line includes the \n character if it was present in the input.
//
// WARNING: The GNL is integrated with the garbage collector:
// - Don't free the returned line !!
// It will be freed when close_and_clear(fd) is called.
// - Make sure to call close_and_clear(fd) when you are done with the FD.
// - When close_and_clear(fd) is called, all memory associated with the FD
//   is freed, so avoid accessing the returned line afterward.
char	*get_next_line(int fd);

// Closes the file descriptor and clears its associated static buffer
void	close_and_clear(int fd);

#endif
