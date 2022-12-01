/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_contenu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellini <mbellini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:36:13 by mbellini          #+#    #+#             */
/*   Updated: 2022/12/01 17:04:55 by mbellini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	check_personnage(t_vars *vars)
{
	int	personnage;
	int	i;
	int	j;

	personnage = 0;
	i = 0;
	while (vars->map && vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'P')
				personnage++;
			j++;
		}
		i++;
	}
	if (personnage != 1)
	{
		ft_printf("%s\n", "Error\n-->Il doit y avoir 1 personnage");
		return (0);
	}
	return (1);
}

int	check_exit(t_vars *vars)
{
	int	exit;
	int	i;
	int	j;

	exit = 0;
	i = 0;
	while (vars->map && vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (exit != 1)
	{
		ft_printf("%s\n", "Error\n-->Il doit y avoir 1 exit");
		return (0);
	}
	return (1);
}

int	check_collectible(t_vars *vars)
{
	int	collectible;
	int	i;
	int	j;

	collectible = 0;
	i = 0;
	while (vars->map && vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
	if (collectible == 0)
	{
		ft_printf("%s\n", "Error\n-->Il doit y avoir au moins 1 collectible");
		return (0);
	}
	return (1);
}

int	check_contenu(t_vars *vars)
{
	if (check_personnage(vars) == 0 || check_exit(vars) == 0
		|| check_collectible(vars) == 0)
	{
		return (0);
	}
	return (1);
}
