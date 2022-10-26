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
}				t_coord;


char	**read_map(char *file);
int		line_count(char **map);
int		column_count(char **map);
int		window_height(char **map);
int		window_length(char **map);
void	pathing(char **map, t_coord *coord);
int		check_pathing(char **map, t_coord *coord);
int		check_map(char **map, t_coord *coord);
void	create_map(char **map, t_vars vars);

void	move_up(char **map);
#endif