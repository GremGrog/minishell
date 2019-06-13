/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipart_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:40:24 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/17 17:40:24 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void	ipart_to_str(void)
{
	int i;
	int j;

	i = 1;
	j = 6;
	ft_itoa_integer(g_ipart);
	i = num_len(g_ipart);
	g_buffer->str[i++] = '.';
	while (j > 0)
	{
		g_buffer->str[i++] = '0';
		j--;
	}
	g_buffer->str_len = i;
	if (1 / g_fpart == -1.0 / 0.0)
	{
		i = 0;
		j = 0;
		g_buffer->final[j++] = '-';
		while (g_buffer->str[i] != '\0')
			g_buffer->final[j++] = g_buffer->str[i++];
		g_buffer->str_len = j;
		ft_strcpy(g_buffer->str, g_buffer->final);
		ft_bzero(g_buffer->final, g_buffer->str_len);
	}
}
