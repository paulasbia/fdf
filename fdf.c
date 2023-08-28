/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:47:09 by paulabiazot       #+#    #+#             */
/*   Updated: 2023/08/28 17:05:04 by paula            ###   ########.fr       */
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

int	deal_key(int key, void *data)
{
	ft_printf("%d", key);
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

int	main(int ac, char **av)
{
	t_map	*fdf;

	//	t_axis	*axis;
	// int		i;
	// int		j;
	check_av(ac, av);
	fdf = (t_map *)malloc(sizeof(t_map));
	//	axis = (t_axis *)malloc(sizeof(t_axis));
	printf("sizeof de t_map eh: %ld\n", sizeof(t_map));
	if (!fdf)
	{
		printf("deu ruim\n\n");
		error();
	}
	read_maps(fdf, av[1]);
	// i = 0;
	// while (i < fdf->heigth)
	// {
	// 	j = 0;
	// 	while (j < fdf->width)
	// 	{
	// 		ft_printf("%d ", fdf->z_matrix[i][j]);
	// 		j++;
	// 	}
	// 	ft_printf("\n");
	// 	i++;
	// }
	// free_matrix(fdf);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1000, 1000, "FDF");
	//	bresenham_line(10, 10, 600, 300, fdf);
	bresenham_line((t_axis){x:2, y:1, x1:100, y1:200}, fdf);
	mlx_key_hook(fdf->win_ptr, deal_key, NULL);
	mlx_loop(fdf->mlx_ptr);
}
