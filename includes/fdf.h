/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:48:43 by paulabiazot       #+#    #+#             */
/*   Updated: 2023/09/06 11:01:53 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
//# include "../mlx/mlx.h"
# include "../mlx_linux/mlx.h"
# include <math.h>

//	Screen Resolution
# define WINDOW_WIDTH 1500
# define WINDOW_HEIGHT 1000

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF

# define GREEN 			"\033[0;32m"
# define RED 			"\033[0;31m"
# define YELLOW 		"\x1b[33m"
# define BLUE 			"\x1b[34m"
# define MARGENTA 		"\x1b[35m"
# define RESET 			"\033[0m"

// MAC KEYS
// # define K_ESC 53
// # define K_UP 13
// # define K_LEFT 0
// # define K_RIGHT 2
// # define K_DOWN 1
// # define A_UP 0x7E
// # define A_DOWN 0x7D
// # define A_LEFT 0x7B
// # define A_RIGHT 0x7C

/* LINUX KEYS */
# define K_ESC					65307
# define W_UP                   119
# define AA_LEFT                 97
# define D_RIGHT                100
# define S_DOWN                 115
# define A_UP                   65362
# define A_DOWN                 65364
# define A_LEFT                 65361
# define A_RIGHT                65363
# define PLUS					61
# define MIN					45

// structs

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_fdf
{
	float	x;
	float	x1;
	float	y;
	float	y1;
	int		z;
	int		z1;
}			t_axis;

typedef struct s_data
{
	int		heigth;
	int		width;
	int		**z_matrix;
	float	x_scale;
	float	y_scale;
	float	x_margin;
	float	y_margin;
	float	z_scale;
	float	angle;
	int		color;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
}			t_map;

void		check_av(int ac, char **av);
void		exit_error(const char *msg);
void		error(void);
void		ft_instruction(void);
void		ft_instruction2(void);
void		ft_param(t_map *fdf);
void		free_matrix(t_map *fdf);
void		read_maps(t_map *fdf, char *file);
void		fill_matrix(int *z_line, char *line);
int			ft_wordc(const char *str, char c);
int			get_width(char *file);
int			get_height(char *file);
void		bresenham_line(t_axis axis, t_map *fdf);
void		draw_file(t_map *fdf);
void		set_start(t_axis *axis, t_map *fdf);
void		set_color(t_axis *axis, t_map *fdf);
void		put_axis(t_axis *axis, t_map *fdf);
void		init_img(t_map *fdf);
int			close_img(t_map *fdf);
int			deal_key(int key, t_map *fdf);

#endif
