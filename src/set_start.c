/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:09:57 by paula             #+#    #+#             */
/*   Updated: 2023/09/01 12:56:49 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_instruction(void)
{
	ft_printf(BLUE "------------------------------------------------------" 
		RESET "\n" BLUE "│" MARGENTA "                " "CONTROLS INFORMATION" 
		"                " BLUE "│" RESET "\n" BLUE 
		"------------------------------------------------------" RESET "\n" 
		BLUE "╔═══════════════════════════════════════════"
		"═════════╗" RESET "\n" BLUE "║" MARGENTA 
		"                     Translation                    " BLUE "║" 
		RESET "\n" BLUE "║" GREEN "      UP ARROW  " YELLOW "    UP   " 
		GREEN "     DOWN ARROW  " YELLOW " DOWN   " BLUE "  ║"
		"\n" BLUE "║" GREEN "      RIGHT ARROW  " YELLOW " RIGHT   " 
		GREEN "  LEFT ARROW  " YELLOW " LEFT " BLUE "    ║" RESET "\n" 
		BLUE "╚════════════════════════════════════════════════════╝" 
		RESET "\n");
}

void	init_img(t_map *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"FDF - by pde-souz");
	if (fdf->win_ptr == NULL)
	{
		free(fdf->win_ptr);
		error();
	}
	fdf->img->mlx_img = mlx_new_image(fdf->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	fdf->img->addr = mlx_get_data_addr(fdf->img->mlx_img, &(fdf->img->bpp),
			&(fdf->img->line_len), &(fdf->img->endian));
	fdf->x_margin = (WINDOW_WIDTH / 2);
	fdf->y_margin = (WINDOW_HEIGHT / 2);
	fdf->angle = 0.523599;
	fdf->x_scale = 0.54 * (WINDOW_WIDTH / fdf->width);
	fdf->y_scale = 0.54 * (WINDOW_HEIGHT / fdf->heigth);
}

void	set_start(t_axis *axis, t_map *fdf)
{
	// fdf->x_scale = 0.54 * (WINDOW_WIDTH / fdf->width);
	// fdf->y_scale = 0.54 * (WINDOW_HEIGHT / fdf->heigth);
	axis->x *= fdf->x_scale;
	axis->x1 *= fdf->x_scale;
	axis->y *= fdf->y_scale;
	axis->y1 *= fdf->y_scale;
	// axis->x += fdf->x_margin;
	// axis->x1 += fdf->x_margin;
	// axis->y += fdf->y_margin;
	// axis->y1 += fdf->y_margin;
}
