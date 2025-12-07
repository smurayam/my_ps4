# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnnya <nnnya@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/24 19:27:39 by nnnya             #+#    #+#              #
#    Updated: 2025/12/07 22:01:47 by nnnya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =   push_swap
CC          =   cc
CFLAGS      =   -Wall -Wextra -Werror

SRCS        =   srcs/commands.c \
                srcs/init.c \
                srcs/sort_elements.c \
                srcs/chunk_sort.c \
                srcs/error.c \
                srcs/main.c \
                srcs/sort_small.c

OBJS        =   $(patsubst srcs/%.c,objs/%.o,$(SRCS))
OBJ_DIR     =   objs

LIBDIR      =   includes/printf/Libft01
LIB         =   libft.a

FT_PRINTFDIR =  includes/printf
FT_PRINTF    =  libftprintf.a

.DEFAULT_GOAL = all

all: $(NAME)

$(NAME): $(OBJS) $(LIBDIR)/$(LIB) $(FT_PRINTFDIR)/$(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBDIR) -lft -L$(FT_PRINTFDIR) -lftprintf

$(LIBDIR)/$(LIB):
	make -C $(LIBDIR)

$(FT_PRINTFDIR)/$(FT_PRINTF):
	make -C $(FT_PRINTFDIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: srcs/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBDIR) clean
	make -C $(FT_PRINTFDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBDIR) fclean
	make -C $(FT_PRINTFDIR) fclean

re: fclean all

.PHONY: all clean fclean re