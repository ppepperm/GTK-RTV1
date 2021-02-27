# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/17 12:14:41 by ppepperm          #+#    #+#              #
#    Updated: 2021/02/28 00:31:11 by gjigglyp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S := $(shell uname -s)
NAME = RT
SRC_DIR = ./src/
SRCF =	inits.c linal.c main.c trace.c input.c free.c\
qaternion.c light.c chose.c transform.c intersections.c controls.c pthread.c\
returns.c objects.c lights.c validation.c shadows.c events.c low_panel.c

OBJ_DIR = ./obj/
SRC = $(addprefix $(SRC_DIR), $(SRCF))
OBJ = $(addprefix $(OBJ_DIR), $(OBJF))
OBJF = $(SRCF:.c=.o)
LIBS = libft/libft.a
HEADERS = -I ./includes -I ./libft/includes
HDR = includes/rt.h

ifeq ($(UNAME_S), Linux)
	FLAGS = -Wall -Wextra -Werror -lm -g 
	CGFLAGS = `sdl2-config --cflags --libs` -lm -pthread
else ifeq ($(UNAME_S), Darwin)
	FLAGS = -Wall -Wextra -Werror -g
	CGFLAGS =  -framework OpenGL -framework AppKit
	INCLUDES	=	-I./frameworks/SDL2.framework/Versions/A/Headers \
					-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
					-I./frameworks/SDL2_image.framework/Versions/A/Headers \
					-I./frameworks/SDL2_mixer.framework/Headers \
					-F./frameworks/
	FRAMEWORKS	=	-F./frameworks \
					-rpath ./frameworks \
					-framework OpenGL -framework AppKit -framework OpenCl \
					-framework SDL2 -framework SDL2_ttf -framework SDL2_image \
					-framework SDL2_mixer
endif

ifeq ($(UNAME_S), Linux)
	CC = clang
	COMP = $(CC) -g $(CGFLAGS) $(OBJ) $(LIBS) -o $(NAME) -lSDL -lSDL2_ttf -lfreetype
	RECOMP = $(CC) -g $(INCLUDES) -c $< -o $@ $(HEADERS)
else ifeq ($(UNAME_S), Darwin)
	CC = gcc
	COMP = $(CC) $(FLAGS) $(CGFLAGS) $(FRAMEWORKS) $(OBJ) $(LIBS) -o $(NAME) -lSDL -lSDL2_ttf -lfreetype
	RECOMP = $(CC) $(FLAGS) $(INCLUDES) $(HEADERS) -c $< -o $@
endif

all: obj $(NAME)

obj:
	mkdir -p $(OBJ_DIR)
	
$(NAME): libft/libft.a $(OBJ) $(HDR)
	$(COMP)
	@printf "Compailing of RT has done\n"

$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(HDR)
	$(RECOMP)
	
clean:
	@make clean -C libft
	@rm -Rf $(OBJ)
	@rm -Rf obj

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft
	@printf "Binary and object files of RT were deleted\n"

libft/libft.a:
	@make -C libft
	
re: fclean all


