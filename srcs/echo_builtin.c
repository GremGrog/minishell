/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:38:59 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/07 16:39:13 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	echo_builtin(char **argv)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	if (ft_strcmp(argv[1], "-n") == 0)
	{
		n = 1;
		i++;
	}
	while (argv[i])
		ft_printf("%s", argv[i++]);
	if (n == 0)
		ft_printf("\n");
}
