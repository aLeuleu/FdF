
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
		fdf.c \
		get_map.c \
		next_tab_element.c \
		iso_projection.c \
		draw_line.c \
		put_pixel.c \
		get_win_center.c \
		get_offset.c \
		add_points.c \
		close_window.c \
		freemap.c \
		get_map_center.c \
		compute_map_x_y_coords.c \
		win_init.c \
		malloc_map.c \
		my_mlx_pixel_put.c \

SRC_BONUS =

FLAGS = -Wall -Wextra -Werror	

OS := $(shell uname)
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

FSAN = #-fsanitize=address

all	: create_obj_folder
	make -C libft
	make -j1 -C $(MLX)
	cp $(MLX)/$(MLX_LIB) ./$(MLX_LIB)
	make $(NAME)
	@make end_message

$(NAME): libft/libft.a $(OBJ)
	cc $(OBJ) $(FSAN) $(MLX_FLAGS) -g3  -L ./libft -lft -lm -o $(NAME)

$(NAME)_bonus: libft/libft.a $(OBJ) $(OBJ_BONUS)
	cc $(OBJ) $(OBJ_BONUS) $(FSAN) $(MLX_FLAGS) -g3  -L ./libft -lft -lm -o $(NAME)_bonus

obj/%.o : src/%.c $(HEADER) Makefile
		cc -c -g3 ${FLAGS} $(FSAN) $< -o $@ -I $(MLX) -I.

create_obj_folder :
	mkdir -p obj

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	make clean -C mlx_macos
	@if [ -d "./obj" ]; then\
		rm -r obj;\
	fi
	make clean -C libft

fclean: clean
	make fclean -C libft
	make clean -C mlx_macos
	rm -f $(NAME)
	rm -f $(NAME)_bonus
	rm -f $(MLX_LIB)

re: 
	make fclean
	make all

end_message:
	@echo "Done !"

bonus:

.PHONY: all clean fclean re create_obj_folder end_message bonus
	