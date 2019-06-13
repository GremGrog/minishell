/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:00:36 by qmebble           #+#    #+#             */
/*   Updated: 2019/05/17 18:00:37 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void	extra_working_integer(__int128_t temp, unsigned short int flag)
{
	int	i;

	i = 0;
	while (temp > 0)
	{
		g_buffer->str[i++] = temp % 10 + '0';
		temp /= 10;
	}
	if (flag)
	{
		g_buffer->str[i] = '-';
		i++;
	}
	g_buffer->str_len = i;
}

void	working_integer(long long int num)
{
	int					i;
	unsigned short int	flag;
	__int128_t			temp;

	temp = num;
	i = 0;
	flag = 0;
	if (temp < 0)
	{
		temp *= -1;
		flag = 1;
	}
	if (temp == 0)
	{
		g_buffer->str[0] = '0';
		g_buffer->str[1] = '\0';
		g_buffer->str_len = 1;
		return ;
	}
	extra_working_integer(temp, flag);
}

void	ft_itoa_integer(long long int num)
{
	int		len;

	len = num_len(num);
	working_integer(num);
	ft_strrev();
}
