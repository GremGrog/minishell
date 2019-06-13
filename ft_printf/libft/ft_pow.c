/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 21:37:40 by qmebble           #+#    #+#             */
/*   Updated: 2018/12/06 17:54:07 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_max(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

static double	ft_sqrt(double n, double s)
{
	long double	r_border;
	long double	l_border;
	long double	m;

	l_border = 0;
	r_border = ft_max(1, n);
	s = 1 / s;
	m = (l_border + r_border) / 2;
	while (ft_pow(m, (int)s) != n)
	{
		m = (l_border + r_border) / 2;
		if ((l_border / 10000) * 10000 == (r_border / 10000) * 10000)
			break ;
		if (ft_pow(m, (int)s) > n)
			r_border = m;
		else if (ft_pow(m, (int)s) < n)
			l_border = m;
	}
	return (m);
}

static double	ft_real(double n, double s)
{
	double k;

	s = ft_abs(s);
	k = ft_pow(n, s);
	return (1 / k);
}

double			ft_pow(double n, double s)
{
	double	i;
	int		k;

	if (s > 0 && s < 1)
		return (ft_sqrt(n, s));
	if (s < 0)
		return (ft_real(n, s));
	i = 1;
	k = -1;
	while (++k < s)
		i *= n;
	return (i);
}
