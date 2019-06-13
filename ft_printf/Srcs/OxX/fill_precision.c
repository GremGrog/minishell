/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:43:17 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/21 16:27:29 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void		copy_str_ox(t_pf *data, int i, int j)
{
	while (data->precision-- > 0)
		g_buffer->final[i++] = '0';
	while (g_buffer->str[j] != '\0')
		g_buffer->final[i++] = g_buffer->str[j++];
	g_buffer->str_len = i;
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, g_buffer->buff_size);
}

void		fill_precision_grid(t_pf *data)
{
	int		i;
	int		j;

	if (data->type != 'o')
	{
		if (g_buffer->str[1] != 'X' && g_buffer->str[1] != 'x')
		{
			ft_fill_zero(data);
			return ;
		}
		g_buffer->final[0] = '0';
		g_buffer->final[1] = 'x';
		i = 2;
	}
	else
	{
		g_buffer->final[0] = '0';
		i = 1;
	}
	j = i;
	copy_str_ox(data, i, j);
}

void		fill_str_ox(t_pf *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data->precision > 0)
	{
		g_buffer->final[i++] = '0';
		data->precision--;
	}
	while (g_buffer->str[j] != '\0')
		g_buffer->final[i++] = g_buffer->str[j++];
	g_buffer->final[i] = '\0';
	g_buffer->str_len = i;
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, g_buffer->buff_size + 1);
}

void		val_precision(t_pf *data)
{
	if (data->type == 'o' && CHECK_BIT(data->flags, 2)
		&& g_buffer->str[0] == '0')
		return ;
	if ((data->type != 'o' && g_buffer->str[0] == '0'
	&& g_buffer->str[1] != 'x' && g_buffer->str[1] != 'X')
		|| (data->type == 'o' && data->precision == -1
			&& g_buffer->str[0] == '0')
		|| g_buffer->str[0] == '\0')
	{
		g_buffer->str[0] = '\0';
		g_buffer->str_len = 0;
		return ;
	}
}

void		fill_precision_ox(t_pf *data)
{
	int		len;

	if (!(data->precision > 0))
		val_precision(data);
	len = g_buffer->str_len - data->precision;
	len *= -1;
	if (len >= data->precision)
		return ;
	check_and_add(len);
	if (data->type != 'o' && (CHECK_BIT(data->flags, 2)))
		len += 2;
	data->precision = len;
	if (CHECK_BIT(data->flags, 2))
		fill_precision_grid(data);
	fill_str_ox(data);
}
