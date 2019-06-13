/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_indents_pointer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:01:32 by qmebble           #+#    #+#             */
/*   Updated: 2019/05/17 20:08:34 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void	if_zero_pointer(int amount_indents)
{
	int	i;

	g_buffer->final[0] = '0';
	g_buffer->final[1] = 'x';
	i = 1;
	while (++i < amount_indents + 2)
		g_buffer->final[i] = '0';
	while (i - amount_indents < g_buffer->str_len)
	{
		g_buffer->final[i] = g_buffer->str[i - amount_indents];
		i++;
	}
	g_buffer->str_len = i;
	ft_strcpy(g_buffer->str, g_buffer->final);
}

void	if_not_minus_pointer(t_pf *data)
{
	int				i;
	int				amount_indents;

	amount_indents = g_buffer->str_len - data->indents;
	if (amount_indents >= 0)
		return ;
	amount_indents *= -1;
	check_and_add(amount_indents);
	if (CHECK_BIT(data->flags, 1))
	{
		if_zero_pointer(amount_indents);
		return ;
	}
	i = -1;
	while (++i < amount_indents)
		g_buffer->final[i] = data->indents_symb;
	while (i - amount_indents < g_buffer->str_len)
	{
		g_buffer->final[i] = g_buffer->str[i - amount_indents];
		i++;
	}
	g_buffer->str_len = i;
	ft_strcpy(g_buffer->str, g_buffer->final);
}

void	if_minus_pointer(t_pf *data)
{
	int		i;
	int		str_len;
	int		amount_indents;

	amount_indents = g_buffer->str_len - data->indents;
	if (amount_indents >= 0)
		return ;
	amount_indents *= -1;
	check_and_add(amount_indents);
	i = -1;
	while (g_buffer->str[++i] && g_buffer->str[i] != '\0')
		g_buffer->final[i] = g_buffer->str[i];
	str_len = 0;
	while (str_len < amount_indents)
	{
		g_buffer->final[i] = data->indents_symb;
		i++;
		str_len++;
	}
	g_buffer->str_len = i;
	ft_strcpy(g_buffer->str, g_buffer->final);
}

void	ft_put_indents_pointer(t_pf *data)
{
	if (data->indents)
	{
		if (CHECK_BIT(data->flags, 5))
			if_minus_pointer(data);
		else
			if_not_minus_pointer(data);
	}
}
