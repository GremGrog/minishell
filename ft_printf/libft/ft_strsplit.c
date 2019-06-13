/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:02:01 by fmasha-h          #+#    #+#             */
/*   Updated: 2018/12/27 20:01:30 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_countwd(const char *s, char c)
{
	unsigned int	i;
	unsigned int	res;

	i = 0;
	res = 0;
	while (s[i] != '\0')
	{
		i++;
		if ((s[i - 1] != c && s[i] == c) || (s[i - 1] != c && s[i] == '\0'))
			res++;
	}
	return (res);
}

static	void			ft_freemem(char ***arr, unsigned int index)
{
	while (index-- > 0)
	{
		free((*arr)[index]);
		(*arr)[index] = NULL;
	}
	free(arr);
	arr = NULL;
}

static char				**ft_me(const char *s, char **arr, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	i = 0;
	j = 0;
	len = 0;
	if (!(arr = (char**)malloc(sizeof(char*) * ft_countwd(s, c) + 1)))
		return (NULL);
	while (j < ft_countwd(s, c))
	{
		len = 0;
		while (s[i] != c && s[i] != '\0')
		{
			if (s[i++] != c && s[i] != '\0')
				len++;
		}
		if (len != 0)
		{
			if (!(arr[j++] = (char *)malloc(sizeof(char) * (len) + 1)))
				ft_freemem(&arr, j);
		}
		i++;
	}
	return (arr);
}

char					**ft_strsplit(char const *s, char c)
{
	char			**arr;
	unsigned int	i;
	unsigned int	j;
	unsigned int	g;

	if (!s)
		return (NULL);
	i = 0;
	g = 0;
	arr = NULL;
	if (!(arr = ft_me(s, arr, c)))
		return (NULL);
	while (i < ft_countwd(s, c))
	{
		if (s[g] != c)
		{
			j = 0;
			while (s[g] != c && s[g] != '\0')
				arr[i][j++] = s[g++];
			arr[i++][j] = '\0';
		}
		g++;
	}
	arr[i] = NULL;
	return (arr);
}
