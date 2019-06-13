/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_ipart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 14:14:31 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/25 14:14:31 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void		check_ipart(int i, int j, t_pf *data)
{
	if (g_buffer->str[i + 1] >= '5' && g_buffer->str[i + 2] != '\0')
	{
		if (g_buffer->final[j - 1] == '9')
			return (round_up_nine(data));
		g_buffer->final[j - 1]++;
	}
	if (g_buffer->str[i + 1] >= '5' && g_buffer->str[i + 2] == '\0')
	{
		if ((g_buffer->final[j - 1] - '0') % 2 == 1)
			g_buffer->final[j - 1]++;
	}
	g_buffer->str_len = j;
}

void		round_ipart(t_pf *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (g_buffer->str[i] != '.')
		g_buffer->final[j++] = g_buffer->str[i++];
	if (CHECK_BIT(data->flags, 2))
	{
		if (g_buffer->str[i + 1] >= '5')
			g_buffer->final[j - 1]++;
		g_buffer->final[j] = '.';
		g_buffer->str_len = j + 1;
	}
	else
		check_ipart(i, j, data);
}
