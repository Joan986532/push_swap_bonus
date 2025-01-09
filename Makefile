# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 17:28:28 by jnauroy           #+#    #+#              #
#    Updated: 2025/01/09 14:15:45 by jnauroy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
PROJECT_DIR = dir_push_swap

NAME_BONUS = checker
BONUS_DIR = dir_checker

MY_SOURCES = $(PROJECT_DIR)/a_operations.c \
	     $(PROJECT_DIR)/best_index.c \
	     $(PROJECT_DIR)/b_operations.c \
	     $(PROJECT_DIR)/ft_check.c \
	     $(PROJECT_DIR)/ft_check_inputs.c \
	     $(PROJECT_DIR)/ft_repush_end.c \
	     $(PROJECT_DIR)/ft_utils.c \
		 $(PROJECT_DIR)/ft_utils_2.c \
	     $(PROJECT_DIR)/long_sort.c \
	     $(PROJECT_DIR)/operations.c \
	     $(PROJECT_DIR)/push_swap.c \
	     $(PROJECT_DIR)/short_sort.c \
		 $(PROJECT_DIR)/algo.c 

MY_SOURCES_BONUS = $(BONUS_DIR)/algo_bonus.c \
				   $(BONUS_DIR)/a_operations_bonus.c \
				   $(BONUS_DIR)/b_operations_bonus.c \
				   $(BONUS_DIR)/checker.c \
				   $(BONUS_DIR)/ft_check_bonus.c \
				   $(BONUS_DIR)/ft_check_inputs_bonus.c \
				   $(BONUS_DIR)/ft_utils_bonus.c \
				   $(BONUS_DIR)/get_next_line.c \
				   $(BONUS_DIR)/get_next_line_utils.c \
				   $(BONUS_DIR)/operations_bonus.c

LIBFT = dir_push_swap/Libft_pushswap/libft.a
LIBFT_BONUS = dir_checker/Libft_checker/libft.a

MY_OBJECTS = $(MY_SOURCES:.c=.o)
MY_OBJECTS_BONUS = $(MY_SOURCES_BONUS:.c=.o)

CFLAGS = -g -Wall -Wextra -Werror

#-------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	$(MAKE) -C dir_push_swap/Libft_pushswap
	cc  $(CFLAGS) $(MY_OBJECTS) $(LIBFT) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(MY_OBJECTS_BONUS)
	$(MAKE) -C dir_checker/Libft_checker
	cc $(CFLAGS) $(MY_OBJECTS_BONUS) $(LIBFT_BONUS) -o $(NAME_BONUS)

clean:
	$(MAKE) clean -C dir_checker/Libft_checker
	$(MAKE) clean -C dir_push_swap/Libft_pushswap
	rm -f $(MY_OBJECTS) $(MY_OBJECTS_BONUS)
fclean: clean
	$(MAKE) fclean -C dir_checker/Libft_checker
	$(MAKE) fclean -C dir_push_swap/Libft_pushswap
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all
rebonus: fclean bonus

.PHONY: all clean fclean re rebonus bonus
