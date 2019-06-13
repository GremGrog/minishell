/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_protection_func.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:17:23 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/20 15:18:54 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void					free_arrays(char **a, char **b)
{
	free(*a);
	free(*b);
}

void					set_arrays_to_null(char *a, char *b, int n)
{
	set_arr_to_null(a, n);
	set_arr_to_null(b, n);
}

void					check_and_free(char **a, char **b, char **c, char **d)
{
	if (!*a)
		return ;
	if (!b)
	{
		free(*a);
		return ;
	}
	if (!*c)
	{
		free(*a);
		free(*b);
		return ;
	}
	if (!*d || *d == NULL)
	{
		free(*a);
		free(*b);
		free(*c);
		return ;
	}
}
