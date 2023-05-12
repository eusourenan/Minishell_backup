

#ifndef HEADER_H
# define HEADER_H

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <bsd/string.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/wait.h>
#include "libft.h"

struct s_env
{
	char			*var;
	struct s_env	*next;
};

typedef struct s_env t_env;

void	free_matrix(void **matrix);

/*------------  commands.c  ----------------*/
char	**split_commands(char *input);

/*------------  env.c  ----------------*/
t_env	*env_build(char **envp);
char	**list_to_pointer(t_env *list);

/*------------  execute.c  ----------------*/
int		multiple_commands(char **command, t_env *env);
int		single_command(char **command, t_env *env);
void	execute_command(char *input, t_env *env);


/*------------  list.c  ----------------*/
void	free_list(t_env **list);
void	add_back(t_env **list, t_env *node);
t_env	*new_node(char *value);
size_t	list_size(t_env *list);

/*------------  path.c  ----------------*/
char	*find_path(char *command, t_env *env);
char	*join_path(char *path_init, char *path_end);

/*------------  pipe.c  ----------------*/
int		has_pipe(char *input);
int		has_invalid_pipe(char *input);
int		count_pipes(char *input);

/*------------  quotemarks.c  ----------------*/
int		has_unclosed_quotes(char *input);
void	remove_quotes(char *input);

/*------------  spaces.c  ----------------*/
void	clean_inner_spaces(char *input);
void	restore_inner_spaces(char *input);

/*------------  var.c  ----------------*/
char	*find_var(char *input);
char	*get_var_name(char *start);
char	*get_value_of_var(char *var, t_env *env);
char	*expand_variables(char *input, t_env *env);

/*------------  .c  ----------------*/
int		is_builtin(char *command);
void	ft_exit(char **args);
#endif