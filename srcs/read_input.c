/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 18:56:01 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/09 18:56:02 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		parse_input(char *input, t_args *args)
{
	t_co	*co_exec;

	if (!input)
		return ;
	args->size = 0;
	args->argv = ft_strsplit(input, ';');
	args->argv = check_dollar(args->argv);
	while (args->argv[args->size++])
		;
	free(input);
	co_exec = NULL;
	co_exec = get_commands_to_exec(args);
	exec_command(args, co_exec->next);
	del_matrix(args->argv);
	free(args->argv);
	free(co_exec);
}

void	ctrl_c_handler(int sig)
{
	sig = 0;
	write(0, "\n", 1);
	write(1, "*_*/` ", 6);
	g_handler = 1;
}

char	*add_memo(char *input, int buf_size)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup(input);
	free(input);
	input = (char*)malloc(sizeof(char) * buf_size);
	ft_strcpy(input, tmp);
	free(tmp);
	while (i < buf_size)
		input[i++] = 0;
	return (input);
}

char	*read_input(char *input, int buf_size)
{
	int		ret;
	int		i;
	char	symb;

	symb = 0;
	i = 0;
	while ((ret = read(0, &symb, 1)) > 0)
	{
		if (symb == '\n')
		{
			g_handler = 0;
			break ;
		}
		input[i] = symb;
		if (i + 1 == buf_size)
		{
			buf_size *= 2;
			input = add_memo(input, buf_size);
		}
		i++;
	}
	if (ret == 0)
		write(1, "\n", 1);
	input[i] = '\0';
	return (input);
}

char	*get_input(void)
{
	int		i;
	int		buf_size;
	char	*input;

	i = 0;
	buf_size = 100;
	input = (char*)malloc(sizeof(char) * buf_size);
	while (i < buf_size)
		input[i++] = 0;
	input = read_input(input, buf_size);
	return (input);
}
