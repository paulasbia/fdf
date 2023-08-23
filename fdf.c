/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:47:09 by paulabiazot       #+#    #+#             */
/*   Updated: 2023/08/23 09:43:51 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	check_av(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".fdf", 4))
		{
			exit_error("[fdf] ERROR - Invalid file extension");
		}
	}
	else
		exit_error("ERROR - Please enter whith one, and just one, argument\n");
}

int	main(int ac, char **av)
{
	t_data	*fdf;
	int		i;
	int		j;

	check_av(ac, av);
	fdf = (t_data *)malloc(sizeof(t_data));
	if (!fdf)
	{
		printf("deu ruim\n\n");
		error();
	}
	read_maps(fdf, av[1]);
	i = 0;
	while (i < fdf->heigth)
	{
		j = 0;
		while (j < fdf->width)
		{
			ft_printf("%d ", fdf->z_matrix[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}