/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:47:09 by paulabiazot       #+#    #+#             */
/*   Updated: 2023/09/07 16:28:32 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	check_av(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".fdf", 4))
			exit_error("Invalid extension, Ex:./fdf ./maps./42maps/42.fdf\n");
	}
	else
		exit_error("Please enter whith one, and just one, argument!\n");
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
	ft_param(fdf);
}

void	free_matrix(t_map *fdf)
{
	int	i;

	i = 0;
	while (fdf->z_matrix[i])
	{
		free(fdf->z_matrix[i]);
		i++;
	}
	free(fdf->z_matrix);
	free(fdf);
}

int	close_img(t_map *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->img->mlx_img);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	free(fdf->img);
	mlx_destroy_display(fdf->mlx_ptr);
	free(fdf->mlx_ptr);
	free_matrix(fdf);
	exit(0);
}

int	main(int ac, char **av)
{
	t_map	*fdf;

	check_av(ac, av);
	fdf = (t_map *)malloc(sizeof(t_map));
	fdf->img = malloc(sizeof(t_img));
	if (!fdf || !fdf->img)
		error();
	read_maps(fdf, av[1]);
	ft_instruction();
	init_img(fdf);
	draw_file(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img->mlx_img, 0, 0);
	mlx_key_hook(fdf->win_ptr, deal_key, fdf);
	mlx_hook(fdf->win_ptr, 17, 0L, close_img, fdf);
	mlx_loop(fdf->mlx_ptr);
}
