NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIBFT = libft.a

SRC = char.c conversions.c modifiers.c string.c ft_printf.c int.c aux.c int.c pointer.c udecint.c hex.c

OBJ = $(SRC:.c=.o)

CC = gcc

AR = ar rc

INDEX = ranlib

RM = rm -f

LIBFTOBJS = ./libft/*.o

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(AR) $(NAME) $(LIBFTOBJS) $(OBJ)
	$(INDEX) $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

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
