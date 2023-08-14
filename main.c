/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:11:56 by paula             #+#    #+#             */
/*   Updated: 2023/08/14 15:24:00 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "mlx.h"

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
//     (void)mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
// 	mlx_loop(mlx);
// }

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_data	img;
	void	*mlx;
	void	*mlx_win;
    int     test = 0;
   // (void)mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 800, "First test");
	img.img = mlx_new_image(mlx, 1000, 800);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    ft_printf("valor bpp: %d, line_length %d and endian %d\n", img.bits_per_pixel, img.line_length, img.endian);
    while (test < 50)
    {
        my_mlx_pixel_put(&img, 20, test, 0x00FF0000);
        test++;
    }
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
