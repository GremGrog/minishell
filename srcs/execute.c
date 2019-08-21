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

int		is_it_dir(char *full_path)
{
	struct stat buff;

	stat(full_path, &buff);
	if (S_ISDIR(buff.st_mode))
		return (-1);
	return (0);
}

int		error_managment(char *full_filename, char *co_name)
{
	if (full_filename == NULL)
	{
		ft_printf("minishell: command not found: %s\n", co_name);
		return (-1);
	}
	else if (access(full_filename, 0) != 0)
	{
		ft_printf("minishell: command not found: %s\n", full_filename);
		free(full_filename);
		return (-1);
	}
	else if (access(full_filename, 1) != 0)
	{
		ft_printf("error: no rights to execute: %s\n", full_filename);
		free(full_filename);
		return (-1);
	}
	return (0);
}

void	exec_system_builtins(t_co *co_exec)
{
	char	*full_filename;
	pid_t	pid;
	int		status;

	if (ft_strcmp(co_exec->co_name, "\0") == 0)
		return ;
	full_filename = search_builtin(co_exec->co_name);
	if (error_managment(full_filename, co_exec->co_name) == -1)
		return ;
	else
	{
		pid = fork();
		if (pid == 0)
			execve(full_filename, co_exec->co_args, g_env->envp);
		else
			wait(&status);
		free(full_filename);
	}
}

void	exec_command(t_args *argv, t_co *co_exec)
{
	int		i;
	t_co	*buf;

	i = 0;
	while (argv->argv[i])
	{
		if (ft_strcmp(co_exec->co_name, "cd") == 0)
			cd_builtin(co_exec->co_args);
		else if (ft_strcmp(co_exec->co_name, "env") == 0)
			env_builtin();
		else if (ft_strcmp(co_exec->co_name, "setenv") == 0)
			setenv_builtin(co_exec->co_args);
		else if (ft_strcmp(co_exec->co_name, "unsetenv") == 0)
			unsetenv_builtin(co_exec->co_args);
		else if (ft_strcmp(co_exec->co_name, "echo") == 0)
			echo_builtin(co_exec->co_args);
		else if (ft_strcmp(co_exec->co_name, "exit") == 0)
			exit_builtin(argv, co_exec);
		else
			exec_system_builtins(co_exec);
		i++;
		buf = co_exec;
		co_exec = co_exec->next;
		del_co(buf);
	}
}
