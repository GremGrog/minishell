/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_limits_integer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:00:19 by qmebble           #+#    #+#             */
/*   Updated: 2019/05/17 18:00:21 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

long long int	check_limits_integer(t_pf *data, va_list args)
{
	if (CHECK_BIT(data->modificators, 5))
		return ((size_t)va_arg(args, long int));
	if ((CHECK_BIT(data->modificators, 4) == 0 &&
		CHECK_BIT(data->modificators, 3) == 0) &&
		(CHECK_BIT(data->modificators, 2) != 0 ||
		CHECK_BIT(data->modificators, 1) != 0))
	{
		if (CHECK_BIT(data->modificators, 2))
			return (va_arg(args, long int));
		return (va_arg(args, long long int));
	}
	if (CHECK_BIT(data->modificators, 4))
		return ((short)va_arg(args, int));
	if (CHECK_BIT(data->modificators, 3))
		return ((char)va_arg(args, int));
	return (va_arg(args, int));
}
