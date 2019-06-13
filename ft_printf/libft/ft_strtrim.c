/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:59:36 by fmasha-h          #+#    #+#             */
/*   Updated: 2018/12/26 20:08:14 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			*str;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	if (*s != '\0')
	{
		j = ft_strlen(s) - 1;
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && (s[i] != '\0'))
			i++;
		while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && (j != 0))
			j--;
		if (!(str = (char*)malloc(sizeof(char) * (j - i) + 2)))
			return (NULL);
		while (i <= j && s[i] != '\0')
			str[k++] = s[i++];
	}
	else
		str = (char*)malloc(sizeof(char) + 1);
	str[k] = '\0';
	return (str);
}
