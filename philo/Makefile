# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 13:33:02 by yujelee           #+#    #+#              #
#    Updated: 2022/10/14 15:47:53 by yujelee          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL := all

CC = $Qcc
CFLAGS = -Wall -Wextra -Werror -MMD -MP -pthread

Q = @
ifdef DEBUG
	Q = 
endif

SRCS = 	philo.c				\
		actions.c			\
		actions_utils.c		\
		initialization.c	\
		utils/ft_atoi.c 	\
		manage_time.c		\
		manage_resource.c

NAME = philo

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
-include $(DEPS)

all : $(NAME)

$(NAME) : $(OBJS)

clean :
	$Q$(RM) $(OBJS) $(DEPS)

fclean : clean
	$Q$(RM) $(NAME)
	
re : 
	$Q$(MAKE) fclean
	$Q$(MAKE) all

.PHONY: all clean fclean re