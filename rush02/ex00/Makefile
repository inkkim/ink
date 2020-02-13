# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhan <suhan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/08 18:23:03 by suhan             #+#    #+#              #
#    Updated: 2020/02/09 17:17:57 by suhan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = rush-02

CFLAGS = -Wall -Wextra -Werror

INCS = ft.h
SRCS = $(shell ls | grep -E "ft_.+\.c") \
				find_dict.c\
				print.c\
				parse.c\
				main.c
OBJS = ${SRCS:.c=.o}

all: ${TARGET}

%.o: %.c
	gcc ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${TARGET}: ${OBJS}
	gcc ${CFLAGS} ${OBJS} -o ${TARGET}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${TARGET}

re: fclean all