/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indents_ox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:50:36 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/17 17:55:26 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void		fill_minus(t_pf *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g_buffer->str[j] != '\0')
		g_buffer->final[i++] = g_buffer->str[j++];
	while (data->indents > 0)
	{
		g_buffer->final[i] = data->indents_symb;
		i++;
		data->indents--;
	}
	g_buffer->final[i] = '\0';
	g_buffer->str_len = i;
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, g_buffer->buff_size + 1);
}

void		fill_plus(t_pf *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (data->indents > 0)
	{
		g_buffer->final[i] = data->indents_symb;
		i++;
		data->indents--;
	}
	while (g_buffer->str[j] != '\0')
		g_buffer->final[i++] = g_buffer->str[j++];
	g_buffer->final[i] = '\0';
	g_buffer->str_len = i;
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, g_buffer->buff_size + 1);
}

void		fill_indents_grid_o(t_pf *data)
{
	int	i;
	int	j;

	g_buffer->final[0] = '0';
	i = 1;
	j = 1;
	while (data->indents > 0)
	{
		g_buffer->final[i++] = data->indents_symb;
		data->indents--;
	}
	while (g_buffer->str[j] != '\0')
		g_buffer->final[i++] = g_buffer->str[j++];
	g_buffer->final[i] = '\0';
	g_buffer->str_len = i;
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, g_buffer->buff_size + 1);
}

void		fill_indents_grid_x(t_pf *data)
{
	int	i;
	int	j;

	if (data->type == 'o')
	{
		fill_indents_grid_o(data);
		return ;
	}
	if (g_buffer->str[0] != '\0')
	{
		g_buffer->final[0] = '0';
		g_buffer->final[1] = 'x';
		i = 2;
		j = 2;
	}
	while (data->indents > 0)
	{
		g_buffer->final[i++] = data->indents_symb;
		data->indents--;
	}
	while (g_buffer->str[j] != '\0')
		g_buffer->final[i++] = g_buffer->str[j++];
	g_buffer->str_len = i;
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, g_buffer->buff_size + 1);
}

void		fill_indents_ox(t_pf *data)
{
	int		len;

	len = data->indents - g_buffer->str_len;
	check_and_add(len);
	if (data->indents < len)
		return ;
	data->indents -= g_buffer->str_len;
	if (data->indents_symb == '0' && CHECK_BIT(data->flags, 2))
		(fill_indents_grid_x(data));
	if (CHECK_BIT(data->flags, 5) && data->indents != 0)
		fill_minus(data);
	if (!(CHECK_BIT(data->flags, 5)) && data->indents != 0)
		fill_plus(data);
}
