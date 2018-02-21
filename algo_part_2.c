/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_part_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:56:18 by dwald             #+#    #+#             */
/*   Updated: 2017/11/20 14:59:46 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.player.h"

/*
** Searches * (case) of piece to analyze.
*/

int			get_case(t_struct *t_map, t_dbl *t_strat)
{
	if (t_strat->case_y >= t_map->piece_y)
		return (-1);
	while (t_strat->case_y < t_map->piece_y)
	{
		while ((++t_strat->case_x < t_map->piece_x)
		&& (t_strat->case_x >= 0 && t_strat->case_y >= 0))
		{
			if (t_map->piece[t_strat->case_x][t_strat->case_y] == '*')
				return (1);
		}
		t_strat->case_x = -1;
		t_strat->case_y++;
	}
	return (0);
}

void		clear_strategy(t_dbl *t_strat)
{
	t_strat->distance = INT_MAX;
	t_strat->best_x = INT_MAX;
	t_strat->best_y = INT_MAX;
	t_strat->best_case_x = -1;
	t_strat->best_case_y = -1;
	t_strat->case_x = -1;
	t_strat->case_y = -1;
}

static	int	check_boundaries(int i, int j, int radius)
{
	if (j == -radius || j == radius)
		i++;
	else
	{
		if (i == -radius)
			i = radius;
		else if (i == radius)
			return (-1);
	}
	return (i);
}

int			check_radius(t_struct *t_map, int x, int y, int max_radius)
{
	int		i;
	int		j;
	int		radius;

	radius = 1;
	while (radius <= max_radius)
	{
		j = -radius;
		while (j <= radius && (j + y) < t_map->y)
		{
			i = -radius;
			while ((i <= radius && (i + x) < t_map->x))
			{
				if (((x + i) >= 0 && (y + j) >= 0)
				&& ((t_map->playfield[x + i][y + j] == t_map->holy_grail[0])
				|| (t_map->playfield[x + i][y + j] == t_map->holy_grail[1])))
					return (radius);
				if ((i = check_boundaries(i, j, radius)) == -1)
					break ;
			}
			j++;
		}
		radius++;
	}
	return (INT_MAX);
}

char		**allocate_memory(int x, int y)
{
	int		i;
	char	**memory;

	i = 0;
	if (!(memory = (char**)malloc(sizeof(char*) * x)))
		ft_protect_malloc();
	while (i < x)
		memory[i++] = ft_strnew(y);
	return (memory);
}
