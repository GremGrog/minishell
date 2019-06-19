/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_to_exec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:10:57 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/06/15 16:10:59 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_node_co(t_co *head, t_co *node)
{
	while (head->next != NULL)
		head = head->next;
	head->next = node;
	node->next = NULL;
}

t_co	*get_command_name(char *com)
{
	t_co	*co_to_exec;
	int		i;

	i = 0;
	co_to_exec = (t_co*)malloc(sizeof(t_co));
	while (com[i] != ' ' && com[i])
		i++;
	co_to_exec->co_name = (char*)malloc(sizeof(char) * i + 1);
	ft_strncpy(co_to_exec->co_name, com, i);
	co_to_exec->co_name[i + 1] = '\0';
	co_to_exec->next = NULL;
	return (co_to_exec);
}

t_co	*get_commands_to_exec(t_args *args)
{
	t_co	*co_exec;
	t_co	*head;
	int		i;

	i = 0;
	if (!args)
		return (NULL);
	head = (t_co*)malloc(sizeof(t_co));
	head->co_name = NULL;
	head->co_args = NULL;
	head->index_argv = -1;
	head->next = NULL;
	while (args->argv[i] != NULL)
	{
		co_exec = get_command_name(args->argv[i]);
		co_exec->index_argv = i;
		co_exec->co_args = ft_strsplit(args->argv[i], ' ');
		add_node_co(head, co_exec);
		i++;
	}
	return (head);
}
