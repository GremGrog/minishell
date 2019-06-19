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
// 
// char	*search_home_dir(void)
// {
//
// }

void	cd_builtin(char *argv)
{
	int	r;
	char	*path;
	char	**args;

	args = ft_strsplit(argv, ' ');
	path = NULL;
	if (args[1] != NULL && args[1][0] != '~')
		path = args[1];
	else if (args[1] == NULL || args[1][0] == '~')
		path = "/Users/fmasha-h";
	r = chdir(path);
	if (r == -1)
	{
		if (access(path, F_OK) == -1)
			ft_printf("cd: no such file or directory: %s\n", path);
	}
}
