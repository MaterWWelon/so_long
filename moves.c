/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellini <mbellini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:05:29 by mbellini          #+#    #+#             */
/*   Updated: 2022/12/01 13:12:48 by mbellini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	move_up(t_vars *vars)
{
	void	*img;
	int		img_width;
	int		img_height;

	if (!vars->map || vars->map[vars->coord->y - 1][vars->coord->x] == '1')
		return;
	else if (vars->map[vars->coord->y - 1][vars->coord->x] == 'C')
	{
		vars->coord->collectible++;
		img = mlx_xpm_file_to_image(vars->mlx, "./img/link_up.xpm", &img_width, &img_height);
		vars->map[vars->coord->y - 1][vars->coord->x] = '0';
	}
	else if (vars->map[vars->coord->y - 1][vars->coord->x] == '0' || vars->map[vars->coord->y - 1][vars->coord->x] == 'P')
		img = mlx_xpm_file_to_image(vars->mlx, "./img/link_up.xpm", &img_width, &img_height);
	else if (vars->map[vars->coord->y - 1][vars->coord->x] == 'E')
	{
		if (vars->coord->collectible == vars->coord->total_collectible)
			game_end(vars);
		else
			img = mlx_xpm_file_to_image(vars->mlx, "./img/tent_up.xpm", &img_width, &img_height);
	}

	mlx_put_image_to_window(vars->mlx, vars->win, img, vars->coord->x * 40, (vars->coord->y - 1) * 40);

	if (vars->map[vars->coord->y][vars->coord->x] == 'E')
		img = mlx_xpm_file_to_image(vars->mlx, "./img/tent.xpm", &img_width, &img_height);
	else
		img = mlx_xpm_file_to_image(vars->mlx, "./img/ground.xpm", &img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, img, vars->coord->x * 40, vars->coord->y * 40);
	vars->coord->y--;
}

void	move_down(t_vars *vars)
{
	void	*img;
	int		img_width;
	int		img_height;

	if (!vars->map || vars->map[vars->coord->y + 1][vars->coord->x] == '1')
		return;
	else if (vars->map[vars->coord->y + 1][vars->coord->x] == 'C')
	{
		vars->coord->collectible++;
		img = mlx_xpm_file_to_image(vars->mlx, "./img/link1.xpm", &img_width, &img_height);
		vars->map[vars->coord->y + 1][vars->coord->x] = '0';
	}
	else if (vars->map[vars->coord->y + 1][vars->coord->x] == '0' || vars->map[vars->coord->y + 1][vars->coord->x] == 'P')
		img = mlx_xpm_file_to_image(vars->mlx, "./img/link1.xpm", &img_width, &img_height);
	else if (vars->map[vars->coord->y + 1][vars->coord->x] == 'E')
	{
		if (vars->coord->collectible == vars->coord->total_collectible)
			game_end(vars);
		else
			img = mlx_xpm_file_to_image(vars->mlx, "./img/tent_down.xpm", &img_width, &img_height);
	}

	mlx_put_image_to_window(vars->mlx, vars->win, img, vars->coord->x * 40, (vars->coord->y + 1) * 40);

	if (vars->map[vars->coord->y][vars->coord->x] == 'E')
		img = mlx_xpm_file_to_image(vars->mlx, "./img/tent.xpm", &img_width, &img_height);
	else
		img = mlx_xpm_file_to_image(vars->mlx, "./img/ground.xpm", &img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, img, vars->coord->x * 40, vars->coord->y * 40);
	vars->coord->y++;
}

void	move_left(t_vars *vars)
{
	void	*img;
	int		img_width;
	int		img_height;

	if (!vars->map || vars->map[vars->coord->y][vars->coord->x - 1] == '1')
		return;
	else if (vars->map[vars->coord->y][vars->coord->x - 1] == 'C')
	{
		vars->coord->collectible++;
		img = mlx_xpm_file_to_image(vars->mlx, "./img/link_left.xpm", &img_width, &img_height);
		vars->map[vars->coord->y][vars->coord->x - 1] = '0';
	}
	else if (vars->map[vars->coord->y][vars->coord->x - 1] == '0' || vars->map[vars->coord->y][vars->coord->x - 1] == 'P')
		img = mlx_xpm_file_to_image(vars->mlx, "./img/link_left.xpm", &img_width, &img_height);
	else if (vars->map[vars->coord->y][vars->coord->x - 1] == 'E')
	{
		if (vars->coord->collectible == vars->coord->total_collectible)
			game_end(vars);
		else
			img = mlx_xpm_file_to_image(vars->mlx, "./img/tent_left.xpm", &img_width, &img_height);
	}

	mlx_put_image_to_window(vars->mlx, vars->win, img, (vars->coord->x - 1) * 40, vars->coord->y * 40);

	if (vars->map[vars->coord->y][vars->coord->x] == 'E')
		img = mlx_xpm_file_to_image(vars->mlx, "./img/tent.xpm", &img_width, &img_height);
	else
		img = mlx_xpm_file_to_image(vars->mlx, "./img/ground.xpm", &img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, img, vars->coord->x * 40, vars->coord->y * 40);
	vars->coord->x--;
}

void	move_right(t_vars *vars)
{
	void	*img;
	int		img_width;
	int		img_height;

	if (!vars->map || vars->map[vars->coord->y][vars->coord->x + 1] == '1')
		return;
	else if (vars->map[vars->coord->y][vars->coord->x + 1] == 'C')
	{
		vars->coord->collectible++;
		img = mlx_xpm_file_to_image(vars->mlx, "./img/link_right.xpm", &img_width, &img_height);
		vars->map[vars->coord->y][vars->coord->x + 1] = '0';
	}
	else if (vars->map[vars->coord->y][vars->coord->x + 1] == '0' || vars->map[vars->coord->y][vars->coord->x + 1] == 'P')
		img = mlx_xpm_file_to_image(vars->mlx, "./img/link_right.xpm", &img_width, &img_height);
	else if (vars->map[vars->coord->y][vars->coord->x + 1] == 'E')
	{
		if (vars->coord->collectible == vars->coord->total_collectible)
			game_end(vars);
		else
			img = mlx_xpm_file_to_image(vars->mlx, "./img/tent_right.xpm", &img_width, &img_height);
	}

	mlx_put_image_to_window(vars->mlx, vars->win, img, (vars->coord->x + 1) * 40, vars->coord->y * 40);

	if (vars->map[vars->coord->y][vars->coord->x] == 'E')
		img = mlx_xpm_file_to_image(vars->mlx, "./img/tent.xpm", &img_width, &img_height);
	else
		img = mlx_xpm_file_to_image(vars->mlx, "./img/ground.xpm", &img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, img, vars->coord->x * 40, vars->coord->y * 40);
	vars->coord->x++;
}