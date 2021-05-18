NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIBFT = libft.a

SRC = char.c conversions.c modifiers.c string.c ft_printf.c int.c aux.c int.c pointer.c udecint.c hex.c

OBJ = $(SRC:.c=.o)

CC = gcc

AR = ar rc

INDEX = ranlib

RM = rm -f

LIBFTOBJS = $(LIBFT:.c=.o)

all: $(NAME)

$(NAME): $(LIBFTOBJS) $(OBJ)
	ar -x $(LIBFT)
	$(AR) $(NAME) *.o
	$(INDEX) $(NAME)
	rm __.SYMDEF\ SORTED

$(LIBFT):
	$(MAKE) libft.a -C ./libft
	cp ./libft/libft.a .

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I.

clean:
	$(RM) *.o $(OBJ)
	@make clean -C ./libft

fclean : clean
	$(RM) $(NAME) 
	@make fclean -C ./libft

re: fclean all

.PHONY: all, clean, fclean, re
