/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:19:05 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/25 15:38:16 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void					ft_copy_float(char *x, short sign)
{
	int		i;
	int		j;
	int		o;
	int		l;

	j = 0;
	i = 0;
	o = 398;
	while (x[i] == 0)
		i++;
	while (x[o] == 0)
		o--;
	if (i == 1)
		i--;
	l = o - i;
	check_and_add(g_buffer->str_len + l);
	if (sign == 1)
		g_buffer->str[j++] = '-';
	while (l >= 0)
		g_buffer->str[j++] = x[l--] + '0';
	g_buffer->str_len = j;
	get_ipart();
	free(x);
}

void					copy_long_double_other(char *x, short sign)
{
	int		i;
	int		j;
	int		o;
	int		l;

	j = 0;
	i = 0;
	o = 4998;
	while (x[i] == 0)
		i++;
	while (x[o] == 0)
		o--;
	if (i == 1)
		i--;
	l = o - i;
	check_and_add(g_buffer->str_len + l);
	if (sign == 1)
		g_buffer->str[j++] = '-';
	while (l >= 0)
		g_buffer->str[j++] = x[l--] + '0';
	g_buffer->str_len = j;
	get_ipart();
	free(x);
}

void					copy_long_double(char *z, int n, short sign)
{
	int					i;
	int					j;
	int					o;

	o = 4998;
	i = -1;
	j = 0;
	while (z[++i] == 0)
		n--;
	while (z[o] == 0)
		o--;
	check_and_add(g_buffer->str_len + (o - i));
	while (n-- > 0 && i < 4998)
	{
		g_buffer->str[j++] = z[i++] + '0';
		if (n == 0)
			g_buffer->str[j++] = '.';
	}
	while (i <= o)
		g_buffer->str[j++] = z[i++] + '0';
	if (sign == 1)
		g_buffer->str[j++] = '-';
	g_buffer->str_len = j;
	ft_strrev();
	get_ipart();
}
