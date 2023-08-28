/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:59:25 by paula             #+#    #+#             */
/*   Updated: 2023/08/28 19:08:19 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include <math.h>

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

void	bresenham_line(t_axis axis, t_map *fdf)
{
	float	x_step;
	float	y_step;
	int		max_num;
	int		z;
	int		z1;

	z = fdf->z_matrix[(int)axis.y][(int)axis.x];
	z1 = fdf->z_matrix[(int)axis.y1][(int)axis.x1];
	axis.x *= fdf->x_scale;
	axis.x1 *= fdf->x_scale;
	axis.y *= fdf->y_scale;
	axis.y1 *= fdf->y_scale;
	if (z == 0)
		fdf->color = RED_PIXEL;
	else
		fdf->color = WHITE_PIXEL;
	x_step = axis.x1 - axis.x;
	y_step = axis.y1 - axis.y;
	max_num = max(mod(x_step), mod(y_step));
	x_step /= max_num;
	y_step /= max_num;
	while ((int)(axis.x - axis.x1) || (int)(axis.y - axis.y1))
	{
		printf("entrou\n");
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
			bresenham_line((t_axis){x: x, y: y, x1: x + 1, y1: y}, fdf);
			bresenham_line((t_axis){x: x, y: y, x1: x, y1: y + 1}, fdf);
			x++;
		}
		y++;
	}
}