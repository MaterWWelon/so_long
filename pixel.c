#include "minilibx-linux/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	red_square(t_data img, int length, int color)
{
	int i = -1;

	while (++i <= length)
	{
		my_mlx_pixel_put(&img, 5 + i, 5, color);
		my_mlx_pixel_put(&img, 5 + i, 5 + length, color);
		my_mlx_pixel_put(&img, 5, 5 + i, color);
		my_mlx_pixel_put(&img, 5 + length, 5 + i, color);
	}
}


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	red_square(img, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
