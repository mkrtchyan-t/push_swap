PUSH_SWAP	= push_swap
CHECKER		= checker
CC			= gcc
FLAGS		= -Wall -Wextra -Werror

SRCS_PS		=	push_swap.c error_check.c stacking.c mini_sort.c \
				instructions.c instructions2.c instructions3.c stack_control.c \
				ft_quicksort.c sort.c sort2.c ft_error.c
SRCS_CH		=	checker.c get_next_line.c stack_control.c stacking.c ft_quicksort.c\
				instructions.c instructions2.c instructions3.c error_check.c ft_error.c
OBJPS		= $(SRCS_PS:.c=.o)
OBJCH		= $(SRCS_CH:.c=.o)
OBJ_DIR		= ./objects/
OBJ_FILESPS	= $(addprefix $(OBJ_DIR), $(OBJPS))
OBJ_FILESCH	= $(addprefix $(OBJ_DIR), $(OBJCH))
LIBFT		= ./libft/libft.a

GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0;0m

all: $(LIBFT) $(PUSH_SWAP) $(CHECKER)

$(LIBFT):
	@make -C ./libft --silent

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -o $@ -c $<

$(PUSH_SWAP): $(OBJ_FILESPS)
	@$(CC) $(LIBFT) $(OBJ_FILESPS) -o $@
	@echo "$(GREEN) libft.a	created! $(RESET)"
	@echo "$(GREEN) objects	created! $(RESET)"
	@echo "$(GREEN) $@	created! $(RESET)"

$(CHECKER): $(OBJ_FILESCH)
	@$(CC) $(LIBFT) $(OBJ_FILESCH) -o $@
	@echo "$(GREEN) $@	created! $(RESET)"

clean:
	@make -C ./libft clean --silent
	@rm -rf $(OBJ_DIR) --silent
	@echo "$(RED) libft.a	deleted! $(RESET)"
	@echo "$(RED) objectcs	deleted! $(RESET)"

fclean: clean
	@rm -rf $(PUSH_SWAP) --silent
	@rm -rf $(CHECKER) --silent
	@rm -rf $(LIBFT) --silent
	@echo "$(RED) $(PUSH_SWAP)	deleted! $(RESET)"
	@echo "$(RED) $(CHECKER)	deleted! $(RESET)"

re:	fclean all

.PHONY: all clean fclean re
