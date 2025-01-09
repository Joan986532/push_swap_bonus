/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_operations_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 07:50:21 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/08 14:48:56 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	ft_swap_a(t_list **stack_a)
{
	t_list	*head;

	if (*stack_a && (*stack_a)->next)
	{
		head = (*stack_a)->next;
		(*stack_a)->next = head->next;
		head->next = *stack_a;
		*stack_a = head;
	}
}

void	ft_push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_b)
	{
		temp = (*stack_b)->next;
		ft_lstadd_front(stack_a, *stack_b);
		*stack_b = temp;
	}
}

void	ft_rotate_a(t_list **stack_a)
{
	t_list	*ptr;

	if (*stack_a)
	{
		ptr = (*stack_a)->next;
		ft_lstlast(*stack_a)->next = *stack_a;
		(*stack_a)->next = NULL;
		*stack_a = ptr;
	}
}

void	ft_reverse_rotate_a(t_list **stack_a)
{
	t_list	*ptr;

	if (*stack_a)
	{
		ptr = *stack_a;
		while ((*stack_a)->next->next != NULL)
			*stack_a = (*stack_a)->next;
		(*stack_a)->next->next = ptr;
		ptr = *stack_a;
		*stack_a = (*stack_a)->next;
		ptr->next = NULL;
	}
}
