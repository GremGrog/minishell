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

t_args	*parse_input(char *input)
{
	t_args	*args;

	if (!input)
		return (NULL);
	args = (t_args*)malloc(sizeof(t_args));
	args->size = 0;
	args->argv = ft_strsplit((char*)input, ';');
	while (args->argv[args->size] != NULL)
	{
		args->argv[args->size] = ft_strtrim(args->argv[args->size]);
		args->size++;
	}
	return (args);
}

void	get_input(char **buf)
{
	get_next_line(0, &(*buf));
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
		args = NULL;
		write(1, "*_*/` ", 6);
		get_input(&input);
		args = parse_input(input);
		if (args == NULL)
			break ;
		co_exec = get_commands_to_exec(args);
		exec_command(args, co_exec->next);
		input = NULL;
	}
	if (args)
		free(args);
	if (co_exec)
		free(co_exec);
}

int main(int argc, char **argv, char **env)
{
	// t_map	*map;
	// t_map	*output_buf;
	// int		i = 0;
	if (!argc && !argv && !env)
		return (-1);
	init_env();
	copy_env(env);
	mini_loop();
	delete_env();
	// map = create_hash_table(3);
	// add_elem_to_hasht(map, "cd", NULL);
	// add_elem_to_hasht(map, "cd", NULL);
	// add_elem_to_hasht(map, "kek", NULL);
	// add_elem_to_hasht(map, "dok", NULL);
	// output_buf = map;
	// // while (i < 3)
	// // {
	// // 	if (!output_buf->hash_t[i])
	// // 	{
	// // 		i++;
	// // 		continue ;
	// // 	}
	// // 	if (output_buf->hash_t[i]->key != NULL)
	// // 		ft_printf("%d %s\n", i, output_buf->hash_t[i]->key);
	// // 	if (output_buf->hash_t[i]->next)
	// // 	{
	// // 		output_buf->hash_t[i] = output_buf->hash_t[i]->next;
	// // 		while (output_buf->hash_t[i] != NULL)
	// // 		{
	// // 			ft_printf("->%d %s\n",i,  output_buf->hash_t[i]->key);
	// // 		output_buf->hash_t[i] = output_buf->hash_t[i]->next;
	// // 		}
	// // 	}
	// // 	i++;
	// // }
	// delete_hash_t(map);
	// free(map);
	return (0);
}
