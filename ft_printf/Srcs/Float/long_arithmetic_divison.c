/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithmetic_divison.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:56:36 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/25 15:38:16 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void				long_arithmetic_div_d(char *z, int n, char *y)
{
	int				temp;
	int				i;
	int				j;

	i = 0;
	j = 0;
	temp = n;
	while (z[i] == 0)
	{
		n--;
		i++;
	}
	while (n-- > 0)
	{
		y[j++] = z[i++] % 10;
		if (n == 0)
			y[j++] = -2;
	}
	i = 398;
	while (z[i] == 0)
		i--;
	temp = i - temp + 1;
	while (--temp >= 0)
		y[j++] = z[i - temp] % 10;
}

void				long_arithmetic_div_ld(char *z, int n, char *y)
{
	int				temp;
	int				i;
	int				j;

	i = 0;
	j = 0;
	temp = n;
	while (z[i] == 0)
	{
		n--;
		i++;
	}
	while (n-- > 0)
	{
		y[j++] = z[i++] % 10;
		if (n == 0)
			y[j++] = -2;
	}
	i = 4998;
	while (z[i] == 0)
		i--;
	temp = i - temp + 1;
	while (--temp >= 0)
		y[j++] = z[i - temp] % 10;
}
