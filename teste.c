/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulabiazotto <paulabiazotto@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:11:56 by paula             #+#    #+#             */
/*   Updated: 2023/08/18 15:55:45 by paulabiazot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "mlx.h"
//#include <X11/X.h>
//#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 700

#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF

//MAC KEYS
# define K_ESC					53
# define K_UP					13
# define K_LEFT					0
# define K_RIGHT				2
# define K_DOWN					1
# define A_UP					0x7E
# define A_DOWN					0x7D
# define A_LEFT					0x7B
# define A_RIGHT				0x7C

/* LINUX KEYS */
/* #define K_ESC 65307
#define K_UP 119
#define K_LEFT 97
#define K_RIGHT 100
#define K_DOWN 115
#define A_UP 65362
#define A_DOWN 65364
#define A_LEFT 65361
#define A_RIGHT 65363
*/

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
// 	if (keysym == K_ESC)
// 	{
// 		mlx_destroy_window(mlx, win);
// 		free(mlx);
// 		exit(0);
// 	}
// 	return (0);
// }

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// int	draw_line(int x, int y, t_data *img, void *mlx, void *win)
// {
// 	while (x < 50)
// 	{
// 		my_mlx_pixel_put(img, x, y, 0x00FF00AA);
// 		x++;
// 	}
// 	mlx_put_image_to_window(mlx, win, img, 0, 0);
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
// 	draw_line(test, 100, &img, &mlx, &mlx_win);
// 	//mlx_loop_hook(mlx, &draw_line, mlx);

// 	//mlx_hook(mlx_win, KeyPress, KeyPressMask, &handle_keypress, mlx);
// 	mlx_key_hook(mlx_win, &handle_keypress, mlx);
// 	mlx_loop(mlx);
// 	mlx_destroy_display(mlx);
// 	free(mlx);
// }

//draw a pixel and exit

#define MLX_ERROR 1

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}			t_data;

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}			t_rect;

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

/* The x and y coordinates of the rect corresponds to its upper left corner. */
int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == K_ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	return (0);
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, WHITE_PIXEL);
	render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100,
			100, 100, GREEN_PIXEL});
	render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0,
			0);
	return (0);
}

int	main(void)
{
	t_data	data;
	int		fd;
	char	*line;

	fd = open("teste.txt", O_RDONLY);
	line = get_next_line(fd);
	printf(" line 1 %s\n\n", line);
	free(line);
	line = get_next_line(fd);
	printf(" line 2 %s\n\n", line);
	free(line);
	line = get_next_line(fd);
	printf(" line 3 %s\n\n", line);
	free(line);
	line = get_next_line(fd);
	printf(" line 4 %s\n\n", line);
	printf("parou\n");
	free(line);

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
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	/* Setup hooks */
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_key_hook(data.win_ptr, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	/* we will exit the loop if there's no window left, and execute this code */
	mlx_destroy_image(data.mlx_ptr, NULL);
	free(data.mlx_ptr);
}
