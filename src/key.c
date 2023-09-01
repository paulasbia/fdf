/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:26:02 by pde-souz          #+#    #+#             */
/*   Updated: 2023/09/01 12:55:10 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	deal_key(int key, t_map *fdf, t_axis *axis)
{
	printf("%d\n", key);
	if (key != 0)
		(void)axis;
	if (key == A_UP)
		fdf->y_margin -= 10;
	else if (key == A_DOWN)
		fdf->y_margin += 10;
	else if (key == A_RIGHT)
		fdf->x_margin += 10;
	else if (key == A_LEFT)
		fdf->x_margin -= 10;
	else if (key == 61)
	{
		fdf->x_scale += 1;
		fdf->y_scale += 1;
	}
	else if (key == 45)
	{
		fdf->x_scale -= 1;
		fdf->y_scale -= 1;
	}
	// else if (key == W_UP || key == S_DOWN)
	// 	rotate(key, fdf, axis);
	else if (key == K_ESC)
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
