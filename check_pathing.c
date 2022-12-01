/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pathing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellini <mbellini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:05:29 by mbellini          #+#    #+#             */
/*   Updated: 2022/12/01 15:23:14 by mbellini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	collectible_in_range(t_vars *vars)
{
	t_list	*curr;
	int		c;

	curr = vars->list;
	c = 0;
	while (curr != NULL)
	{
		if (vars->map[curr->y][curr->x] == 'C')
			++c;
		curr = curr->next;
	}
	if (c != count_collectible(vars))
		return (0);
	return (1);
}

int	exit_in_range(t_vars *vars)
{
	t_list	*curr;

	curr = vars->list;
	while (curr != NULL)
	{
		if (vars->map[curr->y][curr->x] == 'E')
			return (1);
		curr = curr->next;
	}
	return (0);
}

int	check_list(int x, int y, t_vars *vars)
{
	t_list	*curr;

	curr = vars->list;
	while (curr != NULL)
	{
		if (curr->x == x && curr->y == y)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	pathing(int x, int y, t_vars *vars, t_size *size)
{
	if (y < 0 || x < 0 || y >= size->line || x >= size->column)
		return ;
	if (!vars->map[y] || vars->map[y][x] == '1'
		|| vars->map[y][x] == '\0' || vars->map[y][x] == '\n')
		return ;
	if (vars->map[y][x] != '1' && check_list(x, y, vars) != 0)
	{
		include_list(x, y, vars);
		pathing(x - 1, y, vars, size);
		pathing(x + 1, y, vars, size);
		pathing(x, y - 1, vars, size);
		pathing(x, y + 1, vars, size);
	}
}

int	check_pathing(t_vars *vars, t_size *size)
{
	vars->list = NULL;
	pathing(initialisation_x(vars), initialisation_y(vars), vars, size);
	if (collectible_in_range(vars) == 0 || exit_in_range(vars) == 0)
		return (0);
	return (1);
}
