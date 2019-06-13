/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_up_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 14:05:46 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/25 14:22:49 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void		fill_zero(t_pf *data)
{
	int		i;

	i = g_buffer->str_len;
	g_buffer->final[i++] = '.';
	while (data->precision > 0)
	{
		g_buffer->final[i++] = '0';
		data->precision--;
	}
	g_buffer->str_len = i;
}

void		add_one(int i, int j)
{
	j = i;
	g_buffer->str_len = j;
	while (i > 0)
	{
		if (g_buffer->str[i] == '9')
			if (g_buffer->final[j] != '9')
				g_buffer->final[j]++;
			else
			{
				g_buffer->final[j] = '0';
				g_buffer->final[j - 1] == '9' ? g_buffer->final[j - 1] = '0'
												: g_buffer->final[j - 1]++;
				j--;
			}
		else if (g_buffer->str[i + 1] == '9')
		{
			if (g_buffer->final[j - 1] != '9')
				g_buffer->final[j - 1]++;
			if (g_buffer->final[j - 1] == '9')
				g_buffer->final[j - 1] = '0';
			j--;
		}
		j--;
		i--;
	}
}

void		add_extra(t_pf *data, int n)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	g_buffer->final[j++] = '1';
	while (j <= n)
	{
		if (g_buffer->str[i] == '.')
		{
			if (data->precision == -1)
				break ;
			g_buffer->final[j++] = '.';
		}
		else
			g_buffer->final[j++] = '0';
		i++;
	}
	g_buffer->str_len = j;
}

void		round_up_nine(t_pf *data)
{
	int		i;
	int		j;
	int		n;
	int		flag;

	n = g_buffer->str_len;
	i = 0;
	j = 0;
	flag = 0;
	while (g_buffer->str[i] != '.')
	{
		if (g_buffer->str[i] == '9')
			flag++;
		g_buffer->final[j++] = g_buffer->str[i++];
	}
	if (flag < i)
	{
		add_one(i, j);
		if (data->precision > 0)
			fill_zero(data);
	}
	if (flag == i)
		add_extra(data, n);
}

void		copy_flo(t_pf *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (g_buffer->str[i] != '.')
		g_buffer->final[j++] = g_buffer->str[i++];
	g_buffer->final[j++] = g_buffer->str[i++];
	while (data->precision > 0)
	{
		if (g_buffer->str[i] == '\0')
		{
			while (data->precision-- > 0)
				g_buffer->final[j++] = '0';
		}
		else
		{
			g_buffer->final[j++] = g_buffer->str[i++];
			data->precision--;
		}
	}
	if (g_buffer->str[i] >= '5')
		g_buffer->final[j - 1]++;
	g_buffer->str_len = j;
}
