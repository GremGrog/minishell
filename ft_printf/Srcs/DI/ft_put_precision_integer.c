/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_precision_integer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:00:45 by qmebble           #+#    #+#             */
/*   Updated: 2019/05/24 13:11:18 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

int		num_len_integer(__int128 num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		num *= -1;
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

void	working_precision_integer(t_pf *data, int flag)
{
	int		i;
	int		j;
	int		len;

	len = num_len_integer(g_integer) - data->precision;
	if (len >= 0)
		return ;
	if (g_buffer->str[0] == '-')
		flag = 1;
	check_and_add(flag - len);
	i = 0;
	if (g_buffer->str[0] == '-')
		g_buffer->final[i++] = '-';
	j = 0;
	while (j++ < (-1) * len)
		g_buffer->final[i++] = '0';
	len = flag;
	while (g_buffer->str[len] != '\0' && g_buffer->str[len])
		g_buffer->final[i++] = g_buffer->str[len++];
	g_buffer->str_len = i;
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, g_buffer->buff_size + 1);
}

void	ft_put_precision_integer(t_pf *data)
{
	if (!data->precision)
		return ;
	if (g_buffer->str[0] == '0' && data->precision == -1)
	{
		g_buffer->str[0] = '\0';
		g_buffer->str_len = 0;
		return ;
	}
	working_precision_integer(data, 0);
}
