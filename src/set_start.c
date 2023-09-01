/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:09:57 by paula             #+#    #+#             */
/*   Updated: 2023/09/01 15:35:05 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_instruction(void)
{
	ft_printf(BLUE "------------------------------------------------------" 
		RESET "\n" BLUE "│" MARGENTA "                "
		"CONTROLS INFORMATION" "                " BLUE "│" RESET "\n" BLUE 
		"------------------------------------------------------" RESET "\n"
		BLUE "╔═══════════════════════════════════════════"
		"═════════╗" RESET "\n" BLUE "║" MARGENTA 
		"                     Translation                    " BLUE "║" 
		RESET "\n" BLUE "║" GREEN "      UP ARROW  " YELLOW "    UP   " 
		GREEN "     DOWN ARROW  " YELLOW " DOWN   " BLUE "  ║"
		"\n" BLUE "║" GREEN "      RIGHT ARROW  " YELLOW " RIGHT   " 
		GREEN "  LEFT ARROW  " YELLOW " LEFT " BLUE "    ║" RESET BLUE "\n" 
		BLUE "║" BLUE "                                                    ║"
		"\n" BLUE "║" MARGENTA "                        Zoom                 "
		BLUE "       ║" RESET "\n" BLUE "║" GREEN "     '+'  " YELLOW 
		"    ZOOM IN   " GREEN "     '-'  " YELLOW " ZOOM OUT   " BLUE "      ║"
		"\n" BLUE "║" GREEN "     'A'  " YELLOW " ZOOM IN SCALE   " 
		GREEN "  'D'  " YELLOW " ZOOM OUT SCALE " BLUE "  ║" RESET "\n"
		BLUE "║" RESET BLUE 
		"                                                    ║"
		"\n" BLUE "║" MARGENTA "                      Rotation               "
		BLUE "       ║" RESET "\n" BLUE "║" GREEN "     'W'  " YELLOW 
		"    ROT UP   " GREEN "      'S'  " YELLOW " ROT DOWN  " BLUE "       ║"
		RESET "\n" 
		BLUE "╚════════════════════════════════════════════════════╝" RESET 
		"\n");
}

void	ft_param(t_map *fdf)
{
	fdf->x_margin = (WINDOW_WIDTH / 2.5);
	fdf->y_margin = (WINDOW_HEIGHT / 2.5);
	fdf->angle = 0.523599;
	fdf->x_scale = 0.54 * (WINDOW_WIDTH / fdf->width);
	fdf->y_scale = 0.54 * (WINDOW_HEIGHT / fdf->heigth);
	fdf->z_scale = 1;
}

void	set_start(t_axis *axis, t_map *fdf)
{
	axis->x *= fdf->x_scale;
	axis->x1 *= fdf->x_scale;
	axis->y *= fdf->y_scale;
	axis->y1 *= fdf->y_scale;
}

void	put_axis(t_axis *axis, t_map *fdf)
{
	axis->x += fdf->x_margin;
	axis->x1 += fdf->x_margin;
	axis->y += fdf->y_margin;
	axis->y1 += fdf->y_margin;
}

void	set_color(t_axis *axis, t_map *fdf)
{
	if (axis->z > 0 || axis->z1 > 0)
		fdf->color = GREEN_PIXEL;
	else if (axis->z < 0 || axis->z1 < 0)
		fdf->color = RED_PIXEL;
	else
		fdf->color = WHITE_PIXEL;
}