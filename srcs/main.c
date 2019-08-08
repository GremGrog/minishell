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

void	parse_input(char *input, t_args *args)
{
	char	*tmp;

	if (!input)
		return ;
	args->size = 0;
	args->argv = ft_strsplit(input, ';');
	while (args->argv[args->size] != NULL)
	{
		tmp = ft_strtrim(args->argv[args->size]);
		free(args->argv[args->size]);
		args->argv[args->size] = ft_strdup(tmp);
		free(tmp);
		args->size++;
	}
}

char	*add_memo(char *input, int buf_size)
{
	char	*tmp;

	tmp = ft_strdup(input);
	free(input);
	input = (char*)malloc(sizeof(char) * buf_size + 1);
	ft_strcpy(input, tmp);
	free(tmp);
	return (input);
}

char	*get_input(void)
{
	int		ret;
	int		i;
	int		buf_size;
	char	symb;
	char	*input;

	i = 0;
	buf_size = 10;
	input = (char*)malloc(sizeof(char) * buf_size);
	while ((ret = read(0, &symb, 1)) > 0)
	{
		if (symb == '\n')
		{
			input[i] = '\0';
			break ;
		}
		input[i++] = symb;
		if (i >= buf_size)
		{
			buf_size *= 2;
			input = add_memo(input, buf_size);
		}
	}
	return (input);
}

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
		parse_input(input, args);
		if (args == NULL)
			break ;
		co_exec = get_commands_to_exec(args);
		exec_command(args, co_exec);
		del_co_list(co_exec->next);
		free(co_exec);
		del_matrix(args->argv);
		free(args->argv);
		free(input);
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
	mini_loop();
	return (0);
}
