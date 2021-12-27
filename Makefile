# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keshav <keshav@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/24 13:56:32 by keshav            #+#    #+#              #
#    Updated: 2021/12/24 14:30:32 by keshav           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FONT_COLOR_GREEN = '\033[1;36m'
FONT_COLOR_RED = '\033[1;31m'
FONT_COLOR_DEFAULT = '\033[0m'

NAME		= 	push_swap
LIBFT		= 	libft
SRC			= 	pushswap.c 
SRCS		= 	ft_helpers.c ft_push.c ft_rotate.c ft_sort.c ft_swap.c \
		  		ft_fastsort.c ft_values.c ft_array.c \
		  		ft_fasthelp.c ft_memory.c ft_lists.c ft_minisort.c \
		 		ft_atol.c

CC			= 	gcc
FLAGS		= 	-Wall -Wextra -Werror
RM			= 	rm -f

$(NAME)	:	$(SRCS) $(LIBFT)
			@make bonus -C $(LIBFT)
			@$(CC) $(FLAGS) $(SRC) $(SRCS) -L$(LIBFT) -lft -o $(NAME)
			@echo $(FONT_COLOR_GREEN)[executable files created]$(FONT_COLOR_DEFAULT)
			@echo $(FONT_COLOR_GREEN)[objects file compiled]$(FONT_COLOR_DEFAULT)

all	: 	$(NAME)
		
fclean	: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT)
	@echo $(FONT_COLOR_RED)[executable files deleted]$(FONT_COLOR_DEFAULT)

clean	: 
	@make clean -C $(LIBFT)
	@echo $(FONT_COLOR_RED)[objects files deleted]$(FONT_COLOR_DEFAULT)

re	: fclean all
