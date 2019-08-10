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

int		parse_input(char *input, t_args *args)
{
	char	*tmp;

	if (!input)
		return (-1);
	args->size = 0;
	args->argv = ft_strsplit(input, ';');
	while (args->argv[args->size] != NULL)
	{
		tmp = ft_strtrim(args->argv[args->size]);
		if (tmp[0] == '$')
			tmp = dollar_sign(tmp);
		if (tmp == NULL)
			return (-1);
		free(args->argv[args->size]);
		args->argv[args->size] = ft_strdup(tmp);
		free(tmp);
		args->size++;
	}
	free(input);
	return (0);
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
