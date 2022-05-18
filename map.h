#ifndef MAP_H
# define MAP_H
# include "get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


char	**read_map(char *file);

#endif