/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:10:43 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/06/15 16:10:46 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*search_builtin(char *path, char *co_name)
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
	if (access(full_path, F_OK) == 0)
		return (full_path);
	else
		free(full_path);
	return (NULL);
}

char	*get_builtin(char *co_name)
{
	int		i;
	char	**path;
	int		j;
	char	*full_filename;

	if (!co_name)
		return (NULL);
	if (ft_strcmp(co_name, "cd") == 0)
		return (NULL);
	full_filename = NULL;
	i = 0;
	while (g_env->envp[12][i] != '=')
		i++;
	i++;
	path = ft_strsplit(&g_env->envp[12][i], ':');
	j = 0;
	while (path[j] != NULL)
	{
		full_filename = search_builtin(path[j], co_name);
		if (full_filename != NULL)
			break ;
		j++;
	}
	return (full_filename);
}

void	exec_command(t_args *argv, t_co *co_exec)
{
	char	*full_filename;
	pid_t	pid;
	pid_t	wpid;
	int		status;
	int		i;

	i = 0;
	while (argv->argv[i])
	{
		if (ft_strcmp(co_exec->co_name, "cd") == 0)
		{
			pid = fork();
			if (pid == 0)
				cd_builtin(argv->argv[i]);
			else
				wpid = waitpid(pid, &status, WUNTRACED);
		}
		full_filename = get_builtin(co_exec->co_name);
		if (full_filename)
		{
			pid = fork();
			if (pid == 0)
				execve(full_filename, co_exec->co_args,	g_env->envp);
			else
				wpid = waitpid(pid, &status, WUNTRACED);
		}
		i++;
		co_exec = co_exec->next;
		free(full_filename);
	}
}
