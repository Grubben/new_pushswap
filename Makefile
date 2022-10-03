NAME	= push_swap

## COMPILATION
CC		= gcc
# Compilation Flags
CFLAGS		= -g3 -Wall -Wextra -Werror


# Removal Flags. Not sure if necessary
RM			= rm -rf

SRCS	= $(wildcard src/*.c)
OBJS	= $(SRCS:.c=.o)


$(NAME).out		: src/libft.a $(OBJS)
			$(CC) $(CFLAGS) -o $(NAME).out src/libft.a $(OBJS)

src/libft.a	:
			$(MAKE) -C src/libft --silent
			cp src/libft/libft.a src/libft.a

all			: $(NAME)

clean		:
			$(RM) $(OBJS)

fclean		: clean
			$(RM) $(NAME)
			$(RM) src/libft.a
			$(MAKE) -C src/libft fclean

re			: fclean $(NAME)

.PHONY		: re fclean clean all