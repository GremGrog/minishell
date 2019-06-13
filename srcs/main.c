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


void	get_input(void)
{
	char	*buf;

	get_next_line(0, &buf);
	ft_printf("%s\n", buf);
}

void	mini_loop(void)
{
	while (1)
	{
		write(1, "o_O > ", 6);
		get_input();
	}
}

int main(int argc, char **argv, char **env)
{
	if (!argc && !argv)
		return (-1);
	init_env();
	copy_matrix(env);
	mini_loop();
	return (0);
}
