NAME = push_swap
BONUS_NAME = checker

LIBFT_PATH = ./libft/
LIBFT = $(LIBFT_PATH)libft.a

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address
OTHERFLAGS = -L$(LIBFT_PATH) -lft -o $(NAME)
OTHERFLAGS_BONUS = -L$(LIBFT_PATH) -lft -o $(BONUS_NAME)
CC = cc

SRC = ./sources/push_swap.c	./sources/parsing.c	./sources/utils.c\
			./sources/moves_a.c	./sources/moves_b.c	./sources/utils_2.c\
			./sources/sort_2.c	./sources/utils_3.c	./sources/sort_6.c\
			./sources/lists.c	./sources/lists_2.c	./sources/sort_10_up.c\
			./sources/lists_3.c	./sources/utils_4.c ./sources/test.c

OBJS = $(SRC:.c=.o)

#=====||BONUS||========

BONUS_SRC = ./bonus/checker.c	./bonus/lists.c	./bonus/utils_c.c\
				./bonus/parsing.c	./bonus/moves_checker.c	./bonus/moves_a.c\
				./bonus/moves_b.c	./bonus/moves_double.c

BONUS_OBJS = $(BONUS_SRC:.c=.o)

#=====||COLOURS||======


#======||RULES||=======
all:$(NAME)

$(NAME): $(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(OTHERFLAGS)
$(LIBFT):
		@make -sC $(LIBFT_PATH)

bonus:$(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
				$(CC) $(CFLAGS) $(BONUS_OBJS) $(OTHERFLAGS_BONUS)

clean:
		@make -sC $(LIBFT_PATH) clean
		rm -f $(OBJS) $(BONUS_OBJS)
fclean:
		@make -sC $(LIBFT_PATH) fclean
		rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
