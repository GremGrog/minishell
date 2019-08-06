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

char	*search_home_dir(void)
{
	int		i;
	int		j;
	char	*home_path;

	i = 0;
	j = 0;
	home_path = NULL;
	while (g_env->envp[i] && ft_strncmp(g_env->envp[i], "HOME", 4) != 0)
		i++;
	while (g_env->envp[i][j] && g_env->envp[i][j++] != '=')
		;
	home_path = ft_strsub(g_env->envp[i], j, ft_strlen(g_env->envp[i]));
	return (home_path);
}

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
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (ft_strncmp(g_env->envp[i], "OLDPWD", 6) != 0)
		i++;
	while (g_env->envp[i][j++] != '=')
		;
	j++;
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

	i = 0;
	j = 0;
	while (ft_strncmp(g_env->envp[i], "PWD", 3) != 0)
		i++;
	while (g_env->envp[i][j++] != '=')
		;
	j++;
	old_pwd = ft_strsub(g_env->envp[i], j, ft_strlen(g_env->envp[i]));
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

void	cd_builtin(char *argv)
{
	int		r;
	int		f;
	char	*path;
	char	**args;

	f = 0;
	args = ft_strsplit(argv, ' ');
	path = NULL;
	if (args[1] != NULL && args[1][0] != '~')
		path = args[1];
	else if (args[1] == NULL || args[1][0] == '~')
	{
		path = search_home_dir();
		f = 1;
	}
	(r = chdir(path)) == 0 ? change_pwd_env() : cd_errors(path);
	if (f == 1)
		free(path);
	del_matrix(args);
	free(args);
}
