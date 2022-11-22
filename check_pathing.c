#include "map.h"
#include <stdio.h>

int	collectible_in_range(t_vars *vars)
{
	t_list* curr;
	int		c;

	curr = vars->list;
	//printf("x de vars->list: %d\n", vars->list->y);
	c = 0;
	while (curr != NULL)
	{
		if (vars->map[curr->y][curr->x] == 'C')
			++c;
		curr = curr->next;
	}
	printf("collectible_in_range: %d\n", c);
	printf("count_collectible: %d\n", count_collectible(vars));
	if (c != count_collectible(vars))
		return(0);
	return (1);
}

void	initialisation(t_vars *vars)
{
	vars->coord->y = 0;
	while (vars->map && vars->map[vars->coord->y])
	{
		vars->coord->x = 0;
		while (vars->map[vars->coord->y][vars->coord->x] && vars->map[vars->coord->y][vars->coord->x] != 'P')
			vars->coord->x++;
		if (vars->map[vars->coord->y][vars->coord->x] == 'P')
			break;
		vars->coord->y++;
	}
}

int		check_list(t_vars *vars)
{
	t_list* curr;
	curr = vars->list;
	while (curr != NULL)
	{
		if (curr->x == vars->coord->x && curr->y == vars->coord->y)
			return(0);
		curr = curr->next;
	}
	return(1);	
}

void	pathing(t_vars *vars, t_size *size)
{
	if (vars->coord->y < 0 || vars->coord->x < 0 || vars->coord->y >= size->line || vars->coord->x >= size->column)
		return;
	if (!vars->map[vars->coord->y] || vars->map[vars->coord->y][vars->coord->x] == '1' || vars->map[vars->coord->y][vars->coord->x] == '\0' || vars->map[vars->coord->y][vars->coord->x] == '\n')
		return;
	//printf("%c --> y:%d  x:%d\n", vars->map[vars->coord->y][vars->coord->x] ,vars->coord->y, vars->coord->x);
	if (vars->map[vars->coord->y][vars->coord->x] != '1' && check_list(vars) != 0)
	{
		include_list(vars);
		vars->coord->x--;
		pathing(vars, size);
		vars->coord->x += 2;
		pathing(vars, size);
		vars->coord->x--;
		vars->coord->y--;
		pathing(vars, size);
		vars->coord->y += 2;
		pathing(vars, size);
	}
}

int check_pathing(t_vars *vars, t_size *size)
{
	vars->list = NULL;

	initialisation(vars);
	//printf("ini\nx:%d\ny:%d\n", vars->coord->x, vars->coord->y);
	//int x = ft_strlen(vars->map[0]);
	//printf("x = %d\n", x);
	//printf("column_count: %d\n", size->line);
	//printf("column_count: %d\n", size->column);
	pathing(vars, size);
	//printf("1er carac: %d\n", vars->list->x);
	if (collectible_in_range(vars) == 0)
		return(0);
	return(1);
}