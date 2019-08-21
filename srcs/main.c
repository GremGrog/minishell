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

	input = NULL;
	g_handler = 0;
	signal(SIGINT, ctrl_c_handler);
	while (1)
	{
		args = (t_args*)malloc(sizeof(t_args));
		if (g_handler == 0)
			write(1, "*_*/` ", 6);
		else
			g_handler = 0;
		input = get_input();
		parse_input(input, args);
		free(args);
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
	add_shlvl();
	mini_loop();
	return (0);
}
