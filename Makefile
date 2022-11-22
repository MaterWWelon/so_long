NAME = so_long

SRCS =	read_map.c check_map.c so_long.c window_size.c create_map.c moves.c check_pathing.c linked_list.c $(GNL)

GNL = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJS) ft_printf/libftprintf.a
	gcc -o $(NAME) $(OBJS) ft_printf/libftprintf.a -Lft_printf/ -lftprintf -Lminilibx-linux -lmlx -lXext -lX11

%.o:%.c map.h
	gcc $(CFLAGS) -o $@ -c $< -Ift_printf/

ft_printf/libftprintf.a:
	make -C ft_printf/

clean:
	rm -rf $(OBJS)

fclean:clean
	rm -rf $(NAME)

re: fclean all
