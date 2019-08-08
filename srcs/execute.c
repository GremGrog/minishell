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

	full_filename = search_builtin(co_exec->co_name);
	if (full_filename == NULL)
		ft_printf("minishell: command not found: %s\n", co_exec->co_name);
	else
	{
		pid = fork();
		if (pid == 0)
			execve(full_filename, co_exec->co_args, g_env->envp);
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
