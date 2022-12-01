/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellini <mbellini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:31:37 by mbellini          #+#    #+#             */
/*   Updated: 2022/12/01 17:09:57 by mbellini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	create_map_2(t_vars *vars)
{
	void	*img;
	int		img_width;
	int		img_height;

	if (vars->map[vars->iter->i][vars->iter->j] == '1')
		img = mlx_xpm_file_to_image(vars->mlx,
				"./img/tree.xpm", &img_width, &img_height);
	else if (vars->map[vars->iter->i][vars->iter->j] == '0')
		img = mlx_xpm_file_to_image(vars->mlx,
				"./img/ground.xpm", &img_width, &img_height);
	else if (vars->map[vars->iter->i][vars->iter->j] == 'C')
		img = mlx_xpm_file_to_image(vars->mlx,
				"./img/key.xpm", &img_width, &img_height);
	else if (vars->map[vars->iter->i][vars->iter->j] == 'P')
		img = mlx_xpm_file_to_image(vars->mlx,
				"./img/link1.xpm", &img_width, &img_height);
	else if (vars->map[vars->iter->i][vars->iter->j] == 'E')
		img = mlx_xpm_file_to_image(vars->mlx,
				"./img/tent.xpm", &img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, img, vars->iter->j * 40, vars->iter->i * 40);
}

void	create_map(t_vars *vars)
{
	vars->iter = malloc(sizeof(vars->iter));
	vars->iter->i = 0;
	while (vars->map && vars->map[vars->iter->i])
	{
		vars->iter->j = 0;
		while (vars->map[vars->iter->i][vars->iter->j])
		{
			create_map_2(vars);
			vars->iter->j++;
		}
		vars->iter->i++;
	}
}
