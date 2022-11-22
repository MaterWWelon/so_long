#include "map.h"

int	count_collectible(t_vars *vars)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = 0;
	while (vars->map && vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}


void	include_list(t_vars *vars)
{
	t_list *list;
	list = malloc(sizeof(list));
	if (list == NULL)
		return;	
	list->next = NULL;
	list->x = vars->coord->x;
	list->y = vars->coord->y;
	if (vars->list == NULL)
	{
		vars->list = list;
		return;
	}
	t_list* curr;
	curr = vars->list;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = list;
}

void	free_list(t_vars *vars)
{
	t_list* curr;
	curr = vars->list;
	while (curr != NULL)
	{
		t_list* temp;
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	vars->list = NULL;
}