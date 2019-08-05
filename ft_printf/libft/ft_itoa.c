/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:24:09 by fmasha-h          #+#    #+#             */
/*   Updated: 2018/12/26 20:04:52 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strrev(char *s)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	i = 0;
	j = ft_strlen(s) - 1;
	str = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (str == 0)
		return (NULL);
	if (s[0] == '-')
		str[i++] = s[0];
	while (i < ft_strlen(s))
		str[i++] = s[j--];
	str[i] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				i;
	unsigned int	d;

	i = 0;
	d = (unsigned int)n;
	str = (char*)malloc(sizeof(char) * 128);
	if (str == 0)
		return (NULL);
	if (n < 0)
	{
		d = n * (-1);
		str[i++] = '-';
	}
	if (d == 0)
		str[i++] = '0';
	while (d > 0)
	{
		str[i++] = d % 10 + '0';
		d /= 10;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
