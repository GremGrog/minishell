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

void	cd_builtin(char *argv)
{
	int	r;
	char	*path;
	char	**args;

	args = ft_strsplit(argv, ' ');
	if (args[1] != NULL)
		path = args[1];
	else if (args[1] == NULL)
		path = "~";
	r = chdir(path);
	if (r == -1)
	{
		if (ENOENT[chdir(path)])
			ft_printf(" No such file or directory");
	}
}
