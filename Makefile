# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antondob <antondob@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 00:08:38 by antondob          #+#    #+#              #
#    Updated: 2020/04/09 22:05:24 by antondob         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# EXECUTABLES
SORTER = push_swap
CHECKER = checker
LIB_NAME = libftprintf.a
# DIRECTORIES
LIB_DIR = libft/
OBJ_DIR = obj/
INCL_DIR = includes/
# SOURCES
JNT_SRC = algo_quicksort.c\
			cmd_control.c\
			cmd_optimize.c\
			cmd_push.c\
			cmd_reverse_rotate.c\
			cmd_rotate.c\
			cmd_swap.c\
			params.c\
			print_result.c\
			check_sorted.c\
			read_check.c
SORTER_SRC = main_push_swap.c
CHECKER_SRC = main_checker.c
HEADERS = push_swap.h
LIB = $(LIB_DIR)$(LIB_NAME)
# OBJECTS
JNT_OBJ = $(patsubst %.c, %.o, $(JNT_SRC))
SORTER_OBJ = $(patsubst %.c, %.o, $(SORTER_SRC))
CHECKER_OBJ = $(patsubst %.c, %.o, $(CHECKER_SRC))
# OBJECT_PATHS
JNT_OBJ_PATH = $(addprefix $(OBJ_DIR), $(JNT_OBJ))
SORTER_OBJ_PATH = $(addprefix $(OBJ_DIR), $(SORTER_OBJ))
CHECKER_OBJ_PATH = $(addprefix $(OBJ_DIR), $(CHECKER_OBJ))
# INCLUDES
INCLUDES = $(addprefix $(INCL_DIR), $(HEADERS))
# COMPILER
COMPILER = gcc
FLAGS =  -Wall -Wextra -Werror
# PATHS
vpath %.o obj/
vpath algo%.c src/algo/
vpath cmd%.c src/cmd/
vpath params%.c src/params/
vpath print%.c src/print/
vpath read%.c src/read_check/
vpath check%.c src/read_check/
vpath main%.c src/main/
vpath %.h includes/

all: $(SORTER) $(CHECKER)

$(SORTER): $(JNT_OBJ) $(SORTER_OBJ) $(LIB)
	@$(COMPILER) -o $@ $(JNT_OBJ_PATH) $(SORTER_OBJ_PATH) $(LIB)
	@echo "\033[0;93mSORTER COMPILATION:  \033[1;92mSUCCESS\033[0m"

$(CHECKER): $(JNT_OBJ) $(CHECKER_OBJ) $(LIB)
	@$(COMPILER) -o $@ $(JNT_OBJ_PATH) $(CHECKER_OBJ_PATH) $(LIB)
	@echo "\033[0;93mCHECKER COMPILATION: \033[1;92mSUCCESS\033[0m"

$(JNT_OBJ): %.o : %.c $(INCLUDES)
	@mkdir -p $(OBJ_DIR)
	$(COMPILER) $(FLAGS) -I $(INCL_DIR) -c $< -o $(OBJ_DIR)$@

$(SORTER_OBJ): %.o : %.c $(INCLUDES)
	$(COMPILER) $(FLAGS) -I $(INCL_DIR) -c $< -o $(OBJ_DIR)$@

$(CHECKER_OBJ): %.o : %.c $(INCLUDES)
	$(COMPILER) $(FLAGS) -I $(INCL_DIR) -c $< -o $(OBJ_DIR)$@
	
$(LIB):
	@$(MAKE) -C $(LIB_DIR)

clean:
	@$(MAKE) -C $(LIB_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIB_DIR) fclean
	@rm -f $(SORTER) $(CHECKER)

re: fclean all
