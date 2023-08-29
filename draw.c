/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:59:25 by paula             #+#    #+#             */
/*   Updated: 2023/08/29 11:19:14 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"


int	max(float x, float y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

float	mod(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

void	put_3d(float *x, float *y, int *z)
{
	*x = (*x - *y) * cos(0.7);
	*y = (*x + *y) * sin(0.7) - *z;
}

void	bresenham_line(t_axis axis, t_map *fdf)
{
	float	x_step;
	float	y_step;
	int		max_num;

	axis.z = fdf->z_matrix[(int)axis.y][(int)axis.x];
	axis.z1 = fdf->z_matrix[(int)axis.y1][(int)axis.x1];
	
	axis.x *= fdf->x_scale;
	axis.x1 *= fdf->x_scale;
	axis.y *= fdf->y_scale;
	axis.y1 *= fdf->y_scale;

	axis.x += fdf->x_margin;
	axis.x1 += fdf->x_margin;
	axis.y += fdf->y_margin;
	axis.y1 += fdf->y_margin;
	if (axis.z > 0 || axis.z1 > 0)
		fdf->color = RED_PIXEL;
	else
		fdf->color = WHITE_PIXEL;
	put_3d(&axis.x, &axis.y, &axis.z);
	put_3d(&axis.x1, &axis.y1, &axis.z1);
	x_step = axis.x1 - axis.x;
	y_step = axis.y1 - axis.y;
	max_num = max(mod(x_step), mod(y_step));
	x_step /= max_num;
	y_step /= max_num;
	while ((int)(axis.x - axis.x1) || (int)(axis.y - axis.y1))
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, axis.x, axis.y, fdf->color);
		axis.x += x_step;
		axis.y += y_step;
	}
}

void	draw_file(t_map *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->heigth)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x < fdf->width - 1)
				bresenham_line((t_axis){x: x, y: y, x1: x + 1, y1: y}, fdf);
			if (y < fdf->heigth - 1)
				bresenham_line((t_axis){x: x, y: y, x1: x, y1: y + 1}, fdf);
			x++;
		}
		y++;
	}
}
