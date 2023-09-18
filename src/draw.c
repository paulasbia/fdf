/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:59:25 by paula             #+#    #+#             */
/*   Updated: 2023/09/18 18:25:07 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#define PI 3.141592654

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

static void	put_3d(float *x, float *y, int *z, t_map *fdf)
{
	*x = *x * cos(fdf->angle) - *y * cos(fdf->angle);
	*y = (*x * sin(fdf->angle) + *y * sin(fdf->angle)) - (2.5 * (*z));
}

void	bresenham_line(t_axis axis, t_map *fdf)
{
	float	x_step;
	float	y_step;
	int		max_num;

	axis.z = fdf->z_matrix[(int)axis.y][(int)axis.x] * fdf->z_scale;
	axis.z1 = fdf->z_matrix[(int)axis.y1][(int)axis.x1] * fdf->z_scale;
	set_start(&axis, fdf);
	if (fdf->is_3d)
	{
		put_3d(&axis.x, &axis.y, &axis.z, fdf);
		put_3d(&axis.x1, &axis.y1, &axis.z1, fdf);
	}
	put_axis(&axis, fdf);
	x_step = axis.x1 - axis.x;
	y_step = axis.y1 - axis.y;
	max_num = max(mod(x_step), mod(y_step));
	x_step /= max_num;
	y_step /= max_num;
	while ((int)(axis.x - axis.x1) || (int)(axis.y - axis.y1))
	{
		ft_mlx_pixel_put(fdf->img, (int)axis.x, (int)axis.y, axis.color);
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
				bresenham_line((t_axis){.x = x, .y = y, .x1 = x + 1, .y1 = y,
					.color = fdf->color[y][x]}, fdf);
			if (y < fdf->heigth - 1)
				bresenham_line((t_axis){.x = x, .y = y, .x1 = x, .y1 = y + 1,
					.color = fdf->color[y][x]}, fdf);
			x++;
		}
		y++;
	}
}
