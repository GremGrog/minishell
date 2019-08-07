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
	{
		if (access(full_path, X_OK) == -1)
		{
			ft_printf("error: no rights to execute");
			free(full_path);
			return (NULL);
		}
		return (full_path);
	}
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
	full_filename = NULL;
	i = 0;
	j = 0;
	while (ft_strncmp(g_env->envp[i], "PATH", 4) != 0)
		i++;
	while (g_env->envp[i][j++] != '=')
		;
	j++;
	path = ft_strsplit(g_env->envp[i], ':');
	j = 0;
	while (path[j] != NULL)
	{
		full_filename = search_builtin(path[j], co_name);
		if (full_filename != NULL)
			break ;
		j++;
	}
	del_matrix(path);
	free(path);
	return (full_filename);
}

void	exec_custom_builtins(void (*f)(char**), char **argv)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	pid = fork();
	if (pid == 0)
		(*f)(argv);
	else
		wpid = wait(&status);
}

void	exec_system_builtins(t_co *co_exec)
{
	char	*full_filename;
	pid_t	pid;
	pid_t	wpid;
	int		status;

	full_filename = get_builtin(co_exec->co_name);
	if (full_filename == NULL)
		ft_printf("minishell: command not found: %s\n", co_exec->co_name);
	else
	{
		pid = fork();
		if (pid == 0)
			execve(full_filename, co_exec->co_args,	g_env->envp);
		else
			wpid = wait(&status);
		free(full_filename);
	}
}

void	exec_command(t_args *argv, t_co *co_exec)
{
	int		i;
	t_co	*tmp;

	i = 0;
	tmp = co_exec->next;
	while (argv->argv[i])
	{
		if (ft_strcmp(tmp->co_name, "cd") == 0)
			exec_custom_builtins(cd_builtin, tmp->co_args);
		else if (ft_strcmp(tmp->co_name, "env") == 0)
			exec_custom_builtins(env_builtin, tmp->co_args);
		else if (ft_strcmp(tmp->co_name, "setenv") == 0)
			exec_custom_builtins(setenv_builtin, tmp->co_args);
		else if (ft_strcmp(tmp->co_name, "unsetenv") == 0)
			exec_custom_builtins(unsetenv_builtin, tmp->co_args);
		else if (ft_strcmp(tmp->co_name, "echo") == 0)
			exec_custom_builtins(echo_builtin, tmp->co_args);
		else if (ft_strcmp(tmp->co_name, "exit") == 0)
			exit_builtin(argv, co_exec);
		else
			exec_system_builtins(tmp);
		i++;
		tmp = tmp->next;
	}
}
