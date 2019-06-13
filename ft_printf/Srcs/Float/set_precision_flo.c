/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_precision_flo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:35:42 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/25 16:02:54 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

int			to_ipart(int i)
{
	while (g_buffer->str[i] != '.')
		i++;
	return (i);
}

int			round_up(int i, int flag, int i_part)
{
	while (i > i_part)
	{
		if (g_buffer->str[i] == '9' && g_buffer->str[i + 2] != '5')
		{
			if (flag == 0 && g_buffer->str[i - 1] != '9')
				flag++;
			if (g_buffer->str[i - 1] != '.')
				g_buffer->str[i] = '0';
		}
		else if (flag != 0 && g_buffer->str[i] < '9')
		{
			g_buffer->str[i]++;
			i--;
			flag = 0;
		}
		else if (i == g_buffer->str_len - 1 &&
		g_buffer->str[i + 1] >= '5' && g_buffer->str[i] < '9')
			g_buffer->str[i]++;
		if (g_buffer->str[i] == '.')
			;
		i--;
	}
	return (flag);
}

void		round_up_flo(t_pf *data, int i, int flag)
{
	int		i_part;

	i_part = to_ipart(i);
	if (data->precision > 0)
	{
		i = data->precision + i_part;
		g_buffer->str_len = i + 1;
		check_and_add(g_buffer->str_len + i);
		if (g_buffer->str[i] > '5' && g_buffer->str[i + 1] >= '5')
			flag = round_up(i, flag, i_part);
		else
		{
			copy_flo(data);
			return ;
		}
		if (flag == 1 && data->precision <= 5)
			round_up_nine(data);
		else
			ft_strcpy(g_buffer->final, g_buffer->str);
	}
	else
		round_ipart(data);
}

void		set_precision_flo(t_pf *data)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	if (g_fpart == 1.0 / 0.0 || g_fpart == -1.0 / 0.0 ||
		g_fpart != g_fpart || data->precision == 0)
		return ;
	round_up_flo(data, i, flag);
	ft_bzero(g_buffer->str, g_buffer->buff_size);
	ft_memcpy(g_buffer->str, g_buffer->final, g_buffer->str_len);
	ft_bzero(g_buffer->final, g_buffer->buff_size);
}
