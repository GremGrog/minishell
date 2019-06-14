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

char	*get_command_name(char *com)
{
	char	*command;
	int		i;

	i = 0;
	command = NULL;
	while (com[i] != ' ' && com[i])
		i++;
	command = (char*)malloc(sizeof(char) * i + 1);
	ft_strncpy(command, com, i);
	command[i] = '\0';
	return (command);
}

void	get_command_from_input(t_args *args)
{
	char	*co_name;
	int		i;

	i = 0;
	// while (args->argv[i] != NULL)
	// {
	co_name = get_command_name(args->argv[i]);
		// i++;
	// }
}

void	parse_input(char *input)
{
	t_args	*args;

	args = (t_args*)malloc(sizeof(t_args));
	args->size = 0;
	args->argv = ft_strsplit((char*)input, ';');
	while (args->argv[args->size] != NULL)
	{
		args->argv[args->size] = ft_strtrim(args->argv[args->size]);
		ft_printf("%s\n", args->argv[args->size]);
		args->size++;
	}
	get_command_from_input(args);
}

void	get_input(char **buf)
{
	get_next_line(0, &(*buf));
}

void	mini_loop(void)
{
	char	*input;

	input = NULL;
	while (1)
	{
		write(1, "*_*/` ", 6);
		get_input(&input);
		parse_input(input);
	}
}

int main(int argc, char **argv, char **env)
{
	if (!argc && !argv)
		return (-1);
	init_env();
	copy_matrix(env);
	mini_loop();
	// create_hash_table();
	return (0);
}
