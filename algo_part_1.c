/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_part_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:29:15 by dwald             #+#    #+#             */
/*   Updated: 2017/11/20 14:47:16 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.player.h"

/*
** Checks for errors which disqualifies potential move and sets boundaries for
** tested area.
*/

static	int		check_axe_x(t_struct *t_map, t_dbl *t_strat, int x, int y)
{
	int		max_radius;
	int		tmp;

	if (t_strat->koef_x + x >= t_map->x
	|| t_strat->koef_y + y >= t_map->y)
		return (-1);
	if (t_map->playfield[t_strat->koef_x + x][t_strat->koef_y + y]
	!= '.')
		return (-1);
	max_radius = (t_map->x > t_map->y) ? t_map->x - 1 : t_map->y - 1;
	tmp = check_radius(t_map, t_strat->koef_x + x, t_strat->koef_y + y,
	max_radius);
	return (tmp);
}

/*
** One by one checks every coodinate of playing piece transposed on the
** playfield. Playing piece has a fixed point of contact with the player's coor-
** dinate determined by variables x and y. Function return the smallest distance
** found between tested move and enemy coordinates.
*/

int				check_piece_fit(t_struct *t_map, t_dbl *t_strat, int x, int y)
{
	int		x_axe;
	int		y_axe;
	int		distance;
	int		tmp;

	distance = INT_MAX;
	tmp = INT_MAX;
	t_strat->koef_x = x - t_strat->case_x;
	t_strat->koef_y = y - t_strat->case_y;
	y_axe = -1;
	while (++y_axe < t_map->piece_y)
	{
		x_axe = -1;
		while (++x_axe < t_map->piece_x)
			if ((t_map->piece[x_axe][y_axe] == '*')
			&& ((t_strat->koef_y + y_axe < 0 || t_strat->koef_x + x_axe < 0)
			|| (((t_strat->koef_x + x_axe >= 0 && t_strat->koef_y + y_axe >= 0)
			&& (t_strat->koef_x + x_axe != x || t_strat->koef_y + y_axe != y))
			&& ((tmp = check_axe_x(t_map, t_strat, x_axe, y_axe)) == -1))))
				return (-1);
		distance = (tmp > distance && tmp != -1) ? distance : tmp;
	}
	return (distance);
}

/*
** Initiate deep analysis of players coordinate on the playefield which has been
** identified as potential point of contact with a playing piece.
** Function stores the best identified position meaning the closest to the enemy
*/

static	void	point_of_contact(t_struct *t_map, t_dbl *t_strat, int x, int y)
{
	int		tmp_distance;

	tmp_distance = 0;
	t_map->holy_grail = t_map->enemy;
	while (get_case(t_map, t_strat) == 1)
	{
		tmp_distance = check_piece_fit(t_map, t_strat, x, y);
		if (t_strat->distance > tmp_distance && tmp_distance != -1)
		{
			t_strat->distance = tmp_distance;
			t_strat->best_x = x;
			t_strat->best_y = y;
			t_strat->best_case_x = t_strat->case_x;
			t_strat->best_case_y = t_strat->case_y;
		}
	}
	return ;
}

/*
** Will compare one by one all relevant pieces of player on the plan against all
** relevant pieces of enemy in order to find a pair which are the closest.
** Player's relevant pieces are determined by function check_radius which looks
** for at least 1 free point in the perimeter of the tested player's coordinate.
*/

void			algo_launcher(t_struct *t_map, t_dbl *t_strat)
{
	int		x;
	int		y;
	char	free_coordinates[2];

	clear_strategy(t_strat);
	ft_strncat(free_coordinates, ".", 1);
	x = -1;
	while (++x < t_map->x)
	{
		y = 0;
		while (t_map->playfield[x][y] != '\0')
		{
			t_map->holy_grail = free_coordinates;
			if (((t_map->playfield[x][y] == t_map->player[0])
			|| (t_map->playfield[x][y] == t_map->player[1]))
			&& (check_radius(t_map, x, y, 1) != INT_MAX))
			{
				t_strat->case_x = -1;
				t_strat->case_y = -1;
				point_of_contact(t_map, t_strat, x, y);
			}
			y++;
		}
	}
	send_turn(t_map, t_strat);
}
