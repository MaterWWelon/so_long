#include "map.h"
#include <stdio.h>

/*
int	close(int keycode, t_vars *vars)
{
typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}
*/

int key_hook(int keycode, t_vars *vars, char **map)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_loop_end(vars->mlx);
	}
	else if (keycode == 119)
	{
		move_up(map);
		printf("Hello\n");
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_coord	coord;
//	void	*img;
//	int		img_width;
//	int		img_height;
	char	**map;

	map = read_map("map1.ber");
	if (check_map(map, &coord) == 1)
	{
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, window_length(map), window_height(map), "so_long");
		create_map(map, vars);
//		img = mlx_xpm_file_to_image(vars.mlx, "./img/tree.xpm", &img_width, &img_height);
//		mlx_put_image_to_window(vars.mlx, vars.win, img, 0, 0);
		mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
