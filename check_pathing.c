#include "map.h"
#include <stdio.h>

typedef struct s_coord
{
	int	x;
	int	y;
}				t_coord;


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

int	check_pathing(char **map)
{
	int	i;
	int	j;
	//int	c;
	int	c_total;

	c_total = count_collectible(map);
	printf("c_total: %d\n", c_total);



	return (0);
}