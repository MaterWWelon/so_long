/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellini <mbellini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:05:29 by mbellini          #+#    #+#             */
/*   Updated: 2022/12/01 15:30:45 by mbellini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	count_collectible(t_vars *vars)
{
	int	i;
	int	j;

	vars->coord->total_collectible = 0;
	i = 0;
	while (vars->map && vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'C')
				vars->coord->total_collectible++;
			j++;
		}
		i++;
	}
	return (vars->coord->total_collectible);
}

void	include_list(int x, int y, t_vars *vars)
{
	t_list	*list;
	t_list	*curr;

	list = malloc(sizeof(list));
	if (list == NULL)
		return ;
	list->next = NULL;
	list->x = x;
	list->y = y;
	if (vars->list == NULL)
	{
		vars->list = list;
		return ;
	}
	curr = vars->list;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = list;
}

void	free_list(t_vars *vars)
{
	t_list	*curr;
	t_list	*temp;

	curr = vars->list;
	while (curr != NULL)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	vars->list = NULL;
}
