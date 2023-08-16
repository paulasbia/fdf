/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:11:56 by paula             #+#    #+#             */
/*   Updated: 2023/08/16 13:53:00 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
//     (void)mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
// 	mlx_loop(mlx);
// }

//create a window and destroy it, than we don`t have any leak
// int main(void)
// {
//     void	*mlx_ptr;
//     void	*win_ptr;

//     mlx_ptr = mlx_init();
//     win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
//		"My first window!");
//     mlx_destroy_window(mlx_ptr, win_ptr);
//     mlx_destroy_display(mlx_ptr);
//     free(mlx_ptr);
// }

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

int	handle_keypress(int keysym, void *mlx, void *win)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(mlx, win);
		win = NULL;
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(int x, int y, t_data *img)
{
	while (x < 50)
	{
		my_mlx_pixel_put(img, x, y, 0x00FF00AA);
		x++;
	}
}

int	main(void)
{
	t_data	img;
	void	*mlx;
	void	*mlx_win;
	int		test;

	test = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "First test");
	img.img = mlx_new_image(mlx, WINDOW_HEIGHT, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	draw_line(test, 100, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_hook(mlx_win, KeyPress, KeyPressMask, &handle_keypress, mlx);
	mlx_loop(mlx);
	mlx_destroy_display(mlx);
	free(mlx);
}
