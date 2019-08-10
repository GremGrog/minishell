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

int		search_var(char *ar)
{
	int	i;

	i = 0;
	while (g_env->envp[i])
	{
		if (strncmp(g_env->envp[i], ar, ft_strlen(ar)) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*trim_var(char *var)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	j = 0;
	if ((i = search_var(var)) == -1)
		return (NULL);
	while (g_env->envp[i][j] && g_env->envp[i][j++] != '=')
		;
	len = ft_strlen(g_env->envp[i]) - j;
	str = ft_strsub(g_env->envp[i], j, len);
	return (str);
}

char	*search_builtin(char *co_name)
{
	int		i;
	char	**path_var;
	char	*tmp;
	char	*full_filename;

	if (!co_name)
		return (NULL);
	if (access(co_name, F_OK) == 0)
		return (ft_strdup(co_name));
	full_filename = NULL;
	i = 0;
	if ((tmp = trim_var("PATH")) == NULL)
		return (NULL);
	path_var = ft_strsplit(tmp, ':');
	while (path_var[i] != NULL)
	{
		full_filename = get_builtin(path_var[i], co_name);
		if (full_filename != NULL)
			break ;
		i++;
	}
	del_matrix(path_var);
	free(path_var);
	free(tmp);
	return (full_filename);
}
