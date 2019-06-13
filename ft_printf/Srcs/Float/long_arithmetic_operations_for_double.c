/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:35:30 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/25 15:46:38 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void				multiplication_on_short(char *src, int num, char *dst)
{
	int				i;
	int				temp;
	int				d;

	i = 0;
	while (i < 399)
	{
		temp = src[i] * num;
		if (temp >= 10)
		{
			dst[i] += temp % 10;
			if (dst[i] >= 10)
			{
				d = dst[i];
				dst[i] = d % 10;
				dst[i + 1] += d / 10;
			}
			else
				dst[i + 1] = temp / 10;
		}
		else
			dst[i] += temp;
		i++;
	}
}

char				*get_five_power(int power, short exp, char *pow, char *bow)
{
	power -= exp;
	pow[0] = 5;
	if (!(power > 1))
		return (pow);
	while (power > 0)
	{
		multiplication_on_short(pow, 5, bow);
		set_arr_to_null(pow, 399);
		power--;
		if (power == 1)
		{
			free(pow);
			return (bow);
		}
		multiplication_on_short(bow, 5, pow);
		set_arr_to_null(bow, 399);
		power--;
		if (power == 1)
			break ;
	}
	free(bow);
	return (pow);
}

char				*get_two_power(int power, char *pow, char *bow)
{
	pow[0] = 2;
	if (!(power > 1))
		return (pow);
	while (power > 0)
	{
		multiplication_on_short(pow, 2, bow);
		set_arr_to_null(pow, 399);
		power--;
		if (power == 1)
		{
			free(pow);
			return (bow);
		}
		multiplication_on_short(bow, 2, pow);
		set_arr_to_null(bow, 399);
		power--;
		if (power == 1)
			break ;
	}
	free(bow);
	return (pow);
}

void				multiplication_loop(int j, char *x, char *y, char *z)
{
	int				temp;
	int				i;

	i = 0;
	while (i < 399 && (i + j) < 399)
	{
		temp = z[i + j] + (x[i] * y[j]);
		if (temp >= 10)
		{
			z[i + j] = temp % 10;
			if (z[i + j] >= 10)
			{
				z[i + j] = z[i + j] % 10;
				z[i + j + 1] += z[i + j] / 10;
			}
			else
				z[i + j + 1] += temp / 10;
		}
		else
			z[i + j] = temp;
		i++;
	}
}

void				multiplication_long(char *x, char *y, char *z)
{
	int				j;

	j = 0;
	while (j < 399)
	{
		multiplication_loop(j, x, y, z);
		j++;
	}
}
