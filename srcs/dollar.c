/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 18:42:51 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/09 18:42:52 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*dollar_sign(char *tmp)
{
	int		i;
	char	*buf;
	char	*str;

	buf = ft_strsub(tmp, 1, ft_strlen(tmp) - 1);
	i = search_var(buf);
	if (i == -1)
	{
		free(buf);
		return (NULL);
	}
	str = trim_var(g_env->envp[i]);
	free(buf);
	return (str);
}

char	**check_dollar(char **argv)
{
	int		i;
	char	*tmp;
	char	*buf;

	i = 0;
	while (argv[i])
	{
		tmp = ft_strtrim(argv[i]);
		free(argv[i]);
		argv[i] = NULL;
		if (tmp[0] == '$')
		{
			buf = dollar_sign(tmp);
			if (buf)
			{
				argv[i] = ft_strdup(buf);
				free(buf);
			}
		}
		else
			argv[i] = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	return (argv);
}
