/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:10:42 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/06/11 15:10:44 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mini_loop(void)
{
	char	*input;
	t_args	*args;
	t_co	*co_exec;

	input = NULL;
	while (1)
	{
		co_exec = NULL;
		args = (t_args*)malloc(sizeof(t_args));
		write(1, "*_*/` ", 6);
		input = get_input();
		if (parse_input(input, args) != -1)
		{
			if (args == NULL)
				break ;
			co_exec = get_commands_to_exec(args);
			exec_command(args, co_exec->next);
			del_matrix(args->argv);
			free(args->argv);
		}
		free(args);
		free(co_exec);
		input = NULL;
	}
	delete_env();
}

int		main(int argc, char **argv, char **env)
{
	if (!argc && !argv && !env)
		return (-1);
	init_env();
	copy_env(env);
	mini_loop();
	return (0);
}
