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

int key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_loop_end(vars->mlx);
	}
	else if (keycode == 119)
	{
		printf("vars.map[0]: %s\n", vars->map[0]);
		move_up(vars);
		printf("Hello\n");
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_size	size;

	vars.coord = malloc(sizeof(vars.coord));
	vars.coord->x = 0;
	vars.coord->y = 0;
	vars.map = read_map("map1.ber");
	line_count(&vars, &size);
	column_count(&vars, &size);
	if (check_map(&vars, &size) == 1)
	{
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, window_length(&size), window_height(&size), "so_long");
		create_map(&vars);
		initialisation(&vars);
		printf("map[0]: %s\n", vars.map[0]);
//		img = mlx_xpm_file_to_image(vars.mlx, "./img/tree.xpm", &img_width, &img_height);
//		mlx_put_image_to_window(vars.mlx, vars.win, img, 0, 0);
		mlx_hook(vars.win, 2, 1L<<0, &key_hook, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
