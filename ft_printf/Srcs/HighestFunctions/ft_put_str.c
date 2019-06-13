/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:01:16 by qmebble           #+#    #+#             */
/*   Updated: 2019/05/17 18:01:16 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

int		ft_put_before(char *str, char *final)
{
	int	i;

	i = 0;
	while (i < g_buffer->before_len)
	{
		final[i] = str[i];
		i++;
	}
	free(str);
	return (i);
}

int		ft_put_after(char *str, char *final, int x, int y)
{
	int	i;

	i = 0;
	while (i < g_buffer->after_len)
	{
		final[x + y + i] = str[i];
		i++;
	}
	free(str);
	return (i);
}

void	ft_put_str(t_pf *data)
{
	char	*final;
	int		x;
	int		y;
	int		z;

	final = (char *)malloc(sizeof(char) * (g_buffer->before_len +
			g_buffer->str_len + g_buffer->after_len + 1));
	x = 0;
	if (data->str_before)
		x = ft_put_before(data->str_before, final);
	y = 0;
	if (g_buffer->str)
		while (y < g_buffer->str_len)
		{
			final[x + y] = g_buffer->str[y];
			y++;
		}
	z = 0;
	if (data->str_after)
		z = ft_put_after(data->str_after, final, x, y);
	final[x + y + z] = '\0';
	write(1, final, x + y + z);
	free(final);
}
