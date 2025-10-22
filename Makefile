# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnnya <nnnya@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/01 15:38:02 by nnnya             #+#    #+#              #
#    Updated: 2025/10/01 17:00:02 by nnnya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# --- ソースファイル ---
# コマンド関連
CMDS_DIR = srcs/commands/
CMDS_FILES = push.c reverse_rotate.c rotate.c swap.c
CMDS_SRCS = $(addprefix $(CMDS_DIR), $(CMDS_FILES))

# ユーティリティ関連
UTILS_DIR = srcs/utils/
UTILS_FILES = error.c stack_utils.c
UTILS_SRCS = $(addprefix $(UTILS_DIR), $(UTILS_FILES))

# メインロジック関連
SRCS_DIR = srcs/
SRCS_FILES = main.c init.c sort_elements.c sort_small.c chunk_sort.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

# すべてのソースファイルを結合
ALL_SRCS = $(SRCS) $(CMDS_SRCS) $(UTILS_SRCS)

# --- オブジェクトファイル ---
OBJS = $(ALL_SRCS:.c=.o)

# --- ライブラリ ---
LIBFT_DIR = includes/libft/
LIBFT = $(LIBFT_DIR)libft.a
PRINTF_DIR = includes/printf/
PRINTF = $(PRINTF_DIR)printf.a

# --- インクルードパス ---
INCS = -I includes -I $(LIBFT_DIR) -I $(PRINTF_DIR)

# --- ルール ---
all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re