NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -I./includes -g
MFLAGS = -L./libft -lmlx -lX11 -lXext -lm -lft
LIBFT = ./libft 

SRCS = srcs/check.c srcs/map.c srcs/cleanup.c srcs/move.c srcs/so_long.c srcs/upload.c srcs/utils.c srcs/path.c srcs/flood_fill.c srcs/upload2.c

OBJS = $(SRCS:.c=.o)

all: libft $(NAME)

libft:
	$(MAKE) -C $(LIBFT)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
