#ifndef MAP_H
# define MAP_H
# include "minilibx-linux/mlx.h"
# include "get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_coord {
	int 	x;
	int 	y;
	int		collectible;
}				t_coord;

typedef struct s_list {
	int 	x;
	int 	y;
	struct s_list	*next;
}				t_list;

typedef struct s_size {
	int		line;
	int		column;
}				t_size;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char 	**map;
	t_coord	*coord;
	t_list	*list;
}				t_vars;

char	**read_map(char *file);
void	line_count(t_vars *vars, t_size *size);
void	column_count(t_vars *vars, t_size *size);
int		window_height(t_size *size);
int		window_length(t_size *size);
void	initialisation(t_vars *vars);
int		count_collectible(t_vars *vars);
int		collectible_in_range(t_vars *vars);
void	include_list(t_vars *vars);
void	pathing(t_vars *vars, t_size *size);
int		check_pathing(t_vars *vars, t_size *size);
void	free_list(t_vars *vars);
int		check_map(t_vars *vars, t_size *size);
void	create_map(t_vars *vars);

void	move_up(t_vars *vars);
#endif