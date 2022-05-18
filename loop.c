#include "minilibx-linux/mlx.h"
#include <math.h>
#include <unistd.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int key_hook(int keycode, t_vars *vars)
{
	int	i;
	void	*img[5];
	int	img_width;
	int	img_height;

	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_loop_end(vars->mlx);
	}
	else if (keycode == 119)
	{
		while(1)
		{
			img[0] = mlx_xpm_file_to_image(vars->mlx, "./sprite/tile000.xpm", &img_width, &img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, img[0], 800, 450);
			sleep(1);
			img[1] = mlx_xpm_file_to_image(vars->mlx, "./sprite/tile001.xpm", &img_width, &img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, img[1], 800, 450);
			sleep(1);
			img[2] = mlx_xpm_file_to_image(vars->mlx, "./sprite/tile002.xpm", &img_width, &img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, img[2], 800, 450);
			sleep(1);
			img[3] = mlx_xpm_file_to_image(vars->mlx, "./sprite/tile003.xpm", &img_width, &img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, img[3], 800, 450);
			sleep(1);
			img[4] = mlx_xpm_file_to_image(vars->mlx, "./sprite/tile004.xpm", &img_width, &img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, img[4], 800, 450);
			sleep(1);
		}
	}

	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1600, 900, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1600, 900);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}
