/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 21:26:39 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/06/13 21:26:40 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_env(void)
{
	int	i;

	i = 0;
	g_env = (t_env*)malloc(sizeof(t_env));
	g_env->mem_size = 100;
	g_env->envp = (char**)malloc(sizeof(char*) * g_env->mem_size);
	g_env->used_size = 0;
	while (i < g_env->mem_size)
		g_env->envp[i++] = NULL;
}

void	delete_env(void)
{
	int	i;

	i = 0;
	while (g_env->envp[i] != NULL)
		free(g_env->envp[i++]);
	g_env->mem_size = 0;
	g_env->used_size = 0;
	free(g_env->envp);
	free(g_env);
}

void	copy_env(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		g_env->envp[i] = ft_strdup(env[i]);
		i++;
		g_env->used_size++;
	}
	g_env->envp[i] = NULL;
}
