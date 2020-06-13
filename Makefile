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

NAME= Rtv1
SRC := rt.c draw.c
OBJ := $(SRC:%.c=%.o)
CFLAGS := `pkg-config --cflags --libs gtk+-3.0`
LIB_FLAG :=  -L libft/ -lft -O0 `pkg-config --cflags --libs gtk+-3.0`
LINUX_FLAG := -L libft/ -lft -O0 `pkg-config --cflags --libs gtk+-3.0` -lm
INCLUDES := `pkg-config --cflags --libs gtk+-3.0` .

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

