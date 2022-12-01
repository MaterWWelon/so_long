/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellini <mbellini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:05:29 by mbellini          #+#    #+#             */
/*   Updated: 2022/12/01 13:36:08 by mbellini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	check_dim_map(t_vars *vars, t_size *size)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map && vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] && vars->map[i][j] != '\n')
			j++;
		if (j != size->column)
			return (0);
		i++;
	}
	return (1);
}

int	check_murs(t_vars *vars, t_size *size)
{
	int	i;
	int	j;

	j = 0;
	while (vars->map[0][j] == '1' && vars->map[size->line - 1][j] == '1')
		j++;
	if (j != size->column)
		return (0);
	i = 0;
	while (i < size->line && vars->map[i][0] == '1'
	&& vars->map[i][size->column - 1] == '1')
		i++;
	if (i != size->line)
		return (0);
	return (1);
}

int	check_map(t_vars *vars, t_size *size)
{
	if (!vars->map)
	{
		ft_printf("%s\n", "Error\n-->Aucune map presente");
		return (0);
	}	
	if (check_dim_map(vars, size) == 0)
	{
		ft_printf("%s\n", "Error\n-->Mauvaises dimentions de map");
		return (0);
	}
	if (check_murs(vars, size) == 0)
	{
		ft_printf("%s\n", "Error\n-->Murs non conformes");
		return (0);
	}
	if (check_contenu(vars) == 0)
		return (0);
	if (check_pathing(vars, size) == 0)
	{
		ft_printf("%s\n", "Error\n-->Pathing non viable");
		return (0);
	}
	return (1);
}
