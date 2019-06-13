/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:11:36 by fmasha-h          #+#    #+#             */
/*   Updated: 2018/11/27 16:17:52 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned long	i;

	i = 0;
	if (ft_strlen(src) < len)
	{
		while (i < ft_strlen(src))
		{
			dst[i] = src[i];
			i++;
		}
		while (i < len)
		{
			dst[i] = 0;
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dst);
}
