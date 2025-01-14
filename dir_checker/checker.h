/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:58:23 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/10 17:12:15 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECKER_H
# define CHECKER_H

# include "Libft_checker/libft.h"
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

enum e_commands
{
	SB = 1,
	PB,
	RB,
	RRB,
	SA,
	PA,
	RA,
	RRA,
	SS,
	RR,
	RRR,
};

//checker
int		main(int argc, char **argv);
int		ft_create_instruct(t_list **cmd);
int		ft_checker(t_list **cmd, t_list **stack_a, t_list **stack_b);
int		ft_moove(char *line);
int		ft_main_algo(t_list **cmd, t_list **stack_a, t_list **stack_b);

//ft_utils_bonus
int		ft_atol(char *str, int *content);
void	ft_free_checker(t_list **cmd, t_list **stack_a, t_list **stack_b);

//algo_bonus
int		ft_pars_and_create(int argc, char **argv, t_list **stack_a);

//ft_check_bonus
int		ft_check_syntax(char **str);
int		ft_check_wrong_char(char *str);
int		ft_check_empty(char *str);
int		ft_verification(char *str);
char	*ft_parsing(int args, char **arguments);

//ft_check_inputs_bonus
int		ft_check_for_int_minmax(char **args);
int		ft_create_stack(char *args_joined, t_list **stack_a);
void	ft_free(char **arg_split);
int		ft_check_for_doubles(t_list **stack_a);
int		ft_check_sort(t_list **stack_a);

//a_operations_bonus
void	ft_swap_a(t_list **stack_a);
void	ft_push_a(t_list **stack_a, t_list **stack_b);
void	ft_rotate_a(t_list **stack_a);
void	ft_reverse_rotate_a(t_list **stack_a);

//b_operations_bonus
void	ft_swap_b(t_list **stack_b);
void	ft_push_b(t_list **stack_b, t_list **stack_a);
void	ft_rotate_b(t_list **stack_b);
void	ft_reverse_rotate_b(t_list **stack_b);

//operations_bonus
void	ft_swap(t_list **stack_a, t_list **stack_b);
void	ft_rotate(t_list **stack_a, t_list **stack_b);
void	ft_reverse_rotate(t_list **stack_a, t_list **stack_b);

//get_next_line_utils
size_t	ft_strlen_gnl(char *str);
char	*ft_strchr_gnl(const char *string, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);

//get_next_line
char	*get_next_line(int fd);
char	*ft_write_right(char *buffer);
char	*ft_write_left(char *string);
int		ft_free_gnl(char *buffer, char *temp, char *string, char *sentence);
char	*ft_read_buffer(int fd, char *buffer, char *string);

#endif
