/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulabiazotto <paulabiazotto@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:48:43 by paulabiazot       #+#    #+#             */
/*   Updated: 2023/08/22 13:03:46 by paulabiazot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>

//# include <stdio.h>
//# include <stdlib.h>

//	Screen Resolution
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 700

#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF

//MAC KEYS
# define K_ESC					53
# define K_UP					13
# define K_LEFT					0
# define K_RIGHT				2
# define K_DOWN					1
# define A_UP					0x7E
# define A_DOWN					0x7D
# define A_LEFT					0x7B
# define A_RIGHT				0x7C

/* LINUX KEYS */
/* #define K_ESC                65307
#define K_UP                    119
#define K_LEFT                  97
#define K_RIGHT                 100
#define K_DOWN                  115
#define A_UP                    65362
#define A_DOWN                  65364
#define A_LEFT                  65361
#define A_RIGHT                 65363
*/

//structs

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int     bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_data
{
	int		heigth;
	int		width;
	int		**z_matrix;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}			t_data;


void    check_av(int ac, char **av);
void	exit_error(const char *msg);
void	error(void);
void    read_maps(t_data *fdf, int fd);
void    fill_matrix(int *z_line, char *line);
int		ft_wordc(const char *str, char c);
int 	get_width(int fd);
int 	get_height(int fd);

#endif

