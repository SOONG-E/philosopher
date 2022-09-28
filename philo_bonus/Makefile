# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 13:33:02 by yujelee           #+#    #+#              #
#    Updated: 2022/09/28 13:56:19 by yujelee          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=thread

SRCS = 	philo_bonus.c		\
		actions.c			\
		actions_utils.c		\
		initialization.c	\
		utils/ft_atoi.c 	\
		utils/ft_itoa.c 	\
		manage_time.c		\
		manage_resource.c	\
		philo_routine.c		\
		manage_processes.c

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
