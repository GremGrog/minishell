/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 13:45:17 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/07 13:45:19 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	del_var(char *var)
{
	int	i;

	i = search_var(var);
	if (i == -1)
		return ;
	free(g_env->envp[i]);
	g_env->envp[i] = NULL;
	g_env->used_size--;
}

void	unsetenv_builtin(char **argv)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 1;
	len = get_argc(argv);
	if (len == 1)
		ft_printf("unsetenv: Too few arguments.\n");
	while (argv[j])
		del_var(argv[j++]);
}
