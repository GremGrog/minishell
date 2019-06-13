/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_limits_unsigned_integer.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:01:40 by qmebble           #+#    #+#             */
/*   Updated: 2019/05/17 18:01:41 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

unsigned long long int	check_limits_unsigned(t_pf *data, va_list args)
{
	if ((CHECK_BIT(data->modificators, 4) == 0 &&
		CHECK_BIT(data->modificators, 3) == 0) &&
		(CHECK_BIT(data->modificators, 2) != 0 ||
		CHECK_BIT(data->modificators, 1) != 0))
	{
		if (CHECK_BIT(data->modificators, 2))
			return (va_arg(args, unsigned long int));
		return (va_arg(args, unsigned long long int));
	}
	if (CHECK_BIT(data->modificators, 4))
		return ((unsigned short)va_arg(args, unsigned int));
	if (CHECK_BIT(data->modificators, 3))
		return ((unsigned char)va_arg(args, unsigned int));
	if (CHECK_BIT(data->modificators, 5))
		return (va_arg(args, unsigned long long int));
	return ((unsigned long long)va_arg(args, unsigned int));
}
