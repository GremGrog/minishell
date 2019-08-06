/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:50:21 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/06 18:50:23 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	validate_var_name(char **args)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (args[i][j] >= 0 + 48 && args[i][j] <= 9 + 48)
	{
		ft_printf("setenv: Variable name must begin with a letter.\n");
		exit(0);
	}
	while (args[i][j])
	{
		if (!(args[i][j] >= 0 + 48 && args[i][j] <= 9 + 48) &&
			(!(args[i][j] >= 'a' && args[i][j] <= 'z')) &&
			(!(args[i][j] >= 'A' && args[i][j] <= 'Z')))
		{
			ft_printf("setenv: Variable name must contain ");
			ft_printf("alphanumeric characters.\n");
			exit(0);
		}
		j++;
	}
}

void	add_var(char **ar, int len)
{
	char	*var;
	char	*tmp;
	int		i;
	int		var_len;

	// if (g_env->used_size + 1 > g_env->mem_size)
	// 	add_mem();
	i = g_env->used_size++;
	var_len = ft_strlen(ar[1]);
	if (len == 2)
	{
		if (!(g_env->envp[i] = (char*)malloc(sizeof(char) * var_len + 1)))
			return ;
		ft_strcpy(g_env->envp[i], ar[1]);
	}
	if (len == 3)
	{
		if (!(g_env->envp[i] =
		(char*)malloc(sizeof(char) * (var_len + ft_strlen(ar[2])) + 2)))
			return ;
		var = ft_strjoin(ar[1], "=");
		tmp = ft_strjoin(var, ar[2]);
		free(var);
		ft_strcpy(g_env->envp[i], tmp);
		free(tmp);
	}
}

void	setenv_builtin(char *args)
{
	char	**argv;
	int		i;
	int		len;

	i = 0;
	len = 0;
	argv = ft_strsplit(args, ' ');
	while (argv[len])
		len++;
	if (len == 1)
		print_env();
	else if (len >= 2 && len < 4)
	{
		validate_var_name(argv);
		add_var(argv, len);
	}
}
