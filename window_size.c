#include "map.h"

int	window_height(t_size *size)
{
	int	w_height;

	w_height = size->line * 40;
	return (w_height);
}

int	window_length(t_size *size)
{
	int	w_length;

	w_length = size->column * 40;
	return (w_length);
}