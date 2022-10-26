#include "map.h"
#include <stdio.h>
/*
int	count_collectible(char **map)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}
*/

void	initialisation(char **map, t_coord *coord)
{
	coord->x = 0;
	while (map && map[coord->x])
	{
		coord->y = 0;
		while (map[coord->x][coord->y] && map[coord->x][coord->y] != '0')
			coord->y++;
		if (map[coord->x][coord->y] == '0')
			break;
		coord->x++;
	}
}

void	pathing(char **map, t_coord *coord)
{
	printf("map[x][y]:%c\n", map[coord->x][coord->y]);
	if (map[coord->x][coord->y] == '1' || map[coord->x][coord->y] == '\n')
		return;
	if (map[coord->x][coord->y] != '1')
	{
		map[coord->x][coord->y] = '1';
		coord->x--;
		pathing(map, coord);
		coord->x += 2;
		pathing(map, coord);
		coord->x--;
		coord->y--;
		pathing(map, coord);
		coord->y += 2;
		pathing(map, coord);
	}
}

int check_pathing(char **map, t_coord *coord)
{
	int i;
	int j;

	initialisation(map, coord);
	printf("ini\nx:%d\ny:%d\n", coord->x, coord->y);
	pathing(map, coord);

	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
		}
	}

	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				return(0);
			j++;
		}
		i++;
	}
	return(1);
}