/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:11:56 by paula             #+#    #+#             */
/*   Updated: 2023/08/16 14:27:14 by pde-souz         ###   ########.fr       */
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

//Draw a line and exit with esc:

// typedef struct s_data
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }			t_data;

// int	handle_keypress(int keysym, void *mlx, void *win)
// {
// 	if (keysym == XK_Escape)
// 	{
// 		mlx_destroy_window(mlx, win);
// 		win = NULL;
// 	}
// 	return (0);
// }

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// int	draw_line(int x, int y, t_data *img)
// {
// 	while (x < 50)
// 	{
// 		my_mlx_pixel_put(img, x, y, 0x00FF00AA);
// 		x++;
// 	}
// 	return (0);
// }

// int	main(void)
// {
// 	t_data	img;
// 	void	*mlx;
// 	void	*mlx_win;
// 	int		test;

// 	test = 0;
// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "First test");
// 	img.img = mlx_new_image(mlx, WINDOW_HEIGHT, WINDOW_HEIGHT);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 			&img.endian);
// 	draw_line(test, 100, &img);
// 	//mlx_loop_hook(mlx, &draw_line, mlx);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_hook(mlx_win, KeyPress, KeyPressMask, &handle_keypress, mlx);
// 	mlx_loop(mlx);
// 	mlx_destroy_display(mlx);
// 	free(mlx);
// }

//draw a pixel and exit

#define MLX_ERROR 1

#define RED_PIXEL 0xFF0000

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_data;

#define GREEN_PIXEL 0xFF00

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}			t_rect;

/* The x and y coordinates of the rect corresponds to its upper left corner. */

int	render_rect(t_data *data, t_rect rect)
{
	int	i;
	int	j;

	if (data->win_ptr == NULL)
		return (1);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, rect.color);
		++i;
	}
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

int	render(t_data *data)
{
	// /* if window has been destroyed, we don't want to put the pixel ! */
	// if (data->win_ptr != NULL)
	// 	mlx_pixel_put(data->mlx_ptr, data->win_ptr, WINDOW_WIDTH / 2,
	// 		WINDOW_HEIGHT / 2, RED_PIXEL);
	// return (0);
	render_rect(data, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100,
		100, GREEN_PIXEL});
	render_rect(data, (t_rect){0, 0, 100, 100, RED_PIXEL});
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"my window");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	/* Setup hooks */
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	/* we will exit the loop if there's no window left, and execute this code */
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
