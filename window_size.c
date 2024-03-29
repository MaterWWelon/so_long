/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellini <mbellini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:17:50 by mbellini          #+#    #+#             */
/*   Updated: 2022/12/01 15:31:10 by mbellini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
