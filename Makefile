# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/27 12:16:11 by halnuma           #+#    #+#              #
#    Updated: 2025/01/27 15:56:07 by halnuma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re libft

# ------ COLORS ------ #

_END			= \033[0m
_GREY			= \033[0;30m
_RED			= \033[0;31m
_GREEN			= \033[0;32m
_YELLOW			= \033[0;33m
_BLUE			= \033[0;34m
_PURPLE			= \033[0;35m
_CYAN			= \033[0;36m
_BOLD			= \e[1m

# ------ VARIABLES ------ #

NAME			= push_swap
CC				= cc
AR				= ar -rcs
CFLAGS			= -Wall -Wextra -Werror

# ------ PATHS ------ #

P_OBJ 			= obj/
P_SRC 			= src/
P_UTILS			= $(P_SRC)utils/
P_INC			= includes/
P_LIB			= libft/

# ------ FILES ------ #

MAIN			= main						calculate_cost			\
				sort_small_stack			push_cheapest			\
				rotate_stacks				sort_stack

UTILS			= instructions				stack_utils				\
				args_managing_utils			error_checking_utils	

HDR_SRC			= libft						push_swap				\
				utils

SRC_MAIN		= $(addprefix $(P_SRC), $(addsuffix .c, $(MAIN)))
SRC_UTILS		= $(addprefix $(P_UTILS), $(addsuffix .c, $(UTILS)))
SRC_ALL			= $(SRC_MAIN) $(SRC_UTILS)
SRC_MESS		= $(addprefix -,$(addsuffix \n, $(SRC_ALL)))

OBJ_MAIN 		= $(addprefix $(P_OBJ), $(addsuffix .o, $(MAIN)))
OBJ_UTILS 		= $(addprefix $(P_OBJ), $(addsuffix .o, $(UTILS)))
OBJ_ALL 		= $(OBJ_MAIN) $(OBJ_UTILS)

HEADERS			= $(addprefix $(P_INC), $(addsuffix .h, $(HDR_SRC)))
LIBFT			= $(P_LIB)libft.a

# ------ RULES ------ #

all: 			libft $(NAME)

$(NAME): 		$(SRC_ALL) Makefile $(HEADERS) $(LIBFT)
				@$(CC) $(CFLAGS) -I $(P_INC) $(SRC_ALL) $(LIBFT) -o $@
				@echo -n "$(_YELLOW)Compiling:\n $(SRC_MESS)$(_END)"
				@echo "$(_GREEN)$(_BOLD)=> $(NAME) compiled!$(_END)"

libft:		
				@$(MAKE) -C $(P_LIB) --no-print-directory

# ------ BASIC RULES ------ #

clean: 
				@rm -rf $(P_OBJ)
				@$(MAKE) -C $(P_LIB) clean --no-print-directory
				@echo "$(_CYAN)$(NAME) cleaned!$(_END)"

fclean:
				@$(MAKE) clean --no-print-directory
				@$(MAKE) -C $(P_LIB) fclean --no-print-directory
				@rm -rf $(LIBFT)
				@rm -rf $(NAME)
				@echo "$(_CYAN)$(NAME) full cleaned!$(_END)"

re:
				@$(MAKE) fclean --no-print-directory
				@$(MAKE) all --no-print-directory
