/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:54:05 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/17 17:54:05 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../MainHeader/ft_printf.h"

void	check_for_flags(t_pf *data)
{
	if (CHECK_BIT(data->flags, 1))
	{
		if (!(CHECK_BIT(data->flags, 5)))
			data->indents_symb = '0';
		else
		{
			data->indents_symb = ' ';
			DEL_BIT(data->flags, 1);
		}
	}
	else
		data->indents_symb = ' ';
	if (CHECK_BIT(data->flags, 3))
		if (CHECK_BIT(data->flags, 4))
			DEL_BIT(data->flags, 3);
}

int		set_colors(t_pf *data, const char *format, int i)
{
	if (format[i] == 'b')
	{
		if (format[i + 2] == 'a')
			PUT_BIT(data->colors, 7);
		else if (format[i + 2] == 'u')
			PUT_BIT(data->colors, 3);
	}
	else if (format[i] == 'r')
		PUT_BIT(data->colors, 6);
	else if (format[i] == 'g')
	{
		if (format[i + 3] == 'y')
			PUT_BIT(data->colors, 0);
		else if (format[i + 3] == 'e')
			PUT_BIT(data->colors, 5);
	}
	else if (format[i] == 'y')
		PUT_BIT(data->colors, 4);
	else if (format[i] == 'p')
		PUT_BIT(data->colors, 2);
	else if (format[i] == 'c')
		PUT_BIT(data->colors, 1);
	while (format[i] != '}' && format[i] != '\0' && format[i])
		i++;
	return (i + 1);
}

int		wheel(t_pf *data, const char *format, int i)
{
	while (format[i] != '\0')
		if (char_bin_search(FLAGS, format[i]) != -1 && format[i])
			i = set_flags(data, format, i);
		else if (char_bin_search(NUMBERS, format[i]) != -1 && format[i] != '\0')
			i = set_indents(data, format, i);
		else if (format[i] == '.')
			i = set_precision(data, format, i);
		else if (format[i] == 'h' || format[i] == 'l' ||
			format[i] == 'L' || format[i] == 'z')
			i = set_modificators(data, format, i);
		else if (format[i] == '{')
		{
			PUT_BIT(data->flags, 7);
			i = set_colors(data, format, ++i);
		}
		else if (char_bin_search(TYPES, format[i]) != -1 && format[i] != '\0')
		{
			data->type = format[i++];
			break ;
		}
		else if (char_bin_search(TYPES, format[i]) == -1 && format[i] != '\0')
			break ;
		else
			i++;
	return (i);
}

int		ft_parsing(t_pf *data, va_list args, const char *format, int i)
{
	ft_set_to_null(data);
	make_new_buffer();
	if (format[i] != '%')
		i = string_before(data, format, i);
	if (format[i] == '%')
		i += 1;
	i = wheel(data, format, i);
	if (format[i] != '%' && format[i])
		i = ft_str_after(data, format, i);
	check_for_flags(data);
	assemble_string(put_data(data, args));
	return (i);
}
