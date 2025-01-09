/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:32:33 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/06 13:33:31 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_find_best_index(t_list **stack_a)
{
	int		best;
	int		index;
	t_list	*temp_a;

	temp_a = *stack_a;
	index = temp_a->index_a;
	best = temp_a->total;
	while (temp_a)
	{
		if (temp_a->best_index >= 0 && temp_a->total < best)
		{
			best = temp_a->total;
			index = temp_a->index_a;
		}
		temp_a = temp_a->next;
	}
	return (index);
}

void	ft_value_min(t_list *stk_a, t_list **stk_b)
{
	t_list	*temp_b;
	int		i;

	temp_b = *stk_b;
	i = -1;
	stk_a->closest = temp_b->content;
	while (temp_b)
	{
		++i;
		if (stk_a->closest <= temp_b->content)
		{
			stk_a->best_index = i;
			stk_a->closest = temp_b->content;
			if (stk_a->best_index > ft_lstsize(*stk_b) / 2 + 1)
			{
				stk_a->best_index = ft_lstsize(*stk_b) - stk_a->best_index;
				stk_a->rtt_b = -1;
			}
			stk_a->total = stk_a->best_index + stk_a->index_a;
		}
		temp_b = temp_b->next;
	}
}

int	ft_best_cost(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*temp_a;
	t_list	*temp_b;

	i = -1;
	temp_a = *stack_a;
	temp_b = *stack_b;
	while (temp_a)
	{
		i++;
		ft_bzero_list(temp_a);
		temp_a->index_a = i;
		if (temp_a->index_a > ft_lstsize(*stack_a) / 2 + 1)
		{
			temp_a->index_a = ft_lstsize(*stack_a) - temp_a->index_a;
			temp_a->rtt_a = -1;
		}
		ft_cost_b(temp_a, &temp_b);
		if (temp_a->best_index == -1)
			ft_value_min(temp_a, &temp_b);
		temp_a->index_a = i;
		temp_a = temp_a->next;
	}
	return (ft_find_best_index(stack_a));
}

void	ft_cost_b(t_list *stk_a, t_list **stk_b)
{
	int		i;
	t_list	*tmp;

	i = -1;
	tmp = *stk_b;
	while (tmp)
	{
		i++;
		if (tmp->content < stk_a->content && tmp->content >= stk_a->closest)
		{
			stk_a->closest = tmp->content;
			stk_a->best_index = i;
			if (stk_a->best_index > ft_lstsize(*stk_b) / 2 + 1)
			{
				stk_a->best_index = ft_lstsize(*stk_b) - stk_a->best_index;
				stk_a->rtt_b = -1;
			}
			stk_a->total = stk_a->best_index + stk_a->index_a;
		}
		tmp = tmp->next;
	}
}
