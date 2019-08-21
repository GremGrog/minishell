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

void	cd_errors(char *path)
{
	if (!path)
		return ;
	if (access(path, F_OK) == -1)
		ft_printf("cd: no such file or directory: %s\n", path);
	else if (access(path, X_OK) == -1)
		ft_printf("cd: permission denied: %s\n", path);
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

char	*get_old_path(void)
{
	char	*path;

	path = trim_var("OLDPWD");
	if (!path)
	{
		path = (char*)malloc(sizeof(char) * PATH_MAX);
		path = getcwd(path, PATH_MAX);
	}
	return (path);
}

void	cd_builtin(char **args)
{
	int		r;
	int		f;
	char	*path;

	f = 1;
	path = NULL;
	if (args[1] && ft_strcmp(args[1], "~") != 0 && ft_strcmp(args[1], "-") != 0)
	{
		path = args[1];
		f = 0;
	}
	if (args[1] == NULL || ft_strcmp(args[1], "~") == 0)
		path = trim_var("HOME");
	if (args[1] != NULL && args[1][0] == '~' && args[1][1] != '\0')
	{
		path = get_absolute_path(args[1]);
		f = 1;
	}
	if (args[1] != NULL && (ft_strcmp(args[1], "-") == 0))
		path = get_old_path();
	(r = chdir(path)) == 0 ? change_pwd_env() : cd_errors(path);
	if (args[1] != NULL && ft_strcmp(args[1], "-") == 0)
		ft_printf("%s\n", path);
	if (f == 1)
		free(path);
}
