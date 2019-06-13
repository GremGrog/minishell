/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:36:27 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/24 21:18:32 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

int			fill_str_char(t_pf *data, int i)
{
	while (data->indents > 1)
	{
		g_buffer->str[i] = data->indents_symb;
		i++;
		data->indents--;
	}
	return (i);
}

void		set_indents_char(t_pf *data, char sym)
{
	int		i;

	i = 0;
	if (CHECK_BIT(data->flags, 5))
	{
		if (sym != 0)
			g_buffer->str[i++] = sym;
		i = fill_str_char(data, i);
	}
	else
	{
		i = fill_str_char(data, i);
		if (sym != 0)
			g_buffer->str[i++] = sym;
	}
	g_buffer->str[i] = '\0';
	g_buffer->str_len = i;
}

void		convert_char_to_str(t_pf *data, char sym)
{
	if (data->indents != 0)
		set_indents_char(data, sym);
	else
	{
		g_buffer->str[0] = sym;
		g_buffer->str[1] = '\0';
		g_buffer->str_len = 1;
	}
}

void		char_process(t_pf *data, va_list args)
{
	char	sym;

	if (data->type == '%')
		sym = '%';
	else
		sym = va_arg(args, int);
	if (sym != 0)
		convert_char_to_str(data, sym);
	if (sym == 0)
	{
		data->type = '0';
		if (data->indents != 0)
			set_indents_char(data, sym);
	}
	ft_put_color(data);
}
