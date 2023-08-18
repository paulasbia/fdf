NAME = fdf

SRCS = teste.c

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Wextra -Werror -g

COLOUR_GREEN=\033[32m
COLOUR_RED=\033[31m
COLOUR_END=\033[0m


ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx_linux
else
	INCLUDES = -I/opt/X11/include -Imlx
endif

MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
ifeq ($(shell uname), Linux)
	MLX_DIR = ./mlx_linux
	MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
else
	MLX_DIR = ./mlx
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

#INCLUDES = -I/opt/X11/include -Imlx

#MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit

.c.o: %.o : %.c
	@cc ${FLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: ${NAME}

install:
	python3 -m pip install --upgrade pip setuptools
	python3 -m pip install norminette
	sudo apt install valgrind -y

check:
	norminette $(SRCS)

test: all
	gcc -ggdb $(FLAGS) pipex.c utils.c error.c $(NAME) -o pipex.o

run: all
	./pipex

${NAME}: ${OBJS}
	@echo "\033[33m----Compiling lib----"
	@make re -C ./libft
	@cc $(FLAGS) $(OBJS) -Llibft -lft -o $(NAME) $(MLX_FLAGS)
	@echo "$(COLOUR_GREEN)fdf Compiled! ᕦ$(COLOUR_RED)♥$(COLOUR_GREEN)_$(COLOUR_RED)♥$(COLOUR_GREEN)ᕤ\n$(COLOUR_END)"

clean:
	@make clean -C ./libft
	@rm -f ${OBJS}

fclean: clean
	@make fclean -C ./libft
	@rm -f ${NAME}
	@echo "$(COLOUR_RED)Deleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n$(COLOUR_END)"

re:			fclean all

valgrind: clean fclean all
	rm -f $(OBJS) $(NAME)
	valgrind --leak-check=full ./result.out

.PHONY: all clean fclean re 