#include "map.h"

int	window_height(char **map)
{
	int	w_height;

	w_height = line_count(map) * 40;
	return (w_height);
}

int	window_length(char **map)
{
	int	w_length;

	w_length = column_count(map) * 40;
	return (w_length);
}