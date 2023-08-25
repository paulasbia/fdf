/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:59:25 by paula             #+#    #+#             */
/*   Updated: 2023/08/25 12:11:28 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include <math.h>

int max(float x, float y)
{
    if (x > y)
        return (x);
    else
        return (y);
}

float   mod(float i)
{
    if (i < 0)
        return (-i);
    else
        return(i);
}

void    bresenham_line(float x, float y, float x1, float y1, t_map *fdf)
{
    float   x_step;
    float   y_step;
    int   max_num;

    x_step = x1 - x;
    y_step = y1 - y;
    max_num = max(mod(x_step), mod(y_step));
    x_step /= max_num;
    y_step /= max_num;
    while ((int)(x - x1)|| (int)(y - y1))
    {
        mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0xffffff);
        x += x_step;
        y += y_step;
    }
    
}