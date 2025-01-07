/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:25:06 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/06 13:18:52 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_find_min(t_list **stck)
{
	t_list	*tmp_list;
	int		temp;

	tmp_list = *stck;
	temp = tmp_list->content;
	while (tmp_list)
	{
		if (temp > tmp_list->content)
			temp = tmp_list->content;
		tmp_list = tmp_list->next;
	}
	return (temp);
}

int	ft_find_max(t_list **stck)
{
	t_list	*tmp_list;
	int		temp;

	tmp_list = *stck;
	temp = tmp_list->content;
	while (tmp_list)
	{
		if (temp < tmp_list->content)
			temp = tmp_list->content;
		tmp_list = tmp_list->next;
	}
	return (temp);
}
