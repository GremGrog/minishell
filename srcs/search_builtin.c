/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:34:05 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/08 19:34:07 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		check_builtin(char *full_path)
{
	if (access(full_path, F_OK) == 0)
	{
		if (access(full_path, X_OK) == -1)
		{
			ft_printf("error: no rights to execute");
			free(full_path);
			return (0);
		}
		return (1);
	}
	return (0);
}

char	*get_builtin(char *path, char *co_name)
{
	char	*full_path;
	char	*tmp;
	char	*buf;

	full_path = (char*)malloc(sizeof(char) * (ft_strlen(path) +
				ft_strlen(co_name) + 3));
	ft_strcpy(full_path, path);
	tmp = ft_strjoin(full_path, "/");
	free(full_path);
	buf = ft_strjoin(tmp, co_name);
	full_path = (char*)malloc(sizeof(char) * (ft_strlen(path) +
				ft_strlen(co_name) + 3));
	full_path = ft_strcpy(full_path, buf);
	free(tmp);
	free(buf);
	if (check_builtin(full_path) == 1)
		return (full_path);
	else
	{
		free(full_path);
		return (NULL);
	}
}

char	*search_builtin(char *co_name)
{
	int		i;
	char	**path;
	int		j;
	char	*full_filename;

	if (!co_name)
		return (NULL);
	full_filename = NULL;
	i = 0;
	j = 0;
	while (ft_strncmp(g_env->envp[i], "PATH", 4) != 0)
		i++;
	path = ft_strsplit(g_env->envp[i], ':');
	// while (*path[j] != '=')
	// 	path[j]++;
	// path[j]++;
	while (path[j] != NULL)
	{
		full_filename = get_builtin(path[j], co_name);
		if (full_filename != NULL)
			break ;
		j++;
	}
	del_matrix(path);
	free(path);
	return (full_filename);
}
