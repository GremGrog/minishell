/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_double_manipulation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 17:37:59 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/20 16:08:23 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void			multiplication_on_short_ld(char *src, int num, char *dst)
{
	int				i;
	int				temp;
	int				d;

	i = 0;
	while (i < 4999)
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

char			*get_five_power_ld(int power, short exp, char *pow, char *bow)
{
	power -= exp;
	pow[0] = 5;
	if (!(power > 1))
		return (pow);
	while (power > 0)
	{
		multiplication_on_short_ld(pow, 5, bow);
		set_arr_to_null(pow, 4999);
		power--;
		if (power == 1)
		{
			free(pow);
			return (bow);
		}
		multiplication_on_short_ld(bow, 5, pow);
		set_arr_to_null(bow, 4999);
		power--;
		if (power == 1)
			break ;
	}
	free(bow);
	return (pow);
}

char			*get_two_power_ld(int power, char *pow, char *bow)
{
	pow[0] = 2;
	if (!(power > 1))
		return (pow);
	while (power > 0)
	{
		multiplication_on_short_ld(pow, 2, bow);
		set_arr_to_null(pow, 4999);
		power--;
		if (power == 1)
		{
			free(pow);
			return (bow);
		}
		multiplication_on_short_ld(bow, 2, pow);
		set_arr_to_null(bow, 4999);
		power--;
		if (power == 1)
			break ;
	}
	free(bow);
	return (pow);
}

void			multiplication_loop_ld(int j, char *x, char *y, char *z)
{
	int				temp;
	int				i;

	i = 0;
	while (i < 4999 && (i + j) < 4999)
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

void			multiplication_long_ld(char *x, char *y, char *z)
{
	int				j;

	j = 0;
	while (j < 4999)
	{
		multiplication_loop_ld(j, x, y, z);
		j++;
	}
}
