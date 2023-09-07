/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:01:22 by jhogonca          #+#    #+#             */
/*   Updated: 2023/08/11 17:01:22 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_atoi_base_aux(const char *str, int i, int base)
{
	int	result;

	result = 0;
	while ((str[i] >= '0' && str[i] <= '9')
		|| (base == 16 && str[i] >= 'A' && str[i] <= 'F')
		|| (base == 16 && str[i] >= 'a' && str[i] <= 'f'))
	{
		if (str[i] >= 'A' && str[i] <= 'F')
			result = result * base + (str[i] - 'A' + 10);
		else if (str[i] >= 'a' && str[i] <= 'f')
			result = result * base + (str[i] - 'a' + 10);
		else
			result = result * base + (str[i] - '0');
		i++;
		if (result < 0)
			return (0);
	}
	return (result);
}

static int	is_hex(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n' && str[i] != ' ')
	{
		if ((str[i] >= '0' && str[i] <= '9')
			|| (str[i] >= 'A' && str[i] <= 'F')
			|| (str[i] >= 'a' && str[i] <= 'f'))
			i++;
		else
			return (0);
	}
	return (1);
}

static int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi_base(const char *str, int base)
{
	int	sign;
	int	i;
	int	result;

	result = 0;
	sign = 1;
	i = 0;
	if (!str)
		return (0);
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -sign;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (base == 16 && str[i] == '0' && str[i + 1] == 'x')
		i += 2;
	if (base == 16 && is_hex(str + i) == 0)
		return (0);
	result = ft_atoi_base_aux(str, i, base);
	return (result * sign);
}
