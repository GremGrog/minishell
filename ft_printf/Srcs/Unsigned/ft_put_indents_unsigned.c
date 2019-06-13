/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_indents_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:01:48 by qmebble           #+#    #+#             */
/*   Updated: 2019/05/17 18:03:26 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void	if_not_zero_unsigned(int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len)
		g_buffer->final[i] = ' ';
	j = -1;
	while (g_buffer->str[++j] != '\0' && g_buffer->str[j])
	{
		g_buffer->final[i] = g_buffer->str[j];
		i++;
	}
	g_buffer->str_len = i;
	ft_strcpy(g_buffer->str, g_buffer->final);
}

void	if_zero_unsigned(int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (g_buffer->str[0] == '+' || g_buffer->str[0] == ' ')
		g_buffer->final[i++] = g_buffer->str[j++];
	while (i < len)
		g_buffer->final[i++] = '0';
	while (g_buffer->str[j] != '\0' && g_buffer->str[j])
		g_buffer->final[i++] = g_buffer->str[j++];
	g_buffer->str_len = i;
	ft_strcpy(g_buffer->str, g_buffer->final);
}

void	if_not_minus_unsigned(t_pf *data)
{
	int	len;

	len = g_buffer->str_len - data->indents;
	if (len >= 0)
		return ;
	len *= -1;
	check_and_add(len);
	if (data->precision)
		data->indents_symb = ' ';
	if (data->indents_symb == '0')
		if_zero_unsigned(len);
	else
		if_not_zero_unsigned(len);
}

void	if_minus_unsigned(t_pf *data)
{
	int		i;
	int		j;
	int		len;

	len = g_buffer->str_len - data->indents;
	if (len >= 0)
		return ;
	check_and_add(len * (-1));
	i = -1;
	while (g_buffer->str[++i] != '\0' && g_buffer->str[i])
		g_buffer->final[i] = g_buffer->str[i];
	j = 0;
	while (j++ < (-len))
		g_buffer->final[i++] = data->indents_symb;
	g_buffer->str_len = i;
	ft_strcpy(g_buffer->str, g_buffer->final);
}

void	ft_put_indents_unsigned(t_pf *data)
{
	if (!data->indents)
		return ;
	if (CHECK_BIT(data->flags, 5))
		if_minus_unsigned(data);
	else
		if_not_minus_unsigned(data);
}
