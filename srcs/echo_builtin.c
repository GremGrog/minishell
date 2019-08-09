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
	int	argc;

	n = 0;
	argc = get_argc(argv);
	i = (argc > 1) ? 1 : 0;
	if (argc > 1)
	{
		while (argv[i])
			ft_printf("%s", argv[i++]);
	}
	ft_printf("\n");
}
