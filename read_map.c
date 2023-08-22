/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulabiazotto <paulabiazotto@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 09:59:25 by paulabiazot       #+#    #+#             */
/*   Updated: 2023/08/22 13:30:15 by paulabiazot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int get_height(int fd)
{
    char    *line;
    int     height;

 //   printf("entrou higth\n");
    line = get_next_line(fd);
    if (line == 0)
        return(-1);
    height = 1;
    while (line)
    {
        line = get_next_line(fd);
        height++;
        free(line);
    }
    close(fd);
    return(height);
}

int get_width(int fd)
{
    char    *line;
    int     width;

 //   printf("entrou em width\n");
    line = get_next_line(fd);
 //   printf("linha 1 %s\n\n", line);
    if (line == 0)
        return(-1);
 //   printf("vai contar\n");
    width = ft_wordc(line, ' ');
    free(line);
    return(width);
}

int ft_wordc(const char *str, char c)
{
 //   printf("entrou counter\n");
	int	count;

	count = 1;
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

void    fill_matrix(int *z_line, char *line)
{
    char    **num;
    int     i;

    num = ft_split(line, ' ');
    i = 0;
    while (num[i])
    {
        z_line[i] = ft_atoi(num[i]);
        free(num[i]);
        i++;
    }
    free(num);
}

void    read_maps(t_data *fdf, int fd)
{
    char    *line;
    int     i;
    int     temp;
 //   printf("entrou\n");
    temp = fd;
    fdf->width = get_width(temp);
    printf("width eh %d\n", fdf->width);
    fdf->heigth = get_height(temp);
    printf("heigth eh %d\n", fdf->heigth);
    fdf->z_matrix = (int**)malloc(sizeof(int) * (fdf->heigth + 1));
    if (!fdf->z_matrix)
        error();
    i = 0;
    while (i <= fdf->heigth)
        fdf->z_matrix[i++] = (int*)malloc(sizeof(int) * (fdf->width + 1));
    i = 0;
    line = get_next_line(fd);
    printf("para z o line eh %s\n", line);
    while (line)
    {
        fill_matrix(fdf->z_matrix[i], line);
        free(line);
        i++;
    }
    fdf->z_matrix[i] = 0;
}