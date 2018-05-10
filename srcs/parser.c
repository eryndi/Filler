/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:17:55 by dwald             #+#    #+#             */
/*   Updated: 2017/11/20 15:00:42 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.player.h"

void			get_player(char *content, t_struct *t_map)
{
	if (ft_strnstr(content, "$$$ exec p2", 11)
	&& ft_strstr(content, "dwald.filler"))
	{
		ft_strncat(t_map->enemy, "Oo", 2);
		ft_strncat(t_map->player, "Xx", 2);
		return ;
	}
	else
	{
		ft_strncat(t_map->enemy, "Xx", 2);
		ft_strncat(t_map->player, "Oo", 2);
		return ;
	}
}

static	int		get_coord(char **content)
{
	int		i;
	char	tmp[11];

	i = 0;
	ft_bzero(tmp, 11);
	if (**content == ' ')
		(*content)++;
	while (**content != ' ' || **content != '\n')
	{
		while (ft_isdigit((int)**content) == 1)
		{
			tmp[i++] = **content;
			(*content)++;
		}
		return (ft_atoi(tmp));
	}
	return (-1);
}

static	char	**get_map(char **ptr, t_struct *t_map, char **plan)
{
	int		x;
	int		x_max;
	int		y_max;

	x = 0;
	x_max = (t_map->piece_x == -1) ? t_map->x : t_map->piece_x;
	y_max = (t_map->piece_y == -1) ? t_map->y : t_map->piece_y;
	if (t_map->piece_x == -1 && t_map->piece_y == -1)
	{
		*ptr = ft_strchr(*ptr, ' ');
		(*ptr)++;
	}
	while (x < x_max)
	{
		plan[x++][t_map->row] = **ptr;
		(*ptr)++;
	}
	t_map->row++;
	return (plan);
}

static	void	get_coordinates_and_allocate_memory(t_struct *t_map, char *ptr)
{
	t_map->piece_y = (t_map->y != -1) ? get_coord(&ptr) : t_map->piece_y;
	t_map->piece_x = (t_map->x != -1) ? get_coord(&ptr) : t_map->piece_x;
	t_map->y = (t_map->y == -1) ? get_coord(&ptr) : t_map->y;
	t_map->x = (t_map->x == -1) ? get_coord(&ptr) : t_map->x;
	if (t_map->playfield == NULL)
		t_map->playfield = allocate_memory(t_map->x, t_map->y);
	if (t_map->piece_y != -1 && t_map->piece_x != -1)
	{
		t_map->row = 0;
		t_map->piece = allocate_memory(t_map->piece_x, t_map->piece_y);
	}
}

void			ft_parser(char *content, t_struct *t_map)
{
	char	*ptr;
	t_dbl	t_strat;

	ptr = content;
	if (!t_map->player[0])
		get_player(content, t_map);
	if (ft_strnstr(content, "Plateau", 7) || ft_strnstr(content, "Piece", 5))
	{
		if (ft_strnstr(content, "Piece", 5) && t_map->playfield == NULL)
			exit(0);
		ptr += (ft_strnstr(content, "Plateau", 7)) ? 7 : 6;
		t_map->row = (ft_strnstr(content, "Plateau", 7)) ? 0 : t_map->row;
		get_coordinates_and_allocate_memory(t_map, ptr);
	}
	else if (ft_isdigit((int)content[0]) == 1)
		t_map->playfield = get_map(&ptr, t_map, t_map->playfield);
	else if (ft_strchr(".*", content[0]))
		t_map->piece = get_map(&ptr, t_map, t_map->piece);
	if (t_map->piece != NULL && t_map->piece_x != -1 && t_map->piece_y != -1
	&& t_map->piece[t_map->piece_x - 1][t_map->piece_y - 1] != '\0')
		algo_launcher(t_map, &t_strat);
	ptr = content;
	ft_strdel(&ptr);
}
