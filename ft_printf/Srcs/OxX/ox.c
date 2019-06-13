/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ox.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:50:52 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/17 21:49:52 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void			convert_data_without_mod(va_list args, t_pf *data)
{
	int			val;

	val = va_arg(args, int);
	if (val < 0)
		ft_itoa_base_ox(data, (long long)val);
	else
		ft_itoa_base_ox(data, (unsigned long long)val);
}

void			convert_to_short_ox(va_list args, t_pf *data)
{
	int			val;

	val = va_arg(args, int);
	if (val < 0)
		ft_itoa_base_ox(data, (short)val);
	else
		ft_itoa_base_ox(data, (unsigned short)val);
}

void			convert_to_char_ox(va_list args, t_pf *data)
{
	int			val;

	val = va_arg(args, int);
	if (val < 0)
		ft_itoa_base_ox(data, (char)val);
	else
		ft_itoa_base_ox(data, (unsigned char)val);
}

void			convert_data_ox(va_list args, t_pf *data)
{
	unsigned long long	value;

	if (CHECK_BIT(data->modificators, 1) || CHECK_BIT(data->modificators, 2)
		|| CHECK_BIT(data->modificators, 5))
	{
		value = (unsigned long long)va_arg(args, long long);
		ft_itoa_base_ox_max(data, (unsigned long long)value);
	}
	else if (CHECK_BIT(data->modificators, 3))
		return (convert_to_char_ox(args, data));
	else if (CHECK_BIT(data->modificators, 4))
		return (convert_to_short_ox(args, data));
	else
		return (convert_data_without_mod(args, data));
}

void			ox_process(t_pf *data, va_list args)
{
	if (data->type == 'o')
	{
		data->base = 8;
		convert_data_ox(args, data);
		if (CHECK_BIT(data->flags, 2))
			grid_o();
	}
	else
	{
		data->base = 16;
		convert_data_ox(args, data);
		if (CHECK_BIT(data->flags, 2))
			grid_x(data);
	}
	if (data->precision)
		data->indents_symb = ' ';
	if (data->precision != 0)
		fill_precision_ox(data);
	if (data->indents != 0)
		fill_indents_ox(data);
	ft_caps(data);
	ft_put_color(data);
}
