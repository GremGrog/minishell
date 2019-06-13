/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_modificators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:54:34 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/17 17:54:34 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../MainHeader/ft_printf.h"

int	put_haha(t_pf *data, const char *format, int i)
{
	if (format[i + 1] == 'h')
	{
		PUT_BIT(data->modificators, 3);
		i++;
	}
	else
		PUT_BIT(data->modificators, 4);
	return (i);
}

int	put_lala(t_pf *data, const char *format, int i)
{
	if (format[i + 1] == 'l')
	{
		PUT_BIT(data->modificators, 1);
		i++;
	}
	else
		PUT_BIT(data->modificators, 2);
	return (i);
}

int	set_modificators(t_pf *data, const char *format, int i)
{
	while (format[i] == 'h' || format[i] == 'l' ||
	format[i] == 'L' || format[i] == 'z')
	{
		if (format[i] == 'L')
			PUT_BIT(data->modificators, 0);
		if (format[i] == 'l')
			i = put_lala(data, format, i);
		if (format[i] == 'h')
			i = put_haha(data, format, i);
		if (format[i] == 'z')
			PUT_BIT(data->modificators, 5);
		i++;
	}
	return (i);
}
