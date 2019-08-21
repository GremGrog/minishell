/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 14:49:11 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/15 14:49:12 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *g_pwd = "PWD=";
char *g_old_pwd = "OLDPWD=";

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

void	change_old_pwd_env(char *old_pwd)
{
	int		i;
	char	*tmp;

	i = search_var("OLDPWD");
	if (i == -1)
		return ;
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
	if (i == -1)
		return ;
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

void	add_shlvl(void)
{
	char	*str;
	int		lvl;
	char	*tmp;
	char	*buf;
	int		i;

	i = search_var("SHLVL");
	if (i == -1)
		return ;
	str = trim_var("SHLVL");
	lvl = ft_atoi(str);
	lvl += 1;
	buf = ft_itoa(lvl);
	tmp = ft_strjoin("SHLVL=", buf);
	free(g_env->envp[i]);
	g_env->envp[i] = ft_strdup(tmp);
	free(str);
	free(buf);
	free(tmp);
}
