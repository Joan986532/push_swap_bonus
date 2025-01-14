/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:16:48 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/14 16:29:10 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

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
				free(args_joined);
				return (0);
			}
		}
	}
	if (stack_a)
		ft_lstclear(stack_a);
	free(args_joined);
	return (1);
}
