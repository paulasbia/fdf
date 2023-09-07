/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:26:02 by pde-souz          #+#    #+#             */
/*   Updated: 2023/09/07 16:44:29 by paula            ###   ########.fr       */
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
			fdf->z_scale -= 1.2;
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
		fdf->angle -= 0.05;
	else if (key == S_DOWN)
		fdf->angle += 0.05;
	else if (key == K_ESC)
		close_img(fdf);
	ft_bzero(fdf->img->addr, (WINDOW_HEIGHT * WINDOW_WIDTH
			* sizeof(fdf->img->bpp)));
	draw_file(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img->mlx_img, 0,
		0);
	return (0);
}
