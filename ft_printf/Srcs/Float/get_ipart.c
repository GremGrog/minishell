/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ipart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 14:47:05 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/25 14:25:02 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void	to_dot(int dot, int i)
{
	while (g_buffer->str[i] != '.' && g_buffer->str[i] != '\0')
	{
		i++;
		if (g_buffer->str[i] == '.')
			dot++;
	}
	if (dot == 0)
	{
		g_buffer->str[i++] = '.';
		g_buffer->str_len++;
	}
	g_ipart = i - 1;
}

void	get_ipart(void)
{
	int		i;
	int		j;
	int		dot;

	dot = 0;
	i = 0;
	j = 0;
	if (!(g_buffer->str[i] >= '0' && g_buffer->str[i] <= '9')
	&& g_buffer->str[i] != '-')
	{
		if (g_buffer->str[i] == '.')
			dot++;
		g_buffer->final[j++] = '0';
		while (g_buffer->str[i] != '\0')
			g_buffer->final[j++] = g_buffer->str[i++];
		g_buffer->str_len = j;
		ft_bzero(g_buffer->str, g_buffer->buff_size);
		ft_strcpy(g_buffer->str, g_buffer->final);
		ft_bzero(g_buffer->final, g_buffer->buff_size);
	}
	to_dot(dot, i);
}
