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
		while (map[coord->x][coord->y] && map[coord->x][coord->y] != 'P')
			coord->y++;
		if (map[coord->x][coord->y] == 'P')
			break;
		coord->x++;
	}
}

void	pathing(char **map, t_coord *coord, t_size *size)
{
	if (coord->x < 0 || coord->y < 0 || coord->x >= size->line || coord->y >= size->column)
		return;
	if (!map[coord->x] || map[coord->x][coord->y] == '1' || map[coord->x][coord->y] == '\0' || map[coord->x][coord->y] == '\n')
		return;
	printf("%c --> x:%d  y:%d\n", map[coord->x][coord->y] ,coord->x, coord->y);
	if (map[coord->x][coord->y] != '1')
	{
		map[coord->x][coord->y] = '1';
		coord->x--;
		pathing(map, coord, size);
		coord->x += 2;
		pathing(map, coord, size);
		coord->x--;
		coord->y--;
		pathing(map, coord, size);
		coord->y += 2;
		pathing(map, coord, size);
	}
}

int check_pathing(char **map, t_coord *coord, t_size *size)
{
	int i;
	int j;

	initialisation(map, coord);
	printf("ini\nx:%d\ny:%d\n", coord->x, coord->y);
	int x = ft_strlen(map[0]);
	printf("x = %d\n", x);
	printf("column_count: %d\n", size->line);
	printf("column_count: %d \'c=%c\'\n", size->column, map[2][10]);
	pathing(map, coord, size);

	i = 0;
	while (map && map[i] && i < size->line)
	{
		j = 0;
		while (map[i][j] && j < size->column)
		{
			printf("%c", map[i][j]);
			++j;
		}
		printf("\n");
		++i;
	}

	i = 0;
	while (map && map[i] && i < size->line)
	{
		j = 0;
		while (map[i][j] && j < size->column)
		{
			if (map[i][j] != '1')
				return(0);
			j++;
		}
		i++;
	}
	return(1);
}