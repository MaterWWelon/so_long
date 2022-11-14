#ifndef MAP_H
# define MAP_H
# include "minilibx-linux/mlx.h"
# include "get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_coord {
	int 	x;
	int 	y;
	struct s_coord	*next;
}				t_coord;

typedef struct s_size {
	int		line;
	int		column;
}				t_size;


char	**read_map(char *file);
void	line_count(char **map, t_size *size);
void	column_count(char **map, t_size *size);
int		window_height(t_size *size);
int		window_length(t_size *size);
void	pathing(char **map, t_coord *coord, t_size *size);
int		check_pathing(char **map, t_coord *coord, t_size *size);
int		check_map(char **map, t_coord *coord, t_size *size);
void	create_map(char **map, t_vars vars);

void	move_up(char **map);
#endif