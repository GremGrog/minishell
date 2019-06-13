/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 21:16:19 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/06/13 21:16:20 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	copy_matrix(char **env)
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
