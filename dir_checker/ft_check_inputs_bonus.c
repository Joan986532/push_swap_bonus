/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_inputs_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:01:52 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/14 11:47:42 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

int	ft_check_for_int_minmax(char **args)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (args[i])
	{
		j = 0;
		count = 0;
		if (args[i][j] == '-' || args[i][j] == '+')
			j++;
		while (args[i][j] == '0')
			j++;
		while (args[i][j] >= '0' && args[i][j] <= '9')
		{
			count++;
			j++;
		}
		if (count > 10)
			return (0);
		i++;
	}
	return (1);
}

int	ft_create_stack(char *args_joined, t_list **stack_a)
{
	char	**arg_s;
	int		content;
	int		i;

	i = 0;
	arg_s = ft_split(args_joined, ' ');
	if (arg_s && ft_check_syntax(arg_s) && ft_check_for_int_minmax(arg_s))
	{
		while (arg_s[i])
		{
			content = 0;
			if (!ft_atol(arg_s[i], &content))
			{
				ft_free(arg_s);
				return (0);
			}
			ft_lstadd_back(stack_a, ft_lstnew(content));
			i++;
		}
		ft_free(arg_s);
		return (1);
	}
	ft_free(arg_s);
	write(2, "Error\n", 6);
	return (0);
}

void	ft_free(char **arg_split)
{
	int	i;

	i = 0;
	if (arg_split)
	{
		while (arg_split[i] != NULL)
			i++;
		while (i >= 0)
		{
			free(arg_split[i]);
			i--;
		}
	}
	free(arg_split);
}

int	ft_check_for_doubles(t_list **stack_a)
{
	int		temp;
	t_list	*list_temp;
	t_list	*list_temp2;

	list_temp = *stack_a;
	while (list_temp->next != NULL)
	{
		list_temp2 = list_temp->next;
		temp = list_temp->content;
		while (list_temp2 != NULL)
		{
			if (temp == list_temp2->content)
			{
				ft_lstclear(stack_a);
				write(2, "Error\n", 6);
				return (0);
			}
			list_temp2 = list_temp2->next;
		}
		list_temp = list_temp->next;
	}
	return (1);
}

int	ft_check_sort(t_list **stack_a)
{
	t_list	*temp1;
	t_list	*temp2;
	int		count;
	if (*stack_a)
	{
		temp1 = *stack_a;
		temp2 = temp1->next;
		count = 0;
		while (temp2 != NULL)
		{
			if (temp1->content > temp2->content)
				count++;
			temp2 = temp2->next;
			temp1 = temp1->next;
		}
		if (count == 0)
			return (0);
	}
	return (1);
}
