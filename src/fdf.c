/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:47:09 by paulabiazot       #+#    #+#             */
/*   Updated: 2023/08/31 11:21:08 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	check_av(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".fdf", 4))
			exit_error("[fdf] ERROR - Invalid file extension\n");
	}
	else
		exit_error("ERROR - Please enter whith one, and just one, argument\n");
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
	init_img(fdf);
	draw_file(fdf);
	mlx_key_hook(fdf->win_ptr, deal_key, fdf);
	mlx_hook(fdf->win_ptr, 17, 0L, close_img, fdf);
	mlx_loop(fdf->mlx_ptr);
}
