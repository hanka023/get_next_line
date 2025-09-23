
# Kompilátor
CC = cc

# Kompilační příznaky
CFLAGS = -Wall -Wextra -Werror

# Zdrojové soubory
SRCS = \
	get_next_line.c \
	get_next_line_utils.c \


# Objektové soubory
OBJS = $(SRCS:%.c=%.o)

# Název knihovny
NAME = get_next_line.a

# Výchozí cíl
all: $(NAME)

# Vytvoření statické knihovny
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Překlad .c → .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Vyčištění objektových souborů
clean:
	rm -f $(OBJS)

# Vyčištění všeho (objekty + knihovna)
fclean: clean
	rm -f $(NAME)


# Překompilovat celé
re: fclean all

# Phony cíle
.PHONY: all clean fclean re
