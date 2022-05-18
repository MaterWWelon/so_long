#include "map.h"

int	line_count(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return(i);
}

int	column_count(char **map)
{
	int j;

	j = 0;
	while (map[0][j] != '\n')
		j++;
	return(j);
}

int	check_dim_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
			j++;
		if (j != column_count(map))
			return(0);
		i++;
	}
	return(1);
}

int	check_murs(char **map)
{
	int	linecount;
	int	columncount;
	int	i;
	int	j;

	linecount = line_count(map);
	columncount = column_count(map);
	j = 0;
	while (map[0][j] == '1' && map[linecount - 1][j] == '1')
		j++;
	if (j != columncount)
		return(0);
	
	i = 0;
	while (i < linecount && map[i][0] == '1' && map[i][columncount - 1] == '1')
		i++;
	if (i != linecount)
		return(0);
	return(1);	
}

int	check_contenu(char **map)
{
	int	i;
	int	j;
	int	personnage;
	int	exit;
	int	collectible;

	personnage = 0;
	exit = 0;
	collectible = 0;

	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' && personnage == 1)
			{
				ft_printf("%s\n", "Error\n-->Il doit y avoir 1 personnage au max");
				return(0);
			}
			else if (map[i][j] == 'P' && personnage == 0)
				personnage = 1;

			if (map[i][j] == 'E' && exit == 1)
			{
				ft_printf("%s\n", "Error\n-->Il doit y avoir 1 exit au max");
				return(0);
			}
			else if (map[i][j] == 'E' && exit == 0)
				exit = 1;

			if (map[i][j] == 'C' && collectible == 0)
				collectible = 1;
			j++;
		}
		i++;
	}
	if (personnage == 0 || exit == 0 || collectible == 0)
	{
		ft_printf("%s\n", "Error\n-->Il doit y avoir au moins 1 personnage/exit/collectible");
		return(0);
	}
	return(1);
}

int	check_map(char **map)
{
	if (!map)
	{
		ft_printf("%s\n", "Error\n-->Aucune map presente");
		return(0);
	}	
	if (check_dim_map(map) == 0)
	{
		ft_printf("%s\n", "Error\n-->Mauvaises dimentions de map");
		return(0);
	}
	if (check_murs(map) == 0)
	{
		ft_printf("%s\n", "Error\n-->Murs non conformes");
		return(0);
	}
	if (check_contenu(map) == 0)
		return(0);
	return(1);
}

int	main()
{
	int	i = 0;
	int j;
	char **map;

	map = read_map("map1.ber");
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		i++;
	}
	printf("\n");
	printf("check map: %d\n", check_contenu(map));
}