/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:47:09 by paulabiazot       #+#    #+#             */
/*   Updated: 2023/08/29 19:45:21 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	check_av(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".fdf", 4))
			exit_error("[fdf] ERROR - Invalid file extension");
	}
	else
		exit_error("ERROR - Please enter whith one, and just one, argument\n");
}

int	deal_key(int key, t_map *fdf)
{
	if (key == A_UP)
		fdf->y_margin += 5;
	else if (key == A_DOWN)
		fdf->y_margin -= 5;
	else if (key == A_RIGHT)
		fdf->x_margin += 10;
	else if (key == A_LEFT)
		fdf->x_margin -= 10;
	else if (key == K_ESC)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		free(fdf->mlx_ptr);
		exit(0);
	}
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw_file(fdf);
	return (0);
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

// need change
int	close_img(t_map *fdf)
{
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	free(fdf->mlx_ptr);
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
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"FDF");
	if (fdf->win_ptr == NULL)
	{
		free(fdf->win_ptr);
		error ();
	}
	fdf->x_margin = 450;
	fdf->y_margin = 5;
	draw_file(fdf);
	mlx_key_hook(fdf->win_ptr, deal_key, fdf);
	mlx_hook(fdf->win_ptr, 17, 0L, close_img, fdf);
	mlx_loop(fdf->mlx_ptr);
}
