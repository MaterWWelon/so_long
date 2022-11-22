#include "map.h"
#include <stdio.h>

void	move_up(t_vars *vars)
{
	void	*img;
	int		img_width;
	int		img_height;
	printf("coord-> x: %d\n", vars->coord->x);
	printf("coord-> y - 1: %d\n", vars->coord->y - 1);
	if (!vars->map || !(vars->coord->y - 1) || vars->map[vars->coord->x][vars->coord->y - 1] == '1')
	{
		printf("ouch");
		return;
	}
	if (vars->map[vars->coord->x][vars->coord->y - 1] == 'C')
	{
		++vars->coord->collectible;
		img = mlx_xpm_file_to_image(vars->mlx, "./img/link_up.xpm", &img_width, &img_height);

	}
	if (vars->map[vars->coord->x][vars->coord->y - 1] == '0')
		img = mlx_xpm_file_to_image(vars->mlx, "./img/link_up.xpm", &img_width, &img_height);
	if (vars->map[vars->coord->x][vars->coord->y - 1] == 'E')
	{
		// if (vars->coord->collectible == count_collectible(vars->map))
		// 	game_end();
		if (vars->coord->collectible != count_collectible(vars))
		{
			img = mlx_xpm_file_to_image(vars->mlx, "./img/tent_up.xpm", &img_width, &img_height);
		}
	}

	mlx_put_image_to_window(vars->mlx, vars->win, img, vars->coord->x * 40, (vars->coord->y - 1) * 40);

	if (vars->map[vars->coord->x][vars->coord->y] == 'E')
		img = mlx_xpm_file_to_image(vars->mlx, "./img/tent.xpm", &img_width, &img_height);
	else
		img = mlx_xpm_file_to_image(vars->mlx, "./img/ground.xpm", &img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, img, vars->coord->x * 40, vars->coord->y * 40);
	vars->coord->y--;
}

