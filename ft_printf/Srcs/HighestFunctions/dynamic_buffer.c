/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:01:08 by qmebble           #+#    #+#             */
/*   Updated: 2019/05/20 16:34:56 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void	make_new_buffer(void)
{
	g_buffer = (t_buffer *)malloc(sizeof(t_buffer));
	g_buffer->buff_size = 50;
	g_buffer->str = (char *)malloc(sizeof(char) * (g_buffer->buff_size));
	g_buffer->final = (char *)malloc(sizeof(char) * (g_buffer->buff_size));
	ft_bzero(g_buffer->str, g_buffer->buff_size);
	ft_bzero(g_buffer->final, g_buffer->buff_size);
	g_buffer->str_len = 0;
	g_buffer->before_len = 0;
	g_buffer->after_len = 0;
	g_buffer->overflow_counter = 1;
}

void	ft_copy_temp(char *temp_str, char *temp_final)
{
	int i;

	i = g_buffer->buff_size / g_buffer->overflow_counter;
	ft_strcpy(temp_str, g_buffer->str);
	ft_strcpy(temp_final, g_buffer->final);
	while (i < g_buffer->buff_size)
	{
		temp_str[i] = '\0';
		temp_final[i] = '\0';
		i++;
	}
}

void	copy_free(char *temp_str, char *temp_final)
{
	ft_bzero(g_buffer->str, g_buffer->buff_size);
	ft_bzero(g_buffer->final, g_buffer->buff_size);
	ft_strcpy(g_buffer->str, temp_str);
	ft_strcpy(g_buffer->final, temp_final);
	free(temp_str);
	free(temp_final);
}

void	check_and_add(int size)
{
	char	*temp_str;
	char	*temp_final;

	if (g_buffer->str_len + size < g_buffer->buff_size)
		return ;
	while (g_buffer->str_len + size > g_buffer->buff_size)
	{
		g_buffer->overflow_counter++;
		g_buffer->buff_size *= g_buffer->overflow_counter;
	}
	temp_str = (char *)malloc(sizeof(char) * g_buffer->buff_size);
	temp_final = (char *)malloc(sizeof(char) * g_buffer->buff_size);
	if (!temp_final || !temp_str)
		return ;
	ft_copy_temp(temp_str, temp_final);
	free(g_buffer->str);
	free(g_buffer->final);
	g_buffer->str = (char *)malloc(sizeof(char) * g_buffer->buff_size);
	g_buffer->final = (char*)malloc(sizeof(char) * g_buffer->buff_size);
	if (!g_buffer->str || !g_buffer->final)
		return ;
	copy_free(temp_str, temp_final);
}

void	free_buffer(void)
{
	if (g_buffer->str != NULL)
		free(g_buffer->str);
	if (g_buffer->final != NULL)
		free(g_buffer->final);
	free(g_buffer);
}
