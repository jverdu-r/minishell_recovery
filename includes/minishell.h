/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:07:55 by jverdu-r          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/08/09 10:34:53 by jverdu-r         ###   ########.fr       */
/*   Updated: 2023/06/19 19:53:37 by daparici         ###   ########.fr       */
=======
/*   Updated: 2023/06/22 20:27:33 by daparici         ###   ########.fr       */
>>>>>>> 409a870a76231a4eaab0873cb970655bcb32395b
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"

typedef enum	s_token
{
	PIPE = 1,
	LESS,
	LESS_LESS,
	GREAT,
	GREAT_GREAT,
}	t_token;

typedef struct	s_lexer
{
	char			*str;
	t_token			token;
	int				index;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}	t_lexer;

typedef struct	s_sp_cmds
{
	char				**cmd;
	int					token;
	char				*file;
	struct s_sp_cmds	*next;
	struct s_sp_cmds	*prev;
}	t_sp_cmds;

/*typedef struct s_env
{
	char	*var;
	void	*next;
}	t_env;*/

typedef struct	s_toolbox
{
	char		*args;
<<<<<<< HEAD
	char		**env;
	char		**sort_env;
	//t_env		envp;
	//t_env		sort_envp;
=======
	char		**envp;
	t_env		env;
	t_env		sort_envp;
>>>>>>> 409a870a76231a4eaab0873cb970655bcb32395b
	char		*env_rute;
	char		*pwd;
	char		*old_pwd;
	t_sp_cmds	*sp_cmds;
	t_lexer		*lexer_list;
}	t_toolbox;

typedef struct	s_p_toolbox
{
	t_lexer		*lexer_list;
	t_lexer		*redirections;
	int			num_redirections;
	t_toolbox	*tools;
}	t_p_toolbox;

//signal functions
void	signals_workout(void);

//t_lexer functions

void	lexer_addback(t_lexer **head, t_lexer *new);
void	lexer_add(t_lexer **head, t_lexer *new);
void	lexer_delone(t_lexer **list);
void	lexer_free(t_lexer *list);
void	lexer_show(t_lexer *list); //free list only for testting
int		lexer_length(t_lexer *list);
t_lexer	*lexer_new(char	*str, t_token token);
t_lexer	*lexer_last(t_lexer *list);

//t_sp_cmds functions
void		sp_cmds_addback(t_sp_cmds **head, t_sp_cmds *new);
void		sp_cmds_add(t_sp_cmds **head, t_sp_cmds *new);
void		sp_cmds_delone(t_sp_cmds **list);
void		sp_cmds_free(t_sp_cmds *list);
void		sp_cmds_show(t_sp_cmds *list); //frees list  only for testing
int			sp_cmds_length(t_sp_cmds *list);
t_sp_cmds	*sp_cmds_new(char **cmd, int token);
t_sp_cmds	*sp_cmds_last(t_sp_cmds *list);

//parse functions
int			parser(t_toolbox *tools);
int			file_checker(char *str, char c);
int			token_reader(t_toolbox *tools);
int			token_handler(t_toolbox *tools, int i);
t_token		check_token(char *tk, int i);

//loop functions
int		minishell_loop(t_toolbox *tools);
int		tools_load(t_toolbox *tools);
void	tools_reload(t_toolbox *tools);

//enviroment functions
<<<<<<< HEAD
char	**envp_dup(char **envp, t_toolbox *tools);
//char	 **st_envp(t_toolbox *tools, char **env);
=======
void	envp_dup(char **envp, t_toolbox *tools);
char	**st_envp(t_toolbox *tools, char **env);
>>>>>>> 409a870a76231a4eaab0873cb970655bcb32395b
int		pwd_search(t_toolbox *tools);
t_env	*env_lstnew_m(char *content);
void	env_lstadd_back(t_env **lst, t_env *new);
t_env	*env_lstlast(t_env *lst);
void	ft_lstlast_p_2(t_env *lst);

//utility functions
void	free_arr(char **arr);
int		handle_quotes(char *input);
int		check_input(t_toolbox *tools);
int		exit_code(void);

//error functions
int		error_msg(char *msg);
int		error_token(t_token token);
#endif
