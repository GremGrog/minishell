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

void	change_pwd_env(int len)
{
	int		i;
	int		j;
	char	*buf;
	char	*temp;
	int		pwd_len;

	i = 0;
	j = 0;
	pwd_len = ft_strlen(g_pwd) + len;
	while (ft_strncmp(g_env->envp[i], "PWD", 3) != 0)
		i++;
	while (g_env->envp[i][j++] != '=')
		;
	j++;
	buf = ft_strsub(g_env->envp[i], j, ft_strlen(g_env->envp[i]));
	free(g_env->envp[i]);
	temp = (char*)malloc(sizeof(char) * 100);
	temp = getcwd(temp, 100);
	g_env->envp[i] = (char*)malloc(sizeof(char) * pwd_len + 1);

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
	(r = chdir(path)) == 0 ? change_pwd_env(ft_strlen(path)) : cd_errors(path);
	// if ((r = chdir(path)) == -1)
	// 	cd_errors(path);
	// else
	// 	change_pwd_env(path);
	if (f == 1)
		free(path);
	free(args);
}
