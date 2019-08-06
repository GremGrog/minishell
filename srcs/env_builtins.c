/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:16:36 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/06 15:16:38 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_env(void)
{
	int	i;

	i = 0;
	while (g_env->envp[i])
		ft_printf("%s\n", g_env->envp[i++]);
}

void	env_builtin(char *argv)
{
	int		i;
	char	**args;

	i = 0;
	args = ft_strsplit(argv, ' ');
	print_env();
	del_matrix(args);
	free(args);
}
