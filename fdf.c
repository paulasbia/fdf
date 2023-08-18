/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulabiazotto <paulabiazotto@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:47:09 by paulabiazot       #+#    #+#             */
/*   Updated: 2023/08/18 16:45:16 by paulabiazot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void    check_av(int ac, char **av)
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

int main(int ac, char **av)
{
    int fd;

    check_av(ac, av);
    fd = open(av[1], O_RDONLY, 0777);
    if (fd < 0)
        error();
}