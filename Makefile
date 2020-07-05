# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/17 12:14:41 by ppepperm          #+#    #+#              #
#    Updated: 2020/05/26 19:42:03 by ppepperm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= RTv1
SRC :=	src/inits.c src/linal.c src/main.c src/trace.c src/input.c src/free.c\
src/qaternion.c src/light.c src/chose.c src/transform.c src/intersections.c src/controls.c
OBJ := $(SRC:%.c=%.o)
CFLAGS := -Wall -Wextra -Werror -I includes
LIB_FLAG :=  -L libft/ -lft `sdl2-config --libs --cflags` -O0
LINUX_FLAG := -L libft/ -lft `sdl2-config --libs --cflags` -O0  -lm
INCLUDES := includes SDL2

all: $(NAME)

%.o : src/%.c $(INCLUDES)
		gcc -c $(CFLAGS) -I $(INCLUDES) $SSRC -o
		@echo $(SSRC:src/%.c = %)

$(NAME): $(OBJ)
		@make -C libft
		@gcc -o $(NAME) $(CFLAGS) $(OBJ) $(LINUX_FLAG)
		@echo "DONE"

MAC : $(OBJ)
		@make -C libft
		@gcc -o $(NAME) $(CFLAGS) $(OBJ) $(LIB_FLAG)
		@echo "DONE"

clean:
		@rm -f $(OBJ)
		@make -C libft clean

fclean: clean
		@rm -f $(NAME)
		@make -C libft fclean

re: fclean $(NAME)

.PHONY: all clean fclean re

