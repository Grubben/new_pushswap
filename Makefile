NAME		= push_swap

## COMPILATION
CC			= gcc
# Compilation Flags
CFLAGS		= -g3 -Wall -Wextra -Werror


# Removal Flags. Not sure if necessary
RM			= rm -rf

SRCS		= $(wildcard src/*.c)

OBJS		= $(SRCS:.c=.o)

LIBFT		= src/libft.a

$(NAME)	: $(LIBFT) $(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o			: %.c
				$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT)	:
				$(MAKE) -C src/libft --silent
				cp src/libft/libft.a $(LIBFT)

all			: $(NAME)

clean		:
				$(RM) $(OBJS)

fclean		: clean
				$(RM) $(NAME)
				$(RM) $(LIBFT)
				$(MAKE) -C src/libft fclean

re			: fclean $(NAME)

.PHONY		: re fclean clean all