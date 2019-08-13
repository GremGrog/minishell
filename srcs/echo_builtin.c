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

char	*del_quotes(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = (char*)malloc(sizeof(char) * (ft_strlen(str)) + 1);
	while (str[i])
	{
		if (str[i] == '"')
			i++;
		if (str[i] == '\0')
			break ;
		tmp[j] = str[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

void	echo_builtin(char **argv)
{
	int		i;
	int		argc;
	char	*tmp;

	argc = get_argc(argv);
	i = (argc > 1) ? 1 : 0;
	if (argc > 1)
	{
		while (argv[i])
		{
			tmp = del_quotes(argv[i]);
			if (tmp)
			{
				ft_printf("%s", tmp);
				ft_printf(" ");
				free(tmp);
			}
			i++;
		}
	}
	ft_printf("\n");
}
