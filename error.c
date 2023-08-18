/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulabiazotto <paulabiazotto@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:28:06 by paulabiazot       #+#    #+#             */
/*   Updated: 2023/08/18 16:49:45 by paulabiazot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

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