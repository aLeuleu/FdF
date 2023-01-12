
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

SRC =	fdf.c \
		get_map.c \
		print_map.c \
		draw_center.c

FLAGS = # -Wall -Wextra -Werror	
	
OBJ = $(addprefix obj/,$(SRC:.c=.o))

FSAN = -fsanitize=address

all	: create_obj_folder
	make -C libft
	make -C mlx
	cp mlx/libmlx.dylib ./libmlx.dylib
	make $(NAME)
	@make end_message

$(NAME): libft/libft.a $(OBJ)
	cc $(OBJ) $(FSAN) -g3 -Lmlx -lmlx -framework OpenGL -framework AppKit -L ./libft -lft -lm -o $(NAME)

obj/%.o : src/%.c $(HEADER) Makefile
		cc -c -g3 ${FLAGS} $< -o $@ -I mlx -I.

create_obj_folder :
	mkdir -p obj

clean:
	rm -f $(OBJ)
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
	@echo "Done !"

.PHONY: all clean fclean re create_obj_folder end_message
	