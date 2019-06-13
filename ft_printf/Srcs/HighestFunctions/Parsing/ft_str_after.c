/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_after.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:54:12 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/17 17:54:12 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../MainHeader/ft_printf.h"

int			ft_str_after(t_pf *data, const char *format, int i)
{
	int		temp;
	int		j;
	char	*end;

	j = 0;
	temp = i;
	while (format[i] != '%' && format[i] != '\0')
		i++;
	end = (char *)malloc(sizeof(char) * (i - temp + 1));
	while (format[temp] != '%' && format[temp] != '\0')
	{
		end[j] = format[temp];
		j++;
		temp++;
	}
	end[j] = '\0';
	data->str_after = end;
	g_buffer->after_len = j;
	return (i);
}
