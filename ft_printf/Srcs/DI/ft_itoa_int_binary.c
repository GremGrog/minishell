/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_int_binary.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:00:33 by qmebble           #+#    #+#             */
/*   Updated: 2019/05/17 18:00:34 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void	working_binary(long long int num)
{
	int	i;

	i = 0;
	while (num > 0)
	{
		g_buffer->str[i++] = num % 2 + '0';
		num /= 2;
	}
	g_buffer->str_len = i;
	ft_strrev();
}

void	ft_itoa_int_binary(t_pf *data, long long int num)
{
	if (num < 0)
	{
		if (CHECK_BIT(data->modificators, 4))
			num += MAX_SHORT_INT;
		else if (CHECK_BIT(data->modificators, 3))
			num += MAX_CHAR;
		else if (CHECK_BIT(data->modificators, 1))
		{
			num += MAX_LL_INT;
			check_and_add(g_buffer->buff_size + 1);
		}
		else
			num += MAX_LONG_INT;
	}
	if (CHECK_BIT(data->modificators, 1))
		check_and_add(g_buffer->buff_size + 1);
	working_binary(num);
}
