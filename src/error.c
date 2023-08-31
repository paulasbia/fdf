/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:28:06 by paulabiazot       #+#    #+#             */
/*   Updated: 2023/08/31 11:12:13 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	exit_error(const char *msg)
{
	ft_printf("\033[31mERROR - %s\e[0m", msg);
	exit(EXIT_FAILURE);
}

void	error(void)
{
	perror("error");
	exit(EXIT_FAILURE);
}
