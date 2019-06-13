/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:50:44 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/21 16:20:56 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

char				check_ox(long long int num, short base)
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

void				working_ox(t_pf *data, long long num)
{
	int				i;

	i = 0;
	if (num == 0)
		g_buffer->str[i++] = '0';
	while (num > 0)
	{
		if (num % data->base >= 10)
			g_buffer->str[i] = check_ox(num, data->base);
		else
			g_buffer->str[i] = num % data->base + '0';
		num /= data->base;
		i++;
	}
	g_buffer->str[i] = '\0';
	g_buffer->str_len = i;
}

void				ft_itoa_base_ox(t_pf *data, long long int num)
{
	if (data->type == 'o')
	{
		if (num < 0 && CHECK_BIT(data->modificators, 3))
			num += 256;
		else if (num < 0 && CHECK_BIT(data->modificators, 4))
			num += MAX_UNSIGNED_SHORT_INT + 1;
		else if (num < 0)
			num += MAX_LONG_INT;
	}
	else
	{
		if (num < 0)
		{
			if (CHECK_BIT(data->modificators, 3))
				num = MAX_UNSIGNED_CHAR;
			else if (CHECK_BIT(data->modificators, 4))
				num = MAX_UNSIGNED_SHORT_INT;
			else
				num += MAX_LONG_INT;
		}
	}
	working_ox(data, num);
	ft_strrev();
}
