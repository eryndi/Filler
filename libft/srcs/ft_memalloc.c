/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:03:29 by dwald             #+#    #+#             */
/*   Updated: 2017/09/29 17:20:10 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *area;

	if ((area = (void*)malloc(sizeof(size_t) * size)) == NULL)
		ft_protect_malloc();
	ft_bzero(area, size);
	return (area);
}
