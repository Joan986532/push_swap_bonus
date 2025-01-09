/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:24:02 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/08 11:39:40 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

int	ft_atol(char *str, int *content)
{
	int			i;
	int			num;
	long int	result;

	i = 0;
	num = 1;
	result = 0;
	while (str[i] < 33)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			num *= (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - 48;
	if (result * num > 2147483647 || result * num < -2147483648)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	*content = result * num;
	return (1);
}
