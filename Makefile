NAME = fdf

SRCS = main.c

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Wextra -Werror -g

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
	@cc $(FLAGS) ${OBJS} -Llibft -lft -o ${NAME}
	@echo "\033[32mPipex Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n\e[0m"

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