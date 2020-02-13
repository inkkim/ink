# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hana <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/11 22:43:11 by hana              #+#    #+#              #
#    Updated: 2020/02/13 08:26:09 by hana             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
SRCS	= srcs/Calmax.c \
		  srcs/ReadAndBuff.c \
		  srcs/SetCharMap.c \
		  srcs/MapConvertCtoI.c
OBJS	= ${SRCS:.c=.o}
FLAGS	= -Wall -Werror -Wextra
INCS	= ./
NAME	= BSQ

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${FLAGS} -o ${NAME} ${OBJS}

.c.o:
	${CC} -c $< -o ${<:.c=.o} -I${INCS}

RM		= rm -f

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
