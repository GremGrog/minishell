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
	int	var_len;

	i = 0;
	var_len = ft_strlen(var);
	while (g_env->envp[i])
	{
		if (strncmp(g_env->envp[i], var, var_len) == 0)
		{
			free(g_env->envp[i]);
			g_env->envp[i] = NULL;
			g_env->used_size--;
			break ;
		}
		i++;
	}
}

void	unsetenv_builtin(char **argv)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 1;
	len = 0;
	while (argv[len])
		len++;
	if (len == 1)
		ft_printf("unsetenv: Too few arguments.\n");
	while (argv[j])
		del_var(argv[j++]);
	del_matrix(argv);
	free(argv);
}
