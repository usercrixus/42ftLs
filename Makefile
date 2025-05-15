MAKEFLAGS += --no-print-directory

OBJ = \
	src/main.o \
	src/printer.o \
	src/parser.o \
	src/sorter.o \
	src/list.o \
	src/printManager.o \
	
FLAG = -Werror -Wextra -Wall

all: submodule libft.a ft_ls

libft.a:
	make -C ./src/42libft

ft_ls: $(OBJ)
	gcc $(FLAG) $(OBJ) -L./src/42libft/ft_printf -lftprintf -L./src/42libft/ft_base -lft -L./src/42libft/ft_str -lftstr -o $@

%.o: %.c
	gcc $(FLAG) -c $< -o $@

submodule:
	git submodule update --init --recursive

clean:
	rm -f $(OBJ)
	make -C ./src/42libft clean

fclean: clean
	rm -f ft_ls
	make -C ./src/42libft fclean

re: fclean all

.PHONY: fclean clean submodule libft.a