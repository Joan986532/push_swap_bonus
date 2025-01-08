/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:37:08 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/08 11:36:09 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		ft_isdigit(int c);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	int				index_a;
	int				rtt_a;
	int				rtt_b;
	int				total;
	int				best_index;
	int				closest;
}					t_list;

t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);

#endif
