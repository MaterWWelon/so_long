/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellini <mbellini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:05:29 by mbellini          #+#    #+#             */
/*   Updated: 2022/12/01 15:24:50 by mbellini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	initialisation(t_vars *vars)
{
	vars->coord->y = 0;
	while (vars->map && vars->map[vars->coord->y])
	{
		vars->coord->x = 0;
		while (vars->map[vars->coord->y][vars->coord->x]
			&& vars->map[vars->coord->y][vars->coord->x] != 'P')
			vars->coord->x++;
		if (vars->map[vars->coord->y][vars->coord->x] == 'P')
			break ;
		vars->coord->y++;
	}
}

int	initialisation_x(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map && vars->map[y])
	{
		x = 0;
		while (vars->map[y][x] && vars->map[y][x] != 'P')
			x++;
		if (vars->map[y][x] == 'P')
			break ;
		y++;
	}
	return (x);
}

int	initialisation_y(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map && vars->map[y])
	{
		x = 0;
		while (vars->map[y][x] && vars->map[y][x] != 'P')
			x++;
		if (vars->map[y][x] == 'P')
			break ;
		y++;
	}
	return (y);
}
