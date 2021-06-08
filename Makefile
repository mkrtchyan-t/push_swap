PUSH_SWAP	= push_swap
CHECKER		= checker
CC			= gcc
FLAGS		= -Wall -Wextra -Werror

SRCS_PS		=	push_swap.c ft_stack_print.c error_check.c stacking.c mini_sort.c \
				instructions.c instructions2.c instructions3.c stack_control.c \
				ft_quicksort.c sort.c sort2.c ft_error.c
# SRCS_CH		=	checker.c get_next_line.c
OBJ			= $(SRCS_PS:.c=.o)
OBJ_DIR		= ./objects/
OBJ_FILES	= $(addprefix $(OBJ_DIR), $(OBJ))
# LIB_DIR		= libft/
# LIB			= libft.a
LIBFT		= ./libft/libft.a

GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0;0m

all: $(LIBFT) ./libft/libft.a $(PUSH_SWAP)

$(LIBFT):
	@make -C ./libft --silent

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -o $@ -c $<

$(PUSH_SWAP): $(OBJ_FILES)
	@$(CC) $(LIBFT) $(OBJ_FILES) -o $@
	@echo "$(GREEN) libft.a created! $(RESET)"
	@echo "$(GREEN) objects created! $(RESET)"
	@echo "$(GREEN) $@ created! $(RESET)"

clean:
	@make -C ./libft clean --silent
	@rm -rf $(OBJ_DIR) --silent
	@echo "$(RED) libft.a deleted! $(RESET)"
	@echo "$(RED) objectcs deleted! $(RESET)"

fclean: clean
	@rm -rf $(PUSH_SWAP) --silent
	@rm -rf $(LIBFT) --silent
	@echo "$(RED) $(PUSH_SWAP) deleted! $(RESET)"

re:	clean all

.PHONY: all clean fclean re
