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

t_env			*g_env;
void			init_env(void);
void			copy_matrix(char **env);

# endif
