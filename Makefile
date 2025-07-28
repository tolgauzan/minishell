NAME		= minishell
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -I$(INC_DIR) -I$(LIBFT_DIR)
SRC_DIR		= src
INC_DIR		= inc
MAKEFLAGS	+= --no-print-directory
LIBFT_DIR	= libft
SRCS		= $(SRC_DIR)/main.c \
			$(SRC_DIR)/env/env_array.c \
			$(SRC_DIR)/env/env_utils.c \
			$(SRC_DIR)/env/env.c \
			$(SRC_DIR)/error/error.c \
			$(SRC_DIR)/error/status.c \
			$(SRC_DIR)/gc/gc_delete.c \
			$(SRC_DIR)/gc/gc_insert.c \
			$(SRC_DIR)/gc/gc_utils.c \
			$(SRC_DIR)/gc/gc.c \
			$(SRC_DIR)/lexer/tokenize_operator.c \
			$(SRC_DIR)/lexer/tokenize_word.c \
			$(SRC_DIR)/lexer/tokenize_utils.c \
			$(SRC_DIR)/lexer/lexer_utils.c \
			$(SRC_DIR)/lexer/lexer.c \
			$(SRC_DIR)/lexer/syntax_check.c \
			$(SRC_DIR)/expand/expand_str.c \
			$(SRC_DIR)/expand/expand_utils.c \
			$(SRC_DIR)/expand/expand.c \
			$(SRC_DIR)/parser/parser_args.c \
			$(SRC_DIR)/parser/parser_redir.c \
			$(SRC_DIR)/parser/parser.c \
			$(SRC_DIR)/utils/char_var_utils.c \
			$(SRC_DIR)/utils/char_utils.c \
			$(SRC_DIR)/utils/type_operator.c \
			$(SRC_DIR)/utils/type_word.c \
			$(SRC_DIR)/utils/prompt.c \
			$(SRC_DIR)/utils/history.c \
			$(SRC_DIR)/utils/utils.c \
			$(SRC_DIR)/redir/redir.c \
			$(SRC_DIR)/redir/heredoc.c \
			$(SRC_DIR)/redir/heredoc_io.c \
			$(SRC_DIR)/builtin/b_cd.c \
			$(SRC_DIR)/builtin/b_echo.c \
			$(SRC_DIR)/builtin/b_env.c \
			$(SRC_DIR)/builtin/b_exit.c \
			$(SRC_DIR)/builtin/b_export_print.c \
			$(SRC_DIR)/builtin/b_export.c \
			$(SRC_DIR)/builtin/b_pwd.c \
			$(SRC_DIR)/builtin/b_unset.c \
			$(SRC_DIR)/builtin/builtin.c \
			$(SRC_DIR)/exec/error.c \
			$(SRC_DIR)/exec/exec.c \
			$(SRC_DIR)/exec/execute_single_cmd.c \
			$(SRC_DIR)/exec/find_path.c \
			$(SRC_DIR)/exec/utils.c \
			$(SRC_DIR)/exec/wait_for_children.c \
			$(SRC_DIR)/exec/execute_child.c \
			$(SRC_DIR)/signal/signal_handler.c \
			$(SRC_DIR)/signal/signal_setup.c

OBJS		= $(SRCS:.c=.o)
LIBFT		= $(LIBFT_DIR)/libft.a

GREEN		= \033[0;32m
CYAN		= \033[0;36m
YELLOW		= \033[1;33m
RESET		= \033[0m
CLEAR_LINE	= \033[K
WINKY		= 😊


all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lreadline -o $(NAME)
	@printf "\r$(GREEN)✔️  Built     :$(RESET) $(YELLOW)$(NAME)$(RESET) executable created$(CLEAR_LINE)\n"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\r$(GREEN)📃 Compiling :$(RESET) $(CYAN)$<$(RESET) $(CLEAR_LINE)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)📚 Built     :$(RESET) $(YELLOW)libft$(RESET) static library created\n"

clean:
	@rm -f $(OBJS)
	@echo "$(GREEN)$(FILE_ICON)🧹 Cleaned :$(RESET) $(CYAN)minishell object files$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)🧹 Removed :$(RESET) $(YELLOW)minishell executable$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
	@printf "$(GREEN)🛠️  Rebuilt   :$(RESET) $(YELLOW)$(NAME)$(RESET) project $(WINKY)$(CLEAR_LINE)\n"

.PHONY: all clean fclean re
