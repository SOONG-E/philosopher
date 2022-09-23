# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 13:33:02 by yujelee           #+#    #+#              #
#    Updated: 2022/09/23 15:00:12 by yujelee          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=thread

SRCS = 	philo.c				\
		actions.c			\
		actions_utils.c		\
		initialization.c	\
		utils/ft_atoi.c 	\
		manage_time.c		\
		manage_mutex.c

NAME = philo

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
	
re : 
	make fclean
	make all

.PHONY: all clean fclean re
