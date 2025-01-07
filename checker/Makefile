# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 17:21:45 by jnauroy           #+#    #+#              #
#    Updated: 2025/01/07 17:45:28 by jnauroy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

MY_SOURCES = checker.c \
		  ft_utils_bonus.c \
		  ft_utils_bonus.c \
		  algo_bonus.c \
		  ft_check_inputs_bonus.c \
		  a_operations_bonus.c \
		  b_operations_bonus.c \
		  operations_bonus.c \

MY_OBJECTS = $(MY_SOURCES:.c=.o)

LIBFT = Libft_checker/libft.a

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C Libft_checker
	gcc $(CFLAGS) $(MY_OBJECTS) $(LIBFT) -o $(NAME)

clean:
	@make clean -C Libft_checker
	rm -f $(MY_OBJECTS)
fclean: clean
	@make fclean -C Libft_checker
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean



