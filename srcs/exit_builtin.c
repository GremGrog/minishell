/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 14:47:55 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/07 14:47:57 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	del_co_list(t_co *co_exec)
{
	t_co	*buf;

	buf = NULL;
	while (co_exec)
	{
		buf = co_exec;
		co_exec = co_exec->next;
		if (buf->co_args)
		{
			del_matrix(buf->co_args);
			free(buf->co_args);
		}
		free(buf->co_name);
		free(buf);
	}
	free(co_exec);
}

void	exit_builtin(t_args *argv, t_co *co_exec)
{
	delete_env();
	del_matrix(argv->argv);
	free(argv->argv);
	del_co_list(co_exec);
	ft_printf("exit\n");
	exit(0);
}
