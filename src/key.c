/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:26:02 by pde-souz          #+#    #+#             */
/*   Updated: 2023/08/31 11:36:22 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	deal_key(int key, t_map *fdf)
{
	if (key == A_UP)
		fdf->y_margin -= 5;
	else if (key == A_DOWN)
		fdf->y_margin += 5;
	else if (key == A_RIGHT)
		fdf->x_margin += 10;
	else if (key == A_LEFT)
		fdf->x_margin -= 10;
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
