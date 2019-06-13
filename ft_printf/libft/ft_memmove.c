/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:51:01 by fmasha-h          #+#    #+#             */
/*   Updated: 2018/12/27 20:59:48 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long		i;
	unsigned char		*dest;
	unsigned const char	*sour;

	if (!src && !dst)
		return (NULL);
	i = -1;
	dest = (unsigned char*)dst;
	sour = (unsigned const char*)src;
	if (sour < dest)
	{
		i = len;
		while (i > 0)
		{
			dest[i - 1] = sour[i - 1];
			i--;
		}
	}
	else
	{
		while (++i < len)
			dest[i] = sour[i];
	}
	return (dest);
}
