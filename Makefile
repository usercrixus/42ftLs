MAKEFLAGS += --no-print-directory

OBJ = \
	src/main.o \
	src/printer.o \
	src/parser.o \
	src/sorter.o \
	
FLAG = -Werror -Wextra -Wall

all: submodule libft.a ft_ls

libft.a:
	make -C ./src/42libft

ft_ls: $(OBJ)
	gcc $(OBJ) -L./src/42libft/ft_printf -lftprintf -L./src/42libft/ft_base -lft $(FLAG) -o $@

%.o: %.c
	gcc -c $< -o $@

submodule:
	git submodule update --init --recursive

clean:
	rm -f $(OBJ)
	make -C ./src/42libft fclean

.PHONY: clean submodule libft.a