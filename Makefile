# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 13:43:15 by lannur-s          #+#    #+#              #
#    Updated: 2023/10/24 08:40:45 by lannur-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
LIBFTNAME = libft.a

CC = cc -g3
CCFLAGS = -Wall -Werror -Wextra

AR = ar
ARFLAGS = -rcs

LIBFT_DIR = ./include/libft_combined

INCLUDES = -I./include -I$(LIBFT_DIR)/include

SRCS = src/mandatory/push_swap.c \
		src/mandatory/validator.c \
		src/mandatory/operations/generic_ops.c \
		src/mandatory/operations/wrapper_push.c \
		src/mandatory/operations/wrapper_reverse_rotate.c \
		src/mandatory/operations/wrapper_rotate.c \
		src/mandatory/operations/wrapper_swap.c		
#		src/mandatory/free.c \
#		src/mandatory/print.c \

BONUS_SRCS = src/bonus/checker.c \
		
OBJS = $(SRCS:%.c=%.o)

BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)

$(NAME): $(LIBFT_DIR)/$(LIBFTNAME) $(OBJS)
	$(CC) $(CCFLAGS) $(SRCS) $(LIBFT_DIR)/$(LIBFTNAME) $(INCLUDES) -o ${NAME}

$(BONUS_NAME): $(LIBFT_DIR)/$(LIBFTNAME) $(BONUS_OBJS)
	$(CC) $(CCFLAGS) $(BONUS_SRCS) $(LIBFT_DIR)/$(LIBFTNAME) $(INCLUDES) -o ${BONUS_NAME}

$(LIBFT_DIR)/$(LIBFTNAME):
	make -C $(LIBFT_DIR)

%.o: %.c $(HEADERS)
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

bonus: $(BONUS_NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	cd $(LIBFT_DIR) && make clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	cd $(LIBFT_DIR) && make fclean

re: fclean
	make

.PHONY: all clean fclean re
