NAME = so_long

SRCS =	read_map.c check_map.c $(GNL)

GNL = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):$(OBJS)
	gcc -o $(NAME) $(OBJS) ft_printf/libftprintf.a -Lft_printf/ -lftprintf

%.o:%.c map.h
	make -C ft_printf/
	gcc $(CFLAGS) -o $@ -c $< -Ift_printf/

clean:
	rm -rf $(OBJS)

fclean:clean
	rm -rf $(NAME)

re: fclean all
