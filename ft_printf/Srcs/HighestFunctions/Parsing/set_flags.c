/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:54:25 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/17 17:54:25 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../MainHeader/ft_printf.h"

int	set_flags(t_pf *data, const char *format, int i)
{
	while (char_bin_search(FLAGS, format[i]) > -1)
	{
		if (format[i] == 'b')
			PUT_BIT(data->flags, 6);
		if (format[i] == '-')
			PUT_BIT(data->flags, 5);
		if (format[i] == '+')
			PUT_BIT(data->flags, 4);
		if (format[i] == ' ' && (!(CHECK_BIT(data->flags, 3))))
			PUT_BIT(data->flags, 3);
		else if (format[i] == ' ' && CHECK_BIT(data->flags, 3))
		{
			i++;
			continue;
		}
		if (format[i] == '#')
			PUT_BIT(data->flags, 2);
		if (format[i] == '0')
			PUT_BIT(data->flags, 1);
		i++;
	}
	return (i);
}
