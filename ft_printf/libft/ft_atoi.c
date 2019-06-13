/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:10:44 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/28 18:49:11 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			sign;
	long int	res;
	int			i;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
		str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-' && str[i + 1] >= 48 && str[i + 1] <= 57)
	{
		sign = -1;
		i++;
	}
	if (str[i] == '+' && str[i + 1] >= 48 && str[i + 1] <= 57)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
		res = res * 10 + str[i++] - '0';
	if ((res != (res * 10) / 10) && (sign > 0))
		return (-1);
	if ((res != (res * 10) / 10) && (sign < 0))
		return (0);
	return (sign * res);
}
