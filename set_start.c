/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:09:57 by paula             #+#    #+#             */
/*   Updated: 2023/08/29 12:10:36 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	set_start(t_axis *axis, t_map *fdf)
{
	fdf->x_scale = 0.45 * (WINDOW_WIDTH / fdf->width);
	fdf->y_scale = 0.45 * (WINDOW_HEIGHT / fdf->heigth);
	fdf->x_margin = 450;
	fdf->y_margin = 5;
	axis->x *= fdf->x_scale;
	axis->x1 *= fdf->x_scale;
	axis->y *= fdf->y_scale;
	axis->y1 *= fdf->y_scale;
	axis->x += fdf->x_margin;
	axis->x1 += fdf->x_margin;
	axis->y += fdf->y_margin;
	axis->y1 += fdf->y_margin;
}
