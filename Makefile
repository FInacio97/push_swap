NAME = push_swap

LIBFT_PATH = ./libft/
LIBFT = $(LIBFT_PATH)libft.a

SRC = ./sources/push_swap.c	./sources/parsing.c	./sources/utils.c\
			./sources/moves_a.c	./sources/moves_b.c	./sources/utils_2.c\
			./sources/sort_2.c

OBJS = $(SRC:.c=.o)


CFLAGS = -Wall -Werror -Wextra
OTHERFLAGS = -L$(LIBFT_PATH) -lft -o $(NAME)
CC = cc

#=====||COLOURS||======


#======||RULES||=======
all:$(NAME)

$(NAME): $(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(OTHERFLAGS)
$(LIBFT):
		@make -sC $(LIBFT_PATH)

clean:
		@make -sC $(LIBFT_PATH) clean
		rm -f $(OBJS)
fclean:
		@make -sC $(LIBFT_PATH) fclean
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re