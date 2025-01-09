/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:33:14 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/09 13:58:56 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

int	ft_moove(char *line)
{
	if (!ft_memcmp(line, "sb\n", 3))
		return (SB);
	else if (!ft_memcmp(line, "pb\n", 3))
		return (PB);
	else if (!ft_memcmp(line, "rb\n", 3))
		return (RB);
	else if (!ft_memcmp(line, "rrb\n", 4))
		return (RRB);
	else if (!ft_memcmp(line, "sa\n", 3))
		return (SA);
	else if (!ft_memcmp(line, "pa\n", 3))
		return (PA);
	else if (!ft_memcmp(line, "ra\n", 3))
		return (RA);
	else if (!ft_memcmp(line, "rra\n", 4))
		return (RRA);
	else if (!ft_memcmp(line, "ss\n", 3))
		return (SS);
	else if (!ft_memcmp(line, "rr\n", 3))
		return (RR);
	else if (!ft_memcmp(line, "rrr\n", 4))
		return (RRR);
	return (0);
}

void	ft_create_instructions(t_list **cmd)
{
	char	*line;
	int		value;

	line = get_next_line(0);
	while (line)
	{
		value = ft_moove(line);
		free(line);
		ft_lstadd_back(cmd, ft_lstnew(value));
		line = get_next_line(0);
	}
	free(line);
	close(0);
}

void	ft_checker(t_list **cmd, t_list **stack_a, t_list **stack_b)
{
	if ((*cmd)->content == SB)
		ft_swap_b(stack_b);
	else if ((*cmd)->content == PB)
		ft_push_b(stack_b, stack_a);
	else if ((*cmd)->content == RB)
		ft_rotate_b(stack_b);
	else if ((*cmd)->content == RRB)
		ft_reverse_rotate_b(stack_b);
	else if ((*cmd)->content == SA)
		ft_swap_a(stack_a);
	else if ((*cmd)->content == PA)
		ft_push_a(stack_a, stack_b);
	else if ((*cmd)->content == RA)
		ft_rotate_a(stack_a);
	else if ((*cmd)->content == RRA)
		ft_reverse_rotate_a(stack_a);
	else if ((*cmd)->content == SS)
		ft_swap(stack_a, stack_b);
	else if ((*cmd)->content == RR)
		ft_rotate(stack_a, stack_b);
	else if ((*cmd)->content == RRR)
		ft_reverse_rotate(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*cmd;
	t_list	*tmp;

	stack_a = NULL;
	stack_b = NULL;
	cmd = NULL;
	if (ft_pars_and_create(argc, argv, &stack_a))
		return (1);
	ft_create_instructions(&cmd);
	tmp = cmd;
	while (tmp)
	{
		ft_checker(&tmp, &stack_a, &stack_b);
		tmp = tmp->next;
	}
	if (!ft_check_sort(&stack_a) && ft_lstsize(stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	ft_lstclear(&cmd);
}
