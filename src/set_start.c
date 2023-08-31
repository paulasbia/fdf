/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:09:57 by paula             #+#    #+#             */
/*   Updated: 2023/08/31 11:11:59 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_img(t_map *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"FDF");
	if (fdf->win_ptr == NULL)
	{
		free(fdf->win_ptr);
		error ();
	}
	fdf->img->mlx_img = mlx_new_image(fdf->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	fdf->img->addr = mlx_get_data_addr(fdf->img->mlx_img, &(fdf->img->bpp),
			&(fdf->img->line_len), &(fdf->img->endian));
	fdf->x_margin = 450;
	fdf->y_margin = 5;
}

void	set_start(t_axis *axis, t_map *fdf)
{
	fdf->x_scale = 0.54 * (WINDOW_WIDTH / fdf->width);
	fdf->y_scale = 0.54 * (WINDOW_HEIGHT / fdf->heigth);
	axis->x *= fdf->x_scale;
	axis->x1 *= fdf->x_scale;
	axis->y *= fdf->y_scale;
	axis->y1 *= fdf->y_scale;
	axis->x += fdf->x_margin;
	axis->x1 += fdf->x_margin;
	axis->y += fdf->y_margin;
	axis->y1 += fdf->y_margin;
}
