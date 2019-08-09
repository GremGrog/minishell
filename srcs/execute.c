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

void	exec_system_builtins(t_co *co_exec)
{
	char	*full_filename;
	pid_t	pid;
	int		status;

	full_filename = search_builtin(co_exec->co_name);
	if (full_filename == NULL)
		ft_printf("minishell: command not found: %s\n", co_exec->co_name);
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
