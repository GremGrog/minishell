/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:21:21 by qmebble           #+#    #+#             */
/*   Updated: 2018/12/05 20:55:24 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *s, int size)
{
	int		i;
	int		len;
	char	*c;
	char	*x;
	int		j;

	x = (char *)s;
	i = -1;
	j = -1;
	len = ft_strlen((char *)s) + 1 + size;
	if (!x || !(c = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	while (x[++i])
	{
		c[i] = x[i];
	}
	while (++j < size)
	{
		c[i] = 'u';
		i++;
	}
	c[i] = '\0';
	return ((void *)c);
}
