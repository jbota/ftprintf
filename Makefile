C = gcc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIBFT = .libft/libft.a

S = srcs

O = obj

HEADER = includes

SOURCES = char.c conversions.c modifiers.c string.c ft_printf.c int.c aux.c int.c pointer.c udecint.c hex.c

SRCS = $(addprefix $(S)/,$(SOURCES))

OBJS = $(addprefix $(O)/,$(SOURCES:.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(O)/%.o: $(S)/%.c $(HEADER)/ft_printf.h
	@mkdir -p obj
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(O)
	@make clean -C $(LIBFT)

fclean : clean
	@rm -f $(NAME)
	@make clean -C $(LIBFT)

re: fclean all

.PHONY: fclean re all clean
