/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 15:25:41 by dwald             #+#    #+#             */
/*   Updated: 2017/11/20 15:15:08 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.player.h"

void			ft_prepare_struct(t_struct *t_map)
{
	t_map->x = -1;
	t_map->y = -1;
	t_map->row = 0;
	t_map->playfield = NULL;
	t_map->piece_x = -1;
	t_map->piece_y = -1;
	t_map->piece = NULL;
	t_map->holy_grail = NULL;
	ft_bzero(t_map->player, 3);
	ft_bzero(t_map->enemy, 3);
	return ;
}

static	char	**free_memory(char **map, int x)
{
	int		i;

	i = 0;
	while (i < x)
		ft_strdel(&map[i++]);
	free(map);
	return (NULL);
}

void			send_turn(t_struct *t_map, t_dbl *t_strat)
{
	int	koef_x;
	int	koef_y;

	koef_x = t_strat->best_x - t_strat->best_case_x;
	koef_y = t_strat->best_y - t_strat->best_case_y;
	t_map->playfield = free_memory(t_map->playfield, t_map->x);
	t_map->piece = free_memory(t_map->piece, t_map->piece_x);
	t_map->y = -1;
	t_map->x = -1;
	t_map->piece_y = -1;
	t_map->piece_x = -1;
	if (t_strat->best_x == INT_MAX && t_strat->best_y == INT_MAX)
	{
		ft_dprintf(1, "%d %d\n", 0, 0);
		return ;
	}
	else
		ft_dprintf(1, "%d %d\n", koef_y, koef_x);
}

static	int		ft_error(void)
{
	ft_putendl(strerror(errno));
	exit(1);
}

int				main(void)
{
	t_struct	t_map;
	char		*content;
	int			ret;

	errno = 0;
	ft_prepare_struct(&t_map);
	while ((ret = get_next_line(STDIN_FILENO, &content)) > 0)
		ft_parser(content, &t_map);
	if (close(STDIN_FILENO) < 0)
		ft_error();
	return (0);
}
