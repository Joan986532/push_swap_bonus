/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_operations_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 07:50:21 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/14 16:24:22 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	ft_swap_b(t_list **stack_b)
{
	t_list	*head;

	if (*stack_b && (*stack_b)->next)
	{
		head = (*stack_b)->next;
		(*stack_b)->next = head->next;
		head->next = *stack_b;
		*stack_b = head;
	}
}

void	ft_push_b(t_list **stack_b, t_list **stack_a)
{
	t_list	*temp;

	if (*stack_a)
	{
		temp = (*stack_a)->next;
		ft_lstadd_front(stack_b, *stack_a);
		*stack_a = temp;
	}
}

void	ft_rotate_b(t_list **stack_b)
{
	t_list	*ptr;

	if (*stack_b)
	{
		ptr = (*stack_b)->next;
		ft_lstlast(*stack_b)->next = *stack_b;
		(*stack_b)->next = NULL;
		*stack_b = ptr;
	}
}

void	ft_reverse_rotate_b(t_list **stack_b)
{
	t_list	*ptr;

	if (*stack_b)
	{
		ptr = *stack_b;
		if ((*stack_b)->next)
		{
			while ((*stack_b)->next->next != NULL)
				*stack_b = (*stack_b)->next;
			(*stack_b)->next->next = ptr;
			ptr = *stack_b;
			*stack_b = (*stack_b)->next;
			ptr->next = NULL;
		}
	}
}
