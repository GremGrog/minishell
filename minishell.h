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
# include <limits.h>
# include "ft_printf/MainHeader/ft_printf.h"

typedef struct	s_env
{
	char		**envp;
	int			mem_size;
	int			used_size;
}				t_env;

typedef struct	s_args
{
	char			**argv;
	int				size;
}				t_args;

typedef struct	s_co
{
	char			*co_name;
	char			**co_args;
	struct s_co		*next;
}				t_co;

t_env			*g_env;
int				g_handler;

void			init_env(void);
void			delete_env(void);
void			copy_env(char **env);
void			add_mem_env(void);
void			print_env(void);
char			*get_input(void);
void			parse_input(char *input, t_args *args);
char			*dollar_sign(char *tmp);
void			ctrl_c_handler(int sig);
int				search_var(char *ar);
char			*trim_var(char *var);
int				get_argc(char **argv);
char			**check_dollar(char **argv);
t_co			*get_commands_to_exec(t_args *args);
void			exec_command(t_args *argv, t_co *co_exec);
char			*search_builtin(char *co_name);
void			change_old_pwd_env(char *old_pwd);
void			change_pwd_env(void);
void			cd_builtin(char **argv);
void			env_builtin(void);
void			setenv_builtin(char **argv);
void			unsetenv_builtin(char **argv);
void			echo_builtin(char **argv);
void			exit_builtin(t_args *argv, t_co *co_exec);
void			add_shlvl(void);

void			del_co_list(t_co *co_exec);
void			del_co(t_co *buf);

#endif
