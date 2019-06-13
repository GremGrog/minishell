/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_grid_pointer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:01:29 by qmebble           #+#    #+#             */
/*   Updated: 2019/05/17 20:06:44 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void	ft_put_grid_pointer(void)
{
	int		i;

	check_and_add(g_buffer->str_len + 2);
	g_buffer->final[0] = '0';
	g_buffer->final[1] = 'x';
	i = 2;
	while (g_buffer->str[i - 2] && g_buffer->str[i - 2] != '\0')
	{
		g_buffer->final[i] = g_buffer->str[i - 2];
		i++;
	}
	g_buffer->str_len = i;
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, i);
}
