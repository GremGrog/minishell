/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:01:14 by qmebble           #+#    #+#             */
/*   Updated: 2019/05/17 18:01:14 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void	put(char *color)
{
	int	i;
	int	j;

	i = 0;
	while (color[i] != '\0' && color[i])
	{
		g_buffer->final[i] = color[i];
		i++;
	}
	j = 0;
	while (g_buffer->str[j] != '\0')
		g_buffer->final[i++] = g_buffer->str[j++];
	j = 0;
	while (NORMAL[j] != '\0' && NORMAL[j])
		g_buffer->final[i++] = NORMAL[j++];
	g_buffer->str_len = i;
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, i);
}

void	ft_put_color(t_pf *data)
{
	if (!CHECK_BIT(data->flags, 7))
		return ;
	check_and_add(g_buffer->str_len + 14);
	if (CHECK_BIT(data->colors, 0))
		put(GREY);
	else if (CHECK_BIT(data->colors, 1))
		put(CYAN);
	else if (CHECK_BIT(data->colors, 2))
		put(PURPLE);
	else if (CHECK_BIT(data->colors, 3))
		put(BLUE);
	else if (CHECK_BIT(data->colors, 4))
		put(YELLOW);
	else if (CHECK_BIT(data->colors, 5))
		put(GREEN);
	else if (CHECK_BIT(data->colors, 6))
		put(RED);
	else if (CHECK_BIT(data->colors, 7))
		put(BLACK);
}
