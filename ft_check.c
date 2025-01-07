/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 07:45:42 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/06 16:29:17 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_check_syntax(char **str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i = 0;
		while ((*str)[i] != '\0')
		{
			while ((*str)[i] == ' ')
				i++;
			if ((*str)[i] == '-' || (*str)[i] == '+')
				i++;
			if (!ft_isdigit((int)(*str)[i]))
				return (0);
			while ((*str)[i])
			{
				if (!ft_isdigit((int)(*str)[i]))
					return (0);
				i++;
			}
		}
		str++;
	}
	return (1);
}

int	ft_check_wrong_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit((int)str[i]))
			if (str[i] != '-' && str[i] != '+' && str[i] != ' ')
				return (0);
		i++;
	}
	if (i == 1)
	{
		i = 0;
		if (!ft_isdigit((int)str[i]))
			return (0);
	}
	return (1);
}

int	ft_check_empty(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			flag++;
		i++;
	}
	if (flag == 0)
		return (0);
	return (1);
}

int	ft_verification(char *str)
{
	if (ft_check_empty(str))
		if (ft_check_wrong_char(str))
			return (1);
	write(2, "Error\n", 6);
	return (0);
}

char	*ft_parsing(int args, char **arguments)
{
	int		i;
	char	*args_joined;
	char	*temp;

	i = 1;
	args_joined = NULL;
	while (i < args)
	{
		if (!ft_verification(arguments[i]))
		{
			if (args_joined)
				free(args_joined);
			return (0);
		}
		temp = args_joined;
		args_joined = ft_strjoin(temp, arguments[i]);
		if (!args_joined)
		{
			free(args_joined);
			return (0);
		}
		free(temp);
		i++;
	}
	return (args_joined);
}
