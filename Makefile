
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 15:01:30 by alevra            #+#    #+#              #
#    Updated: 2023/01/09 11:45:21 by alevra           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = fdf

HEADER = $(NAME).h

SRC =	display_map.c \
		draw_center.c \
		fdf.c \
		get_map.c \
		next_tab_element.c \
		print_map.c \
		iso_projection.c \
		draw_line.c \
		put_pixel.c \
		draw_cross.c \
		get_win_center.c \
		get_offset.c \
		add_points.c \

SRC_BONUS = draw_tile.c	\
		are_equals_points.c \

FLAGS = # -Wall -Wextra -Werror	

ifeq ($(OS),Darwin)
  MLX = mlx_macos
  MLX_LIB = libmlx.dylib
  MLX_FLAGS = -L$(MLX) -lmlx -framework OpenGL -framework AppKit
else
  MLX = mlx_linux
  MLX_LIB = libmlx.a
  MLX_FLAGS = -L$(MLX) -lmlx -lXext -lX11
endif
	
OBJ = $(addprefix obj/,$(SRC:.c=.o))
OBJ_BONUS = $(addprefix obj/,$(SRC_BONUS:.c=.o))

FSAN = -fsanitize=address

OS := $(shell uname)


all	: create_obj_folder
	@make -C libft
	@make -C $(MLX)
	@cp $(MLX)/$(MLX_LIB) ./$(MLX_LIB)
	# @clear
	make $(NAME)
	@make end_message

$(NAME): libft/libft.a $(OBJ)
	cc $(OBJ) $(FSAN) $(MLX_FLAGS) -g3  -L ./libft -lft -lm -o $(NAME)

$(NAME)_bonus: libft/libft.a $(OBJ) $(OBJ_BONUS)
	cc $(OBJ) $(OBJ_BONUS) $(FSAN) $(MLX_FLAGS) -g3  -L ./libft -lft -lm -o $(NAME)_bonus

obj/%.o : src/%.c $(HEADER) Makefile
		cc -c -g3 ${FLAGS} $< -o $@ -I $(MLX) -I.

create_obj_folder :
	mkdir -p obj

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	@if [ -d "./obj" ]; then\
		rm -r obj;\
	fi
	make clean -C libft

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: 
	make fclean
	make all

debug : libft/libft.a
	cc $(FSANITIZE) -Wall -Wextra -Werror $(SRC) -L ./libft -lft -o $(NAME)_debug  && ./$(NAME)_debug $(ARG) && echo "" && ./$(NAME)_debug $(ARG) | ./checker $(ARG) 

run:
	./$(NAME) $(ARG)

end_message:
	@clear
	@echo "Done !"

bonus : create_obj_folder
	@make -C libft
	@make -C $(MLX)
	@cp $(MLX)/$(MLX_LIB) ./$(MLX_LIB)
	# @clear
	make $(NAME)_bonus
	@make end_message


.PHONY: all clean fclean re create_obj_folder end_message
	