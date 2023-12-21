# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 10:09:58 by jhouyet           #+#    #+#              #
#    Updated: 2023/12/21 09:56:16 by jhouyet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
ORANGE=\033[38;2;255;165;0m
NC=\033[0m 

NAME		= so_long

SRC_DIR		= src/
OBJ_DIR		= obj/
INC_DIR		= include/

SRC 		= $(wildcard $(SRC_DIR)*.c)
OBJ			= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

LIBFT 		= libft/lib/libft.a
LIBFT_PATH 	= libft/

MLX 		= mlx/libmlx.a
MLX_PATH 	= mlx/

CC			= gcc
RM			= rm -f
C_FLAGS		= -Wall -Wextra -Werror
MLX_FLAGS	= -framework OpenGL -framework AppKit
INCS 		= -I$(INC_DIR) -I.

TOTAL_FILES 	:= $(words $(SRC))
CURRENT_FILE 	:= 0

define progress_bar_so_long
    @$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
    @printf "\r$(YELLOW)Compiling So Long... [%-$(TOTAL_FILES)s] %d/%d $(NC)" $$(for i in $$(seq 1 $(CURRENT_FILE)); do printf "#"; done) $(CURRENT_FILE) $(TOTAL_FILES)
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then echo ""; fi
endef

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@
	$(call progress_bar_so_long)

all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)Linking objects to create executable...$(NC)"
	@$(CC) $(OBJ) -L$(LIBFT_PATH)lib -lft -L$(MLX_PATH) -lmlx $(MLX_FLAGS) -o $(NAME)
	@echo "$(BLUE)Executable $(NAME) created!$(NC)"

$(LIBFT):
	@echo "$(YELLOW)Compiling Libft...$(NC)"
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX):
	@echo "$(YELLOW)Compiling MLX...$(NC)"
	@$(MAKE) -C $(MLX_PATH) > /dev/null 2>&1

clean:
	@echo "$(ORANGE)Cleaning objects for So Long...$(NC)"
	@$(RM) $(OBJ_DIR)*.o
	@echo "$(GREEN)Cleaned So Long objects!$(NC)"
	@echo "$(ORANGE)Cleaning objects for Libft...$(NC)"
	@$(MAKE) clean -C $(LIBFT_PATH) > /dev/null
	@echo "$(GREEN)Cleaned objects Libft!$(NC)"
	@echo "$(ORANGE)Cleaning objects for MLX...$(NC)"
	@$(MAKE) clean -C $(MLX_PATH) > /dev/null
	@echo "$(GREEN)Cleaned MLX objects!$(NC)"

fclean: clean
	@echo "$(ORANGE)Fully cleaning library for So Long...$(NC)"
	@$(RM) $(NAME)
	@$(RM) -r $(OBJ_DIR)
	@echo "$(BLUE)Fully cleaned So Long!$(NC)"
	@echo "$(ORANGE)Fully cleaning library for Libft...$(NC)"
	@$(MAKE) fclean -C $(LIBFT_PATH) > /dev/null
	@echo "$(BLUE)Fully cleaned Libft!$(NC)"
	@echo "$(ORANGE)Fully cleaning library for MLX...$(NC)"
	@$(MAKE) clean -C $(MLX_PATH) > /dev/null
	@echo "$(BLUE)Fully cleaned  MLX!$(NC)"



re: fclean all

.PHONY: all clean fclean re
