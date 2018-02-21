/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.player.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 13:34:30 by dwald             #+#    #+#             */
/*   Updated: 2018/01/12 14:31:01 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_PLAYER_H
# define FILLER_PLAYER_H 

/*
** ------------------------------ Librairies -----------------------------------
*/
 
# include "libft.h"
# include <errno.h>

/*
** ---------------------------- player variables -------------------------------
*/

typedef struct	s_struct
{
	int			x;
	int			y;
	int			row;
	char		**playfield;
	int			piece_x;
	int			piece_y;
	char		**piece;
	char		player[3];
	char		enemy[3];
	char		*holy_grail;
	
}				t_struct;

typedef	struct	s_dbl
{
	int			koef_x;
	int			koef_y;
	int			case_x;
	int			case_y;
	int 		best_x;
	int 		best_y;
	int			best_case_x;
	int			best_case_y;
	int			distance;
}				t_dbl;

/*
** --------------------------- player main functions ---------------------------
*/

void	get_player(char *content, t_struct *t_map);
void	ft_parser(char *content, t_struct *map);
void	ft_prepare_struct(t_struct *t_map);
char	**allocate_memory(int x, int y);
void    send_turn(t_struct *t_map, t_dbl *t_strat);

/*
** -------------------------------- algorhitm ----------------------------------
*/

void    algo_launcher(t_struct *t_map, t_dbl *t_strat);
int		check_radius(t_struct *t_map, int x, int y, int radius);
int		check_if_piece_fits(t_struct *t_map, t_dbl *t_strat, int x, int y);
int		get_case(t_struct *t_map, t_dbl *t_strat);
void	clear_strategy(t_dbl *t_strat);

#endif
