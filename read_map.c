/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellini <mbellini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:17:50 by mbellini          #+#    #+#             */
/*   Updated: 2022/05/24 12:38:34 by mbellini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
//#include <stdio.h>

//Compte le nombre de lignes dans le tableau

static int	file_linecount(char *file)
{
	int		linecount;
	int		fd;
	int		read_cursor;
	char	c;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	linecount = 1;
	while (1)
	{
		read_cursor = read(fd, &c, 1);
		if (read_cursor == 0)
			break;
		if (read_cursor < 0)
			return (-1);
		if (c == '\n')
			linecount++;
	}
	close(fd);
	return (linecount);
}

//Alloue un emplacement par ligne

static char	**init_alloc(char *file)
{
	char	**map;
	int		linecount;

	linecount = file_linecount(file);
	if (linecount <= 0)
	{
		ft_printf("%s\n", "Error\n Probleme de fichier");
		return (0);
	}
	map = malloc(sizeof(char *) * linecount + 1);
	if (map == NULL)
	{
		ft_printf("%s\n", "Error\n Probleme de malloc");
		return (0);
	}
	return (map);
}

//Alloue les caracteres de chaque ligne 1 par 1 avec l'aide de gnl

char	**read_map(char *file)
{
	char	**map;
	int		fd;
	int		i;
	int		linecount;

	linecount = file_linecount(file);
	map = init_alloc(file);
	if (map == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < linecount)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
