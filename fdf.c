/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:47:09 by paulabiazot       #+#    #+#             */
/*   Updated: 2023/08/24 18:29:57 by paula            ###   ########.fr       */
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

void	free_matrix(t_data *fdf)
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
	t_data	*fdf;
	int		i;
	int		j;

	check_av(ac, av);
	fdf = (t_data *)malloc(sizeof(t_data));
	printf("sizeof de t_data eh: %ld\n", sizeof(t_data));
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
	free_matrix(fdf);
}
