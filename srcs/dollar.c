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

	buf = ft_strsub(tmp, 1, ft_strlen(tmp));
	i = search_var(buf);
	if (i == -1)
	{
		ft_printf("%s: Undefined variable.\n", buf);
		return (NULL);
	}
	str = trim_var(g_env->envp[i]);
	free(tmp);
	free(buf);
	return (str);
}
