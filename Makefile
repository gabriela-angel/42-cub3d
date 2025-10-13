# ===========================================================================
#  =============================== CONTROL =================================
# ===========================================================================

UP = \033[A
CUT = \033[K
RESET = \033[0m
RED = \033[31;3m
GREEN = \033[32;3m
YELLOW = \033[33;3m
WHITE = \033[37;1;4m
CYAN = \033[36;1;3;208m

# ===========================================================================
#  =============================== COMPILER ================================
# ===========================================================================

CFLAGS := -Wall -Wextra -Werror -g3
OFLAGS := -Ofast -fno-stack-protector -ffast-math -Wunreachable-code
LIBFLAGS := -ldl -lglfw -pthread -lm
VALGRIND_LOG := valgrind.log

# ===========================================================================
#  =============================== LIBFT ===================================
# ===========================================================================

LIB_PATH := ./libs/libft
LIB_NAME := libft.a

# ===========================================================================
#  =============================== MLX42 ===================================
# ===========================================================================

MLX_PATH := ./libs/MLX
MLX_BUILD_PATH := $(MLX_PATH)/build
MLX_NAME := libmlx42.a

# ===========================================================================
#  =============================== CUB3D ===================================
# ===========================================================================

NAME = cub3d
SRC_PATH = ./src/
HEADER_PATH = ./include/
BUILD_PATH = ./build/

GLOBAL_PATH = ./shared/

FILES = \
	main.c \
	init.c \
	error.c \
	hooks.c \
	draw.c \
	$(GLOBAL_PATH)global.c \

OBJS = $(addprefix $(BUILD_PATH), $(FILES:%.c=%.o))

# ===========================================================================
#  ================================= RULES =================================
# ===========================================================================

all: mlx libft $(BUILD_PATH) print $(NAME)

mlx: 
ifeq ($(wildcard $(MLX_BUILD_PATH)/$(MLX_NAME)),)
	@printf "$(CYAN)-------------------- --------------- --------------------$(COLOR_LIMITER)\n"
	@printf "$(CYAN)--------------------| COMPILING MLX |--------------------$(COLOR_LIMITER)\n"
	@printf "$(CYAN)-------------------- --------------- --------------------$(COLOR_LIMITER)\n"
	@cmake $(MLX_PATH) -B $(MLX_BUILD_PATH)
	@make -C $(MLX_BUILD_PATH) -j4 --no-print-directory
endif

libft:
ifeq ($(wildcard $(LIB_PATH)/$(LIB_NAME)),)
	@printf "$(CYAN)------------------- ----------------- -------------------$(RESET)\n"
	@printf "$(CYAN)-------------------| COMPILING LIBFT |-------------------$(RESET)\n"
	@printf "$(CYAN)------------------- ----------------- -------------------$(RESET)\n"
	@make build -C $(LIB_PATH) --no-print-directory
endif

$(BUILD_PATH):
	@mkdir -p $(BUILD_PATH)${GLOBAL_PATH}

print:
ifeq ($(wildcard $(NAME)),)
	@printf "$(GREEN) ------------------------$(RESET)"
	@printf "$(GREEN)| Compiling Main Project |$(RESET)"
	@printf "$(GREEN)------------------------$(RESET)"
	@echo " "
endif

$(NAME): $(OBJS) $(HEADER_PATH)cub3d.h
	@printf "$(YELLOW)[Building]$(RESET) $(NAME)...\n"
	@$(CC) $(CFLAGS) $(OFLAGS) -o $(NAME) $(OBJS) -I$(HEADER_PATH) $(LIB_PATH)/$(LIB_NAME) $(MLX_BUILD_PATH)/$(MLX_NAME) $(LIBFLAGS) 
	@printf "$(UP)$(CUT)"
	@printf "$(GREEN)[Builded]$(RESET) $(NAME)...\n"
	@printf "$(CYAN)------ --------------------------------------------- ------$(RESET)\n"
	@printf "$(CYAN)------| MINISHELL executable was created successfully!! |------$(RESET)\n"
	@printf "$(CYAN)------ --------------------------------------------- ------$(RESET)\n"
	@echo " "

$(BUILD_PATH)%.o: $(SRC_PATH)%.c
	@printf "$(YELLOW)[Compiling]$(RESET) $(notdir $<)...\n"
	@$(CC) $(CFLAGS) $(OFLAGS) -c $< -o $@ -I$(HEADER_PATH)
	@printf "$(UP)$(CUT)"
	@printf "$(GREEN)[Compiled]$(RESET) $(notdir $<)...\n"


clean:
	@printf "$(RED)[Removing Objects...]$(RESET)\n"
	@make fclean -C $(LIB_PATH) --no-print-directory
	@rm -rf $(BUILD_PATH)
	@rm -rf $(VALGRIND_LOG)
	@rm -rf $(MLX_BUILD_PATH)
	@printf "$(GREEN)[Objects Removed]$(RESET)\n"

fclean: clean
	@printf "$(RED)[Removing $(notdir $(NAME))...]$(RESET)\n"
	@rm -rf $(NAME)
	@printf "$(GREEN)[$(notdir $(NAME)) Removed]$(RESET)\n"

re: fclean
	@make --no-print-directory

valgrind: all
	@valgrind --leak-check=full \
	--show-reachable=yes \
	--track-fds=yes \
	--show-leak-kinds=all -s \
	--track-origins=yes \
	--log-file=$(VALGRIND_LOG) \
	--suppressions=./MLX.supp \
	./$(NAME)
	@cat $(VALGRIND_LOG)

.PHONY: all clean fclean re valgrind libft mlx print
