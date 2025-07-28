/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 07:19:24 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/07 07:19:24 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "minishell_types.h"
# include "libft.h"

//-- HISTORY --//
int		should_add_to_history(char *line);
void	cleanup_ignoreboth_history(void);

//-- MODULE: SIGNALS --/
void	setup_signals_prompt(void);
void	setup_signals_heredoc(void);
void	setup_signals_parent_ignore(void);
void	setup_signals_execute_child(void);
void	handle_sigint_prompt(int signo);
void	handle_sigint_heredoc(int signo);

//-- MODULE: GARBAGE COLLECTOR --//
void	*gc_malloc(size_t size);
void	*gc_safe(void *ptr);
void	gc_free(void *ptr);
void	gc_free_all(void);
void	gc_clear_postorder(t_gc *node);
t_gc	*gc_insert(t_gc *root, void *ptr);
t_gc	*gc_delete_node(t_gc *root, void *ptr);
t_gc	*gc_rotate_right(t_gc *root);
t_gc	*gc_rotate_left(t_gc *root);
t_gc	*gc_balance_node(t_gc *node);
int		gc_get_balance(t_gc *node);
int		gc_get_height(t_gc *node);
int		gc_max(int a, int b);

//-- MODULE: ENVIRONMENT --//
t_list	*create_env_node(char *keyvalue);
t_list	*get_env_node(char *key);
t_list	**get_env(void);
void	export_env(char *keyvalue);
void	init_env(char **envp);
void	unset_env(char *key);
char	*get_env_value(char *key);
char	**env_to_array(void);

//-- MODULE: ERROR HANDLING --//
int		get_exit_status(void);
int		handle_error(t_error err, t_token **token_list, t_cmd **cmd_list);
void	free_lists(t_token **token_list, t_cmd **cmd_list);
void	set_exit_status(int status);
int		shutdown(int abort);

//-- MODULE: LEXER --//
t_error	lex(t_token **token_list, char *line);
t_error	tokenize_redir(t_token **token_list, char *line, size_t *i);
t_error	tokenize_pipe(t_token **token_list, char *line, size_t *i);
t_error	tokenize_w_spaces(t_token **token_list, char *line, size_t *i);
t_error	tokenize_s_word(t_token **token_list, char *line, size_t *i);
t_error	tokenize_d_word(t_token **token_list, char *line, size_t *i);
t_error	tokenize_u_word(t_token **token_list, char *line, size_t *i);
t_error	validate_syntax(t_token *token_list);
t_token	*skip_separators(t_token *token);
t_token	*find_pipe(t_token *start);
t_token	*create_token(char *value, t_token_type type);
void	add_token_list_back(t_token **token_list, t_token *new_token);
void	free_tokens(t_token **token_list);
char	*create_unquoted_word(char *line, size_t start, size_t end);
size_t	find_quote_end(char *ln, size_t start, char quote);
int		is_escape_sequence(char *line, size_t i);

//-- MODULE: EXPANDER --//
void	free_tokens_if(t_token **token_list, int (*condition)(t_token *));
void	merge_word(t_token **token_list);
void	expand(t_token **token_list);
int		is_after_redir(t_token *token);
int		is_after_heredoc(t_token *token);
char	*expand_str(char *str);
char	*expand_var(char *str, size_t *i);

//-- MODULE: PARSER --//
void	parse(t_cmd **cmd_list, t_token *token_list);
void	parse_redirs(t_cmd *cmd, t_token *start, t_token *end);
void	parse_args(t_cmd *cmd, t_token *start, t_token *end);
void	free_cmds(t_cmd **cmd_list);

//-- MODULE: UTILITIES --//
int		is_only_spaces(char *line);
int		is_operator(t_token_type type);
int		is_word(t_token_type type);
int		is_separator(t_token_type type);
int		is_redir(t_token_type type);
int		is_quoted(t_token_type type);
int		is_pipe(t_token_type type);
int		is_separator_token(t_token *token);
int		is_empty_unquoted(t_token *token);
int		is_ambiguous_redir_token(t_token *token, char *expanded);
int		is_redir_char(char c);
int		is_op_char(char c);
int		is_quote_char(char c);
int		is_whitespaces(char c);
int		is_meta_char(char c);
int		is_var_start(char c);
int		is_var_char(char c);
char	*generate_prompt(void);
void	print_err(char *err);

//-- MODULE: REDIRECTIONS --//
t_error	process_heredocs(t_cmd *cmd_list);
t_error	read_heredoc(t_redir *redir, int write_fd);
int		process_cmd_redirections(t_cmd *cmd);
int		handle_single_redir(t_cmd *cmd, t_redir *redir);
int		apply_redir_fd(t_cmd *cmd, t_redir *redir, int flags);
int		print_redir_error(char *filename, int ambiguous);

//-- MODULE: EXECUTOR --//
int		execute(t_cmd *cmd_list);
int		wait_for_child(pid_t pid);
char	*find_path(char *command);
int		wait_for_children(t_cmd *cmd_list);
int		execute_single_cmd(t_cmd *cmd);
void	execute_child(t_cmd *cmd, int *prev_pipe, int *curr_pipe);
int		check_empty_command(t_cmd *cmd);
void	command_not_found(t_cmd *cmd);
void	execve_error(t_cmd *cmd);
void	permission_denied(t_cmd *cmd);
void	no_such_file_or_dir(t_cmd *cmd);
void	is_a_directory(t_cmd *cmd);
int		fork_error(int *prev_pipe, int *cur_pipe);
void	direct_path(t_cmd *cmd);
void	builtin_for_child(t_cmd *cmd);
void	execute_external_command(t_cmd *cmd, char *path);

//-- MODULE: BUILTINS --//
int		is_builtin(char *cmd);
int		is_valid_id(char *format, char stop_char);
void	exec_builtin(t_cmd *cmd, int fd[2], int print);
int		builtin_pwd(t_cmd *cmd, int fd[2]);
void	builtin_env(t_list *env_list, int fd[2]);
void	builtin_echo(t_cmd *cmd, int fd[2]);
int		print_sorted_exports(t_list *env_list, int fd[2]);
int		builtin_export(t_cmd *cmd, int fd[2]);
int		export_set(t_cmd *cmd);
void	builtin_exit(t_cmd *cmd, int print);
int		builtin_unset(t_cmd *cmd);
int		builtin_cd(t_cmd *cmd);

#endif
