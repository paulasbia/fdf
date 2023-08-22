/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 09:59:25 by paulabiazot       #+#    #+#             */
/*   Updated: 2023/08/22 15:45:37 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	get_height(char *file)
{
	char	*line;
	int		height;
	int		fd;

	//   printf("entrou higth\n");
	fd = open(file, O_RDONLY, 0777);
	line = get_next_line(fd);
	if (line == 0)
		return (-1);
	height = 0;
	while (line)
	{
		line = get_next_line(fd);
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int	get_width(char *file)
{
	char	*line;
	int		width;
	int		fd;

	//   printf("entrou em width\n");
	fd = open(file, O_RDONLY, 0777);
	line = get_next_line(fd);
	//   printf("linha 1 %s\n\n", line);
	if (line == 0)
		return (-1);
	//   printf("vai contar\n");
	width = ft_wordc(line, ' ');
	free(line);
	close(fd);
	return (width);
}

int	ft_wordc(const char *str, char c)
{
	int	count;

	//   printf("entrou counter\n");
	count = 0;
	while (*str != 0)
	{
		if (*str != c && (*(str + 1) == c || *(str + 1) == 0))
		{
			count++;
		}
		str++;
	}
	// printf("count eh %d\n", count);
	return (count);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**num;
	int		i;

	num = ft_split(line, ' ');
	i = 0;
	while (num[i])
	{
     //   printf("num eh %s\n", num[i]);
		z_line[i] = ft_atoi(num[i]);
     //   printf("z_line[%d] eh %d\n", i, ft_atoi(num[i]));
		free(num[i]);
		i++;
	}
	free(num);
}

void	read_maps(t_data *fdf, char *file)
{
	char    *line;
	int     i;
	int     fd;

	fdf->width = get_width(file);
	printf("width eh %d\n", fdf->width);
	fdf->heigth = get_height(file);
	printf("heigth eh %d\n", fdf->heigth);
	fdf->z_matrix = (int **)malloc(sizeof(int *) * (fdf->heigth + 1));
	if (!fdf->z_matrix)
		error();
	i = 0;
	while (i <= fdf->heigth)
		fdf->z_matrix[i++] = (int *)malloc(sizeof(int) * (fdf->width + 1));
	fd = open(file, O_RDONLY, 0);
	line = get_next_line(fd);
    printf("para z o line eh %s\n", line);
	i = 0;
	while (line)
	{
		fill_matrix(fdf->z_matrix[i], line);
		i++;
        line = get_next_line(fd);
	}
	close(fd);
	fdf->z_matrix[i] = 0;
}