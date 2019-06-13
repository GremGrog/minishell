/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:01:43 by qmebble           #+#    #+#             */
/*   Updated: 2019/05/17 18:01:43 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void	ft_itoa_u_binary(t_pf *data, unsigned long long int num)
{
	int	i;

	if (CHECK_BIT(data->modificators, 1))
		check_and_add(g_buffer->buff_size + 1);
	i = 0;
	while (num > 0)
	{
		g_buffer->str[i++] = num % 2 + '0';
		num /= 2;
	}
	g_buffer->str_len = i;
	ft_strrev();
}
