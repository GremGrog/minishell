# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/11 15:10:52 by fmasha-h          #+#    #+#              #
#    Updated: 2019/06/11 15:10:54 by fmasha-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS = -Wall -Wextra -Werror

LS_HEAD = -I minishell.h

PRINTF_HEAD = -I ft_printf/MainHeader/ft_printf.h

PRINTF_LIB = ft_printf/libftprintf.a

DIR_O = obj

SRCF = srcs/main.c \
		srcs/init_env.c \
		srcs/get_command_to_exec.c \
		srcs/execute.c \
		srcs/search_builtin.c \
		srcs/cd_builtin.c \
		srcs/env_builtins.c \
		srcs/setenv_builtin.c \
		srcs/unsetenv_builtin.c \
		srcs/echo_builtin.c \
		srcs/exit_builtin.c \

OBJF = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SRCF)))

all: $(NAME)

$(DIR_O):
	@mkdir -p obj
	@mkdir -p obj/srcs

$(NAME): $(DIR_O) $(OBJF)
	@make -C ft_printf
	@gcc $(FLAGS) $(OBJF) $(PRINTF_LIB) -o $(NAME)

$(DIR_O)/%.o: %.c
	@gcc $(FLAGS) $(LS_HEAD) $(PRINTF_HEAD) -o $@ -c $<

clean:
	@rm -rf $(DIR_O)
	@make clean -C ft_printf

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C ft_printf

re: fclean all
