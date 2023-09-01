/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:26:02 by pde-souz          #+#    #+#             */
/*   Updated: 2023/09/01 14:53:43 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	simple_move(int key, t_map *fdf)
{
	if (key == A_UP)
		fdf->y_margin -= 10;
	else if (key == A_DOWN)
		fdf->y_margin += 10;
	else if (key == A_RIGHT)
		fdf->x_margin += 10;
	else if (key == A_LEFT)
		fdf->x_margin -= 10;
}

static void	zoom_move(int key, t_map *fdf)
{
	if (key == PLUS)
	{
		fdf->x_scale += 1;
		fdf->y_scale += 1;
	}
	else if (key == MIN)
	{
		fdf->x_scale -= 1;
		fdf->y_scale -= 1;
	}
	else if (key == D_RIGHT)
	{
		if (fdf->z_scale > -20)
			fdf->z_scale -= 1.2 ;
	}
	else if (key == AA_LEFT)
	{
		if (fdf->z_scale < 20)
			fdf->z_scale += 1.2;
	}
}

int	deal_key(int key, t_map *fdf)
{
	simple_move(key, fdf);
	zoom_move(key, fdf);
	if (key == W_UP)
		fdf->angle += 0.05;
	else if (key == S_DOWN)
		fdf->angle -= 0.05;
	if (key == K_ESC)
	{
		mlx_destroy_image(fdf->mlx_ptr, fdf->img->mlx_img);
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		free(fdf->img);
		mlx_destroy_display(fdf->mlx_ptr);
		free(fdf->mlx_ptr);
		free_matrix(fdf);
		exit(0);
	}
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw_file(fdf);
	return (0);
}