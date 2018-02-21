/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:32:58 by dwald             #+#    #+#             */
/*   Updated: 2017/09/29 17:22:53 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	if ((dup = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1)) == NULL)
		ft_protect_malloc();
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
