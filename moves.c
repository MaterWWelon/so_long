#include "map.h"
#include <stdio.h>

void	move_up(char **map)
{
	t_vars	vars;
	int	i;
	int	j;

	printf("test\n");
	i = 0;
	while (map && map[i])
	{
		printf("i:%d\n", i);
		j = 0;
		while (map[i][j])
		{
			//printf("%c", map[i][j]);
			if (map[i][j] == 'P')
			{
				printf("initial: %c", map[i][j]);
				map[i][j] = '0';
				printf("final: %c", map[i][j]);
				map[i - 1][j] = 'P';
				break;
			}
			j++;
		}
		i++;
	}
	create_map(map, vars);
}