/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellini <mbellini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:31:43 by mbellini          #+#    #+#             */
/*   Updated: 2022/12/01 13:32:15 by mbellini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	line_count(t_vars *vars, t_size *size)
{
	size->line = 0;
	while (vars->map[size->line])
		++size->line;
}

void	column_count(t_vars *vars, t_size *size)
{
	size->column = 0;
	while (vars->map[0][size->column] != '\n')
		++size->column;
}
