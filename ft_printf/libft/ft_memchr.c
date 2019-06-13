/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:13:59 by fmasha-h          #+#    #+#             */
/*   Updated: 2018/12/11 12:59:38 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*str;
	unsigned long		l;
	unsigned char		sym;

	l = 0;
	sym = (unsigned char)c;
	str = (unsigned char *)s;
	while (l < n)
	{
		if (str[l] == sym)
			return (&str[l]);
		l++;
	}
	return (NULL);
}
