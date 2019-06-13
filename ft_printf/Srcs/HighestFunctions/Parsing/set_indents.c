/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_indents.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:54:29 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/17 17:54:29 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../MainHeader/ft_printf.h"

int	set_indents(t_pf *data, const char *format, int i)
{
	while (char_bin_search(NUMBERS, format[i]) != -1)
	{
		data->indents = data->indents * 10 + format[i] - '0';
		i++;
	}
	if (data->indents * 10 / 10 != data->indents)
		data->indents = 0;
	return (i);
}
