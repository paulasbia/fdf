NAME = fdf

SRCS = main.c

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Wextra -Werror -g

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
	@cc ${FLAGS} -c $< -o $@ $(INCLUDES)

all: $(MLX_LIB) ${NAME}

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
	@echo "\033[32mPipex Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n\e[0m"

$(MLX_LIB):
	@make -C $(MLX_DIR)

clean:
	@make clean -C ./libft
	@rm -f ${OBJS}

fclean: clean
	@make fclean -C ./libft
	@rm -f ${NAME}
	@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n\e[0m"

re:			fclean all

valgrind: clean fclean all
	rm -f $(OBJS) $(NAME)
	valgrind --leak-check=full ./result.out

.PHONY: all clean fclean re 