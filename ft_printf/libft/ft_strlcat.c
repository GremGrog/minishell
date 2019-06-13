/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:33:41 by fmasha-h          #+#    #+#             */
/*   Updated: 2018/12/20 18:46:20 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	size_t			n;
	size_t			b;

	i = 0;
	j = 0;
	n = ft_strlen(dst);
	b = ft_strlen(src);
	while (dst[i] != '\0')
		i++;
	if (size < n)
		return (b + size);
	else
	{
		while (n < size-- - 1 && src[j] != '\0')
		{
			dst[i++] = src[j++];
		}
	}
	dst[i] = '\0';
	return (n + b);
}
