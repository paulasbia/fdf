/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:07:16 by paula             #+#    #+#             */
/*   Updated: 2023/09/01 12:33:03 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*void	rotate(int key, t_map *fdf, t_axis *axis)
{
	int mx;
	int my;
	float angle_pos;
	float angle_min;

	mx = (axis->x + axis->x1) / 2;
	my = (axis->y + axis->y1) / 2;
	angle_pos = (fdf->angle += 0.05);
	angle_min = (fdf->angle -= 0.05);
	if (key == W_UP)
	{
		fdf->x_margin = mx + (axis->x - mx) * cos(angle_pos) - (axis->y - my)
			* sin(angle_pos);
		axis->x1 = mx + (axis->x1 - mx) * cos(angle_pos) - (axis->y1 - my)
			* sin(angle_pos);
		fdf->y_margin = my + (axis->x - mx) * sin(angle_pos) + (axis->y - my)
			* cos(angle_pos);
		axis->y1 = my + (axis->x1 - mx) * sin(angle_pos) + (axis->y1 - my)
			* cos(angle_pos);
	}
	if (key == S_DOWN)
	{
		axis->x = mx + (axis->x - mx) * cos(angle_min) - (axis->y - my)
			* sin(angle_min);
		axis->x1 = mx + (axis->x1 - mx) * cos(angle_min) - (axis->y1 - my)
			* sin(angle_min);
		axis->y = my + (axis->x - mx) * sin(angle_min) + (axis->y - my)
			* cos(angle_min);
		axis->y1 = my + (axis->x1 - mx) * sin(angle_min) + (axis->y1 - my)
			* cos(angle_min);
	}
}*/
