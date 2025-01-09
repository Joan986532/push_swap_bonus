/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:10:04 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/07 17:34:00 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmpbis;

	tmp = *lst;
	if (!*lst)
		return ;
	while (tmp)
	{
		tmpbis = tmp;
		tmp = tmp->next;
		free(tmpbis);
	}
	*lst = NULL;
}
