# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 17:28:28 by jnauroy           #+#    #+#              #
#    Updated: 2025/01/07 17:28:33 by jnauroy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

MY_SOURCES = a_operations.c \
	     best_index.c \
	     b_operations.c \
	     ft_check.c \
	     ft_check_inputs.c \
	     ft_repush_end.c \
	     ft_utils.c \
		 ft_utils_2.c \
	     long_sort.c \
	     operations.c \
	     push_swap.c \
	     short_sort.c \
		 algo.c 

LIBFT = Libft_pushswap/libft.a

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	@make -C Libft_pushswap
	gcc  $(CFLAGS) $(MY_OBJECTS) $(LIBFT) -o $(NAME)

clean:
	@make clean -C Libft_pushswap
	rm -f $(MY_OBJECTS)
fclean: clean
	@make fclean -C Libft_pushswap
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean

