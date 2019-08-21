/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:34:05 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/08 19:34:07 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_builtin(char *path, char *co_name)
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
	if (access(full_path, 0) == 0)
		return (full_path);
	else
	{
		free(full_path);
		return (NULL);
	}
}

char	*get_exec_path(char *co_name)
{
	char	*tmp;
	char	*buf;
	char	*path;

	tmp = (char*)malloc(sizeof(char) * PATH_MAX);
	getcwd(tmp, PATH_MAX);
	buf = ft_strsub(co_name, 1, ft_strlen(co_name));
	path = ft_strjoin(tmp, buf);
	free(tmp);
	free(buf);
	if (!(buf = (char*)malloc(sizeof(char) * (ft_strlen(path) + 1))))
		return (NULL);
	ft_strcpy(buf, path);
	free(path);
	return (buf);
}

char	*search_builtin(char *co_name)
{
	int		i;
	char	**path_var;
	char	*tmp;
	char	*full_filename;

	if (!co_name)
		return (NULL);
	if (co_name[0] == '/')
		return ((access(co_name, 0) == 0) ? ft_strdup(co_name) : NULL);
	if (co_name[0] == '.' && co_name[1] == '/')
		return (get_exec_path(co_name));
	full_filename = NULL;
	i = -1;
	if ((tmp = trim_var("PATH")) == NULL)
		return (NULL);
	path_var = ft_strsplit(tmp, ':');
	while (path_var[++i] != NULL)
	{
		if ((full_filename = get_builtin(path_var[i], co_name)) != NULL)
			break ;
	}
	del_matrix(path_var);
	free(path_var);
	free(tmp);
	return (full_filename);
}
