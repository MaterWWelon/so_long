/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellini <mbellini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:17:50 by mbellini          #+#    #+#             */
/*   Updated: 2022/12/01 13:13:40 by mbellini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_loop_end(vars->mlx);
	}
	else if (keycode == 119 || keycode == 65362)
		move_up(vars);
	else if (keycode == 115 || keycode == 65364)
		move_down(vars);
	else if (keycode == 97 || keycode == 65361)
		move_left(vars);
	else if (keycode == 100 || keycode == 65363)
		move_right(vars);
	return (0);
}

void game_end(t_vars *vars)
{
	ft_printf("you win!\n");
	mlx_destroy_window(vars->mlx, vars->win);
	free_list(vars);
	mlx_loop_end(vars->mlx);
}

int	main(void)
{
	t_vars	vars;
	t_size	size;

	vars.coord = malloc(sizeof(vars.coord));
	vars.coord->x = 0;
	vars.coord->y = 0;
	vars.map = read_map("map2.ber");
	line_count(&vars, &size);
	column_count(&vars, &size);
	if (check_map(&vars, &size) == 1)
	{
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, window_length(&size), window_height(&size), "so_long");
		create_map(&vars);
		initialisation(&vars);
		mlx_hook(vars.win, 2, 1L<<0, &key_hook, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
