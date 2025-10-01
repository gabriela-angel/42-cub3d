/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:42:01 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/27 14:11:15 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

// Error codes for the application
typedef enum e_error
{
	E_EMPTY_MAP = 1,
	E_OPEN_FAILED,
	E_INVALID_ARGS,
	E_MLX_INIT_FAILED,
	E_INVALID_MAP_NAME,
	E_INVALID_FILE_CHAR,
}			t_error;

void	ft_error(t_error code);

#endif