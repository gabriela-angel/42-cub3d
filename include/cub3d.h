/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:17:56 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/10/13 22:46:38 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/MLX/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"
# include <math.h>

// Error codes for the application
typedef enum e_error
{
	E_MLX_INIT_FAILED,
}			t_error;

// Constants for window dimensions
# define WIDTH 800
# define HEIGHT 600

// KEY BINDS
# define W MLX_KEY_W
# define A MLX_KEY_A
# define S MLX_KEY_S
# define D MLX_KEY_D
# define LEFT_KEY MLX_KEY_LEFT
# define RIGHT_KEY MLX_KEY_RIGHT
# define ESC MLX_KEY_ESCAPE

// Movement speeds
# define MOVE_SPEED 0.05
# define COLLISION_OFFSET 0.3
# define ROT_SPEED 0.01
# define MOUSE_SENSITIVITY 0.002

enum	e_axis
{
	X,
	Y
};

enum	e_direction
{
	RIGHT = 1,
	LEFT = -1
};

enum	e_texture
{
	NORTH,
	SOUTH,
	WEST,
	EAST
};

typedef struct s_map_textures
{
	uint32_t		floor;
	uint32_t		ceiling;
	t_hash_table	*paths;
}					t_map_textures;

typedef struct s_map
{
	size_t			height;
	size_t			width;
	char			*path;
	int				fd;
	char			**flood_fill;
	char			**matrix;
	t_map_textures	textures;
}					t_map;


typedef struct s_player
{
	double	pos[2];
	double	dir[2];
	double	plane[2];
}	t_player;

typedef struct s_cube
{
	t_map		map;
	t_player	player;
	int			mouse_x;
	char		*error_context;
}	t_cube;

typedef struct s_ray
{
	double	cam_x;
	int		map_pos[2];
	double	dir[2];
	double	side_dist[2];
	double	delta_dist[2];
	double	wall_dist;
	int step[2];
	int hit;
	int side;
	int line_height;
	int line_start;
	int line_end;
}	t_ray;


typedef struct s_mlx
{
	mlx_t		*instance;
}			t_mlx;

// MLX
t_mlx		*get_global_mlx(void);
void		ft_init_mlx(void);

// CUBE
t_cube *get_global_cube(void);

// HOOKS
void		key_hook(mlx_key_data_t keydata, void *param);
void		cursor_hook(double xpos, double ypos, void *param);

// ERROR
void		ft_error(t_error code);

#endif
