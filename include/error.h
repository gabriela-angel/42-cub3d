/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:42:01 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/08 19:38:49 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "map.h"
# include <errno.h>
# include <string.h>

// Error codes for the application
typedef enum e_error
{
	E_SUCCESS = 0,

	E_INVALID_ARGS,
	E_OPEN_FAILED,
	E_MLX_INIT_FAILED,

	E_INVALID_MAP_NAME,
	E_EMPTY_MAP_FILE,
	E_INVALID_FILE_CHAR,
	E_EMPTY_MAP,
	E_INVALID_ELEMENT,

	E_INVALID_MAP_CHAR,

	E_TEX_DUP,
	E_F_DUP,
	E_C_DUP,

	E_TEX_NO_MISS,
	E_TEX_SO_MISS,
	E_TEX_WE_MISS,
	E_TEX_EA_MISS,
	E_F_MISS,
	E_C_MISS,

	E_NO_INV_EXT,
	E_SO_INV_EXT,
	E_WE_INV_EXT,
	E_EA_INV_EXT,

	E_MAP_NOT_LAST_ELEMENT,

	E_NO_FILE,
	E_SO_FILE,
	E_WE_FILE,
	E_EA_FILE,

	E_INVALID_RGB_VALUE,
	E_INVALID_RGB_FIELDS,

	E_MAP_NOT_CLOSED,

	E_MULTIPLE_PLAYER,
	E_NO_PLAYER,
}				t_error;

// Linked list to store t_points of flood fill errors
typedef struct s_flood_errors
{
	t_point		*points;
	size_t		count;
}				t_flood_errors;

// error.c
void			ft_error(t_error code);
void			print_error(char *message);
void			add_error_context(char *message);
void			handle_generic_errors(t_error code);
void			handle_map_errors(t_error code);

// flood_errors.c
t_flood_errors	*get_global_flood_errors(void);
void			add_flood_invalid_char(t_point point);
void			print_errors(void);

// matrix_errors.c
void			print_flood_error(void);
void			flood_fill(char **mtx, size_t wdt, size_t hgt, t_point start);

#endif