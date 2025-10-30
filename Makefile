# **************************************************************************** #
#                                   Makefile                                   #
# **************************************************************************** #

NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I. -D BUFFER_SIZE=64
RM			= rm -f

# --------------------------------------------------------------------------- #
# Files and directories
# --------------------------------------------------------------------------- #

SRC_DIR			= .
GNL_DIR			= GNL
MAPCHECK_DIR	= map_validation
MAP_DIR			= maps

SRC			= $(SRC_DIR)/main.c \
			  $(SRC_DIR)/read_map.c \
			  $(SRC_DIR)/utils.c \
			  $(GNL_DIR)/get_next_line.c \
			  $(GNL_DIR)/get_next_line_utils.c \
			  $(MAPCHECK_DIR)/map_gardian.c \
			  $(MAPCHECK_DIR)/map_gardian_helpers.c \

OBJ			= $(SRC:.c=.o)

MAP_FILE	= $(MAP_DIR)/map_invalid.ber

# --------------------------------------------------------------------------- #
# Rules
# --------------------------------------------------------------------------- #

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "✅ Build complete: $(NAME)"

%.o: %.c so_long.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

clean:
	@$(RM) $(OBJ)
	@echo "🧹 Object files removed."

fclean: clean
	@$(RM) $(NAME)
	@echo "🗑️  Executable removed."

re: fclean all

ucheck: all
	@echo "🚀 Running ucheck test..."
	@./so_long $(MAP_FILE)

.PHONY: all clean fclean re ucheck
# **************************************************************************** #
