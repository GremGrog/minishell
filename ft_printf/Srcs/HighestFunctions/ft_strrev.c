/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:01:21 by qmebble           #+#    #+#             */
/*   Updated: 2019/05/17 18:01:21 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void	ft_strrev(void)
{
	int		i;
	int		j;
	int		len;

	len = g_buffer->str_len;
	i = 0;
	j = len - 1;
	while (i < len)
		g_buffer->final[i++] = g_buffer->str[j--];
	while (i < g_buffer->buff_size)
		g_buffer->final[i++] = '\0';
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, g_buffer->buff_size);
}
