/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:50:27 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/17 17:50:27 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void		grid_x(t_pf *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (g_buffer->str[0] == '0')
	{
		if (!data->precision && !CHECK_BIT(data->flags, 2))
			g_buffer->str[0] = '\0';
		DEL_BIT(data->flags, 2);
		return ;
	}
	g_buffer->final[i++] = '0';
	if (data->type == 'x')
		g_buffer->final[i++] = 'x';
	else
		g_buffer->final[i++] = 'X';
	while (g_buffer->str[j] != '\0')
		g_buffer->final[i++] = g_buffer->str[j++];
	g_buffer->final[i] = '\0';
	g_buffer->str_len = i;
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, g_buffer->buff_size);
}
