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

int		check_var(int var_index)
{
	if ((var_index) == -1)
		return (-1);
	if (ft_strncmp(g_env->envp[var_index], "HOME", 4) == 0)
	{
		ft_printf("error: prohibited action\n");
		return (-1);
	}
	return (0);
}

void	del_var(char *var)
{
	int		var_index;
	int		i;
	int		j;
	char	**arr;

	var_index = search_var(var);
	if (check_var(var_index) == -1)
		return ;
	i = 0;
	j = 0;
	arr = (char**)malloc(sizeof(char*) * g_env->mem_size);
	while (g_env->envp[i])
	{
		if (i == var_index)
			i++;
		else
			arr[j++] = ft_strdup(g_env->envp[i++]);
	}
	arr[j] = NULL;
	delete_env();
	init_env();
	copy_env(arr);
	del_matrix(arr);
	free(arr);
	g_env->used_size--;
}

void	unsetenv_builtin(char **argv)
{
	int		j;
	int		len;

	j = 0;
	len = get_argc(argv);
	if (len == 1)
	{
		ft_printf("unsetenv: Too few arguments.\n");
		return ;
	}
	while (argv[j])
		del_var(argv[j++]);
}
