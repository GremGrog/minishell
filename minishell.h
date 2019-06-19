/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:10:34 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/06/11 15:10:36 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <dirent.h>
# include <stdlib.h>
# include <fcntl.h>
# include <signal.h>
# include "ft_printf/MainHeader/ft_printf.h"

typedef struct	s_env
{
	char		**envp;
	int			mem_size;
	int			used_size;
}				t_env;

typedef struct	s_hasht
{
	void			*key;
	void			*value;
	struct s_hasht	*next;
}				t_hasht;

typedef struct	s_map
{
	t_hasht		**hash_t;
	int			size;
	void		*hash_func;
}				t_map;

typedef struct	s_args
{
	char			**argv;
	int				size;
	struct s_args	*next;
}				t_args;

typedef struct	s_co
{
	char			*co_name;
	char			**co_args;
	int				index_argv;
	struct s_co		*next;
}				t_co;

int				g_htabsize;

t_env			*g_env;
void			init_env(void);
void			copy_matrix(char **env);
t_map			*create_hash_table(int hasht_size);
void			add_elem_to_hasht(t_map *head, char *key, void *value);
void			delete_hash_t(t_map *head);
t_co			*get_commands_to_exec(t_args *args);
void			exec_command(t_args *argv, t_co *co_exec);
void			cd_builtin(char *path);
#endif
