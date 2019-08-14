/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 21:49:09 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/06/15 21:49:10 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *g_pwd = "PWD=";
char *g_old_pwd = "OLDPWD=";

void	cd_errors(char *path)
{
	if (access(path, F_OK) == -1)
		ft_printf("cd: no such file or directory: %s\n", path);
	else if (access(path, X_OK) == -1)
		ft_printf("cd: permission denied: %s\n", path);
}

void	change_old_pwd_env(char *old_pwd)
{
	int		i;
	char	*tmp;

	i = search_var("OLDPWD");
	free(g_env->envp[i]);
	tmp = ft_strjoin(g_old_pwd, old_pwd);
	g_env->envp[i] = (char*)malloc(sizeof(char) * ft_strlen(tmp) + 1);
	ft_strcpy(g_env->envp[i], tmp);
	free(tmp);
}

void	change_pwd_env(void)
{
	int		i;
	int		j;
	char	*new_pwd;
	char	*old_pwd;
	char	*tmp;

	i = search_var("PWD");
	j = 0;
	old_pwd = trim_var("PWD");
	free(g_env->envp[i]);
	new_pwd = (char*)malloc(sizeof(char) * PATH_MAX);
	new_pwd = getcwd(new_pwd, PATH_MAX);
	tmp = ft_strjoin(g_pwd, new_pwd);
	g_env->envp[i] = (char*)malloc(sizeof(char) * ft_strlen(tmp) + 1);
	ft_strcpy(g_env->envp[i], tmp);
	free(tmp);
	free(new_pwd);
	change_old_pwd_env(old_pwd);
	free(old_pwd);
}

char	*get_absolute_path(char *arg)
{
	char	*path;
	char	*buf;
	char	*tmp;

	path = trim_var("HOME");
	tmp = ft_strsub(arg, 1, ft_strlen(arg));
	buf = ft_strjoin(path, tmp);
	free(tmp);
	free(path);
	path = ft_strdup(buf);
	free(buf);
	return (path);
}

void	cd_builtin(char **args)
{
	int		r;
	int		f;
	char	*path;

	f = 1;
	path = NULL;
	if (args[1] != NULL && (ft_strcmp(args[1], "~") != 0) &&
	ft_strcmp(args[1], "-") != 0)
	{
		path = args[1];
		f = 0;
	}
	if (args[1] == NULL || ft_strcmp(args[1], "~") == 0)
		path = trim_var("HOME");
	if (args[1][0] == '~' && args[1][1] != '\0')
	{
		path = get_absolute_path(args[1]);
		f = 1;
	}
	if (args[1] != NULL && (ft_strcmp(args[1], "-") == 0))
		path = trim_var("OLDPWD");
	(r = chdir(path)) == 0 ? change_pwd_env() : cd_errors(path);
	if (f == 1)
		free(path);
}
