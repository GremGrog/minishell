/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indents_flo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:40:07 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/17 17:40:07 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void	if_not_zero_flo(int len)
{
	int		i;
	int		j;

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
	ft_bzero(g_buffer->final, g_buffer->buff_size + 1);
}

void	if_zero_flo(int len)
{
	int					i;
	int					j;
	unsigned short int	flag;

	flag = 0;
	if (g_buffer->str[0] == '-' || g_buffer->str[0] == '+'
		|| g_buffer->str[0] == ' ')
	{
		g_buffer->final[0] = g_buffer->str[0];
		flag = 1;
	}
	i = 0;
	while (i < len)
	{
		g_buffer->final[i + flag] = '0';
		i++;
	}
	j = 0 + flag;
	while (g_buffer->str[j] != '\0' && g_buffer->str[j])
		g_buffer->final[i++ + flag] = g_buffer->str[j++];
	g_buffer->str_len += len;
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, g_buffer->buff_size + 1);
}

void	if_not_minus_flo(t_pf *data)
{
	int					len;

	len = g_buffer->str_len - data->indents;
	if (len >= 0)
		return ;
	len *= -1;
	check_and_add(len);
	if (!CHECK_BIT(data->flags, 1))
		data->indents_symb = ' ';
	if (data->indents_symb == '0')
		if_zero_flo(len);
	else
		if_not_zero_flo(len);
}

void	if_minus_flo(t_pf *data)
{
	int		i;
	int		j;
	int		len;

	len = g_buffer->str_len - data->indents;
	if (len >= 0)
		return ;
	i = -1;
	check_and_add(len * (-1));
	while (g_buffer->str[++i] != '\0' && g_buffer->str[i])
		g_buffer->final[i] = g_buffer->str[i];
	j = 0;
	while (j < (-len))
	{
		g_buffer->final[i] = data->indents_symb;
		i++;
		j++;
	}
	g_buffer->str_len = i;
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, g_buffer->buff_size + 1);
}

void	set_indents_flo(t_pf *data)
{
	if (!data->indents)
		return ;
	if (CHECK_BIT(data->flags, 5))
		if_minus_flo(data);
	else
		if_not_minus_flo(data);
}
