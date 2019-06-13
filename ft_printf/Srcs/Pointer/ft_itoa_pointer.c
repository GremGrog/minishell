/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:01:27 by qmebble           #+#    #+#             */
/*   Updated: 2019/05/17 18:01:27 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

int		num_len_pointer(unsigned long long int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	check_pointer(unsigned long long int num)
{
	if (num % 16 == 10)
		return ('a');
	else if (num % 16 == 11)
		return ('b');
	if (num % 16 == 12)
		return ('c');
	else if (num % 16 == 13)
		return ('d');
	if (num % 16 == 14)
		return ('e');
	else
		return ('f');
}

void	working_pointer(unsigned long long int num)
{
	int	i;

	i = 0;
	while (num > 0)
	{
		if (num % 16 >= 10)
			g_buffer->str[i] = check_pointer(num);
		else
			g_buffer->str[i] = num % 16 + '0';
		num /= 16;
		i++;
	}
	g_buffer->str_len = i;
}

void	ft_itoa_pointer(unsigned long long int num)
{
	check_and_add(num_len_pointer(num));
	if (num == 0)
	{
		g_buffer->str[0] = '0';
		g_buffer->str[1] = '\0';
		g_buffer->str_len = 1;
		return ;
	}
	working_pointer(num);
	ft_strrev();
}
