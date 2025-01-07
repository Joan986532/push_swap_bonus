/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:58:23 by jnauroy           #+#    #+#             */
/*   Updated: 2025/01/07 17:04:54 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECKER_H
# define CHECKER_H

# include "GNL/get_next_line.h"
# include "Libft_checker/libft.h"

enum commands { SB = 1, PB, RB, RRB, SA, PA, RA, RRA, SS, RR, RRR };

//checker
int main(int argc, char **argv);
void ft_create_instructions(t_list **cmd);
int ft_moove(char *line);

//ft_utils_bonus
int	ft_atol(char *str, int *content);

//algo_bonus
int ft_pars_and_create(int argc, char **argv, t_list **stack_a);

//ft_check_bonus
int ft_check_syntax(char **str);
int ft_check_wrong_char(char *str);
int ft_check_empty(char *str);
int ft_verification(char *str);
char *ft_parsing(int args, char **arguments);

//ft_check_inputs_bonus
int ft_check_for_int_minmax(char **args);
int ft_create_stack(char *args_joined, t_list **stack_a);
void ft_free(char **arg_split);
int ft_check_for_doubles(t_list **stack_a);
int ft_check_sort(t_list **stack_a);

//a_operations_bonus
void	ft_swap_a(t_list **stack_a, int flag);
void	ft_push_a(t_list **stack_a, t_list **stack_b);
void	ft_rotate_a(t_list **stack_a, int flag);
void	ft_reverse_rotate_a(t_list **stack_a, int flag);

//b_operations_bonus
void	ft_swap_b(t_list **stack_b, int flag);
void	ft_push_b(t_list **stack_b, t_list **stack_a);
void	ft_rotate_b(t_list **stack_b, int flag);
void	ft_reverse_rotate_b(t_list **stack_b, int flag);

//operations_bonus
void	ft_swap(t_list **stack_a, t_list **stack_b);
void	ft_rotate(t_list **stack_a, t_list **stack_b);
void	ft_reverse_rotate(t_list **stack_a, t_list **stack_b);

#endif

