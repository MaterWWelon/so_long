#include "map.h"

void	create_map(t_vars *vars)
{
	void	*img;
	int		i;
	int		j;
	int		img_width;
	int		img_height;

	i = 0;
	while (vars->map && vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == '1')
				img = mlx_xpm_file_to_image(vars->mlx, "./img/tree.xpm", &img_width, &img_height);
			else if (vars->map[i][j] == '0')
				img = mlx_xpm_file_to_image(vars->mlx, "./img/ground.xpm", &img_width, &img_height);
			else if (vars->map[i][j] == 'C')
			{
				img = mlx_xpm_file_to_image(vars->mlx, "./img/ground.xpm", &img_width, &img_height);
				img = mlx_xpm_file_to_image(vars->mlx, "./img/key.xpm", &img_width, &img_height);
			}
			else if (vars->map[i][j] == 'P')
			{
				img = mlx_xpm_file_to_image(vars->mlx, "./img/ground.xpm", &img_width, &img_height);
				img = mlx_xpm_file_to_image(vars->mlx, "./img/link1.xpm", &img_width, &img_height);
			}
			else if (vars->map[i][j] == 'E')
				img = mlx_xpm_file_to_image(vars->mlx, "./img/tent.xpm", &img_width, &img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, img, j * 40, i * 40);
			j++;
		}
		i++;
	}
}
