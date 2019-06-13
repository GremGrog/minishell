/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ohter_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:36:02 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/25 15:32:36 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void				set_arr_to_null(char *arr, int size)
{
	int				i;

	i = 0;
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
}

void				other_case_double(char *y, short exp, short sign)
{
	int				n;
	char			*x;
	char			*z;
	char			*pow;
	char			*bow;

	n = exp - 52;
	x = (char*)malloc(sizeof(char) * 4999);
	z = (char*)malloc(sizeof(char) * 4999);
	pow = (char *)malloc(sizeof(char) * 4999);
	bow = (char *)malloc(sizeof(char) * 4999);
	if (!x || !z || !pow || !bow)
		return (check_and_free(&x, &z, &pow, &bow));
	set_arr_to_null(x, 4999);
	set_arrays_to_null(pow, bow, 4999);
	pow = get_two_power(n, pow, bow);
	multiplication_long(y, pow, x);
	free_arrays(&z, &y);
	free(pow);
	ft_copy_float(x, sign);
}

void				infinity(t_pf *data)
{
	if (CHECK_BIT(data->flags, 4))
	{
		ft_strcpy(g_buffer->str, "+inf");
		g_buffer->str_len = 4;
	}
	else
	{
		ft_strcpy(g_buffer->str, "inf");
		g_buffer->str_len = 3;
	}
}

void				validity(t_pf *data)
{
	if (g_flo == 1.0 / 0.0)
		infinity(data);
	else if (g_flo == -1.0 / 0.0)
	{
		ft_strcpy(g_buffer->str, "-inf");
		g_buffer->str_len = 4;
	}
	else if (g_flo != g_flo)
	{
		ft_strcpy(g_buffer->str, "nan");
		DEL_BIT(data->flags, 3);
		g_buffer->str_len = 3;
	}
	data->indents_symb = ' ';
	DEL_BIT(data->flags, 1);
	DEL_BIT(data->flags, 2);
	DEL_BIT(data->flags, 4);
}
