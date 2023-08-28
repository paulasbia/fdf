/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:06:21 by paula             #+#    #+#             */
/*   Updated: 2023/08/28 18:55:04 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_map	**memory_allocate(char *file)
{
	int		fd;
	char	*line;
	int		x;
	int		y;
	t_map	**matrix;

	fd = open(file, O_RDONLY, 0);
	if (fd < 0)
		error();
	line = get_next_line(fd);
	x = ft_wordc(line, ' ');
	y = 0;
	while (line)
	{
		y++;
		free(line);
		line = get_next_line(fd);
	}
	matrix = (t_map **)malloc(sizeof(t_map *) * (y + 1));
	while (y > 0)
		matrix[--y] = (t_map *)malloc(sizeof(t_map) * (x + 1));
	close(fd);
	return (matrix);
}

int	ft_wordc(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str != 0)
	{
		if (*str != c && (*(str + 1) == c || *(str + 1) == 0))
			count++;
		str++;
	}
	return (count);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**num;
	int		i;

	num = ft_split(line, ' ');
	printf("em matrix line eh\n%s", line);
	i = 0;
	while (num[i])
	{
		printf("em matrix line%d\n%s\n", i, num[i]);
		z_line[i] = ft_atoi(num[i]);
		free(num[i]);
		i++;
	}
	free(line);
	free(num);
}

void	read_maps(t_map *fdf, char *file)
{
	int i;
	char *line;
	int fd;
	t_map **matrix;

	matrix = memory_allocate(file);
	fd = open(file, O_RDONLY, 0);
	line = get_next_line(fd);
	if (fd > 0)
		error();
	i = 0;
	while (line)
	{
		fill_matrix(fdf->z_matrix[i], line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	fdf->z_matrix[i] = NULL;
	close(fd);
}