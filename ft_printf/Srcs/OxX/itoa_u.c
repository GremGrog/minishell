/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:50:59 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/17 17:50:59 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

int					num_len_m(unsigned long long int num)
{
	int			i;
	__int128_t	n;

	n = num;
	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char				check_ox_u(unsigned long long int num, short base)
{
	if (num % base == 10)
		return ('a');
	else if (num % base == 11)
		return ('b');
	if (num % base == 12)
		return ('c');
	else if (num % base == 13)
		return ('d');
	if (num % base == 14)
		return ('e');
	else
		return ('f');
}

void				working_ox_u(t_pf *data, unsigned long long num)
{
	int				i;

	i = 0;
	if (num == 0)
		g_buffer->str[i++] = '0';
	while (num > 0)
	{
		if (num % data->base >= 10)
			g_buffer->str[i] = check_ox_u(num, data->base);
		else
			g_buffer->str[i] = num % data->base + '0';
		num /= data->base;
		i++;
	}
	g_buffer->str[i] = '\0';
	g_buffer->str_len = i;
}

void				ft_itoa_base_ox_max(t_pf *data, unsigned long long int num)
{
	working_ox_u(data, num);
	ft_strrev();
}
