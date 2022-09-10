NAME			= so_long

LIBFT_DIR		= ./libs/libft/
LIBFT 			= $(LIBFT_DIR)/libft.a
HEADER_LIBFT	= $(addprefix $(LIBFT_DIR), include/)

HEADER_DIR		= ./include/
HEADER			= so_long.h
HEADER_PATH		= $(addprefix $(HEADER_DIR), $(HEADER))

SRC_DIR			= ./src/
SRC				= 	so_long.c \
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

OBJ				= $(SRC_PATH:.c=.o)

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
MLXFLAGS		= -lmlx -lX11 -lXext

BIN				= ./bin
BINARY_OUT		= $(addprefix $(BIN), $(NAME))

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q --tool=memcheck

all: $(NAME)

$(NAME): $(SRC_PATH)
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

valgrind:
	@ $(MAKE) -C $(LIBFT_DIR)
	@ cp $(LIBFT) $(NAME)
	@ mkdir -p $(BIN)
	@ $(CC) $(CFLAGS) $(SRC_PATH) -I $(HEADER_DIR) -I $(HEADER_LIBFT) -L $(LIBFT_DIR) -lft $(MLXFLAGS) -g -o $(NAME)
	@ mv $(NAME) $(BIN)
	@ echo "$(NAME) compiled successfully!"

re: fclean all

.PHONY: all clean fclean re
