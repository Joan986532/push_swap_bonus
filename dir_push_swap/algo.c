/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:16:48 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/06 13:14:37 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_main_algo(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 4)
	{
		ft_short_sort(stack_a);
		return ;
	}
	ft_push_b(stack_b, stack_a);
	if (ft_lstsize(*stack_a) > 3)
	{
		ft_push_b(stack_b, stack_a);
		if ((*stack_b)->content < (*stack_b)->next->content)
			ft_swap_b(stack_b, 0);
	}
	if (ft_lstsize(*stack_a) > 3)
		ft_long_sort(stack_a, stack_b);
	else
		ft_short_sort(stack_a);
	ft_align_repush_stack_b(stack_b, stack_a);
}

int	ft_pars_and_create(int argc, char **argv, t_list **stack_a)
{
	char	*args_joined;

	args_joined = ft_parsing(argc, argv);
	if (args_joined)
	{
		if (ft_create_stack(args_joined, stack_a))
		{
			if (ft_check_for_doubles(stack_a))
			{
				if (ft_check_sort(stack_a))
				{
					free(args_joined);
					return (0);
				}
			}
		}
	}
	if (stack_a)
		ft_lstclear(stack_a);
	free(args_joined);
	return (1);
}
