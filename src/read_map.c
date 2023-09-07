/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 09:59:25 by paulabiazot       #+#    #+#             */
/*   Updated: 2023/09/07 17:23:07 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_height(char *file)
{
	char	*line;
	int		height;
	int		fd;

	fd = open(file, O_RDONLY, 0777);
	if (fd < 0)
		error();
	line = get_next_line(fd);
	if (line == 0)
		exit_error("Empty line\n");
	height = 0;
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
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

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**num;
	int		i;
	char	**components;

	num = ft_split(line, ' ');
	i = 0;
	while (num[i])
	{
		components = ft_split(num[i], ',');
		z_line[i] = ft_atoi(components[0]);
		free(num[i]);
		ft_free_split(components);
		i++;
	}
	free(line);
	free(num);
}

void	pre_fill(t_map *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->heigth)
	{
		fdf->z_matrix[i++] = (int *)malloc(sizeof(int) * (fdf->width + 1));
		if (!fdf->z_matrix)
			error();
	}
}

void	read_maps(t_map *fdf, char *file)
{
	char	*line;
	int		i;
	int		fd;

	fdf->heigth = get_height(file);
	fdf->z_matrix = (int **)malloc(sizeof(int *) * (fdf->heigth + 1));
	if (!fdf->z_matrix)
		error();
	fd = open(file, O_RDONLY, 0);
	if (fd < 0)
		error();
	line = get_next_line(fd);
	fdf->width = ft_wordc(line, ' ');
	pre_fill(fdf);
	i = 0;
	while (line)
	{
		fill_matrix(fdf->z_matrix[i], line);
		line = get_next_line(fd);
		i++;
	}
	fdf->z_matrix[i] = NULL;
	close(fd);
}
