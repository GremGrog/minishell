/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:47:17 by fmasha-h          #+#    #+#             */
/*   Updated: 2018/12/27 19:13:32 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*dest;
	const char		*source;

	i = 0;
	if (!src && !dst)
		return (NULL);
	dest = (char*)dst;
	source = (const char*)src;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}
