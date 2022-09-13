# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 13:33:02 by yujelee           #+#    #+#              #
#    Updated: 2022/09/13 21:20:00 by yujelee          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	parsing.c			\
		philo.c				\
		actions.c			\
		initialization.c	\
		utils/ft_atoi.c 	\
		utils/manage_time.c

NAME = philo

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $^ -o $@

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
