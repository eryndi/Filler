/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_myputnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:16:19 by dwald             #+#    #+#             */
/*   Updated: 2017/09/15 15:02:19 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_myputnbr(char *str, int n)
{
	ft_putstr(str);
	ft_putnbr_base(n, 10);
	ft_putchar('\n');
}