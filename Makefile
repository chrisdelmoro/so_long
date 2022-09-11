NAME			= so_long
NAME_BONUS		= so_long_bonus

LIBFT_DIR		= ./libs/libft/
LIBFT 			= $(LIBFT_DIR)/libft.a
HEADER_LIBFT	= $(addprefix $(LIBFT_DIR), include/)

HEADER_DIR		= ./include/
HEADER			= so_long.h
HEADER_PATH		= $(addprefix $(HEADER_DIR), $(HEADER))

HEADER_DIR_BONUS	= ./bonus/include/
HEADER_BONUS		= so_long_bonus.h
HEADER_PATH			= $(addprefix $(HEADER_DIR_BONUS), $(HEADER_BONUS))

SRC_DIR			= ./src/
SRC				=	so_long.c \
					input_validation_utils.c \
					map_validation_utils.c \
					map_validation_utils_2.c \
					map_validation_utils_3.c \
					initialization_utils.c \
					close_utils.c \
					player_move_utils.c \
					hooks_utils.c \
					render_utils.c
SRC_PATH		= $(addprefix $(SRC_DIR), $(SRC))

SRC_DIR_BONUS	= ./bonus/src/
SRC_BONUS		=	so_long_bonus.c \
					input_validation_utils_bonus.c \
					map_validation_utils_bonus.c \
					map_validation_utils_2_bonus.c \
					map_validation_utils_3_bonus.c \
					initialization_utils_bonus.c \
					close_utils_bonus.c \
					player_move_utils_bonus.c \
					player_move_utils_bonus_2.c \
					hooks_utils_bonus.c \
					render_utils_bonus.c
SRC_PATH_BONUS	= $(addprefix $(SRC_DIR_BONUS), $(SRC_BONUS))

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
MLXFLAGS		= -lmlx -lX11 -lXext

BIN				= ./bin/
BINARY_OUT		= $(addprefix $(BIN), $(NAME))

BIN_BONUS			= ./bonus/bin/
BINARY_OUT_BONUS	= $(addprefix $(BIN_BONUS), $(NAME_BONUS))

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q --tool=memcheck

all: $(BINARY_OUT)

$(BINARY_OUT): $(SRC_PATH)
	@ $(MAKE) -C $(LIBFT_DIR)
	@ cp $(LIBFT) $(NAME)
	@ mkdir -p $(BIN)
	@ $(CC) $(CFLAGS) $(SRC_PATH) -I $(HEADER_DIR) -I $(HEADER_LIBFT) -L $(LIBFT_DIR) -lft $(MLXFLAGS) -o $(NAME)
	@ mv $(NAME) $(BIN)
	@ echo "$(NAME) compiled successfully!"

clean:
	@ $(MAKE) clean -C $(LIBFT_DIR)
	@ echo "libft object files erased successfully!"

fclean: clean
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ rm -f $(BINARY_OUT)
	@ rm -rf $(BIN)
	@ echo "$(NAME) binaries erased successfully!"
	@ rm -f $(BINARY_OUT_BONUS)
	@ rm -rf $(BIN_BONUS)
	@ echo "$(NAME_BONUS) binaries erased successfully!"

bonus: $(BINARY_OUT_BONUS)

$(BINARY_OUT_BONUS): $(SRC_PATH_BONUS)
	@ $(MAKE) -C $(LIBFT_DIR)
	@ cp $(LIBFT) $(NAME_BONUS)
	@ mkdir -p $(BIN_BONUS)
	@ $(CC) $(CFLAGS) $(SRC_PATH_BONUS) -I $(HEADER_DIR_BONUS) -I $(HEADER_LIBFT) -L $(LIBFT_DIR) -lft $(MLXFLAGS) -o $(NAME_BONUS)
	@ mv $(NAME_BONUS) $(BIN_BONUS)
	@ echo "$(NAME_BONUS) compiled successfully!"

valgrind:
	@ $(MAKE) -C $(LIBFT_DIR)
	@ cp $(LIBFT) $(NAME)
	@ mkdir -p $(BIN)
	@ $(CC) $(CFLAGS) $(SRC_PATH) -I $(HEADER_DIR) -I $(HEADER_LIBFT) -L $(LIBFT_DIR) -lft $(MLXFLAGS) -g -o $(NAME)
	@ mv $(NAME) $(BIN)
	@ echo "$(NAME) compiled successfully!"

valgrind_bonus:
	@ $(MAKE) -C $(LIBFT_DIR)
	@ cp $(LIBFT) $(NAME_BONUS)
	@ mkdir -p $(BIN_BONUS)
	@ $(CC) $(CFLAGS) $(SRC_PATH_BONUS) -I $(HEADER_DIR_BONUS) -I $(HEADER_LIBFT) -L $(LIBFT_DIR) -lft $(MLXFLAGS) -g -o $(NAME_BONUS)
	@ mv $(NAME_BONUS) $(BIN_BONUS)
	@ echo "$(NAME_BONUS) compiled successfully!"

re: fclean all

.PHONY: all clean fclean re
