# **************************************************************************** #
#                                   Makefile                                   #
# **************************************************************************** #

# === Project Information ==================================================== #

NAME		= so_long

# === Compiler Settings ====================================================== #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I.
RM			= rm -f

# === Directories ============================================================ #

SRC_DIR			= .
GNL_DIR			= GNL
MAPCHECK_DIR	= map_validation
MAP_DIR			= maps
OBJ_DIR			= obj

# === Source Files =========================================================== #

SRC			= $(SRC_DIR)/main.c \
			  $(SRC_DIR)/read_map.c \
			  $(SRC_DIR)/utils.c \
			  $(GNL_DIR)/get_next_line.c \
			  $(GNL_DIR)/get_next_line_utils.c \
			  $(MAPCHECK_DIR)/map_gardian.c \
			  $(MAPCHECK_DIR)/map_gardian_helpers.c

OBJ			= $(SRC:%.c=$(OBJ_DIR)/%.o)

# === Default Target ========================================================= #

all: $(NAME)

# === Compilation Rules ====================================================== #

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "✅ Build complete: $(NAME)"

# Create object directory if it doesn't exist
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# === Cleaning Rules ========================================================= #

clean:
	@$(RM) $(OBJ)
	@$(RM) -r $(OBJ_DIR)
	@echo "🧹 Object files removed."

fclean: clean
	@$(RM) $(NAME)
	@echo "🗑️  Executable removed."

re: fclean all

# === Utility Rule: ucheck (for testing) ==================================== #

MAP_FILE	= $(MAP_DIR)/map_invalid.ber

ucheck: all
	@echo "🚀 Running ucheck test..."
	@./so_long $(MAP_FILE)

# === Phony Targets ========================================================== #

.PHONY: all clean fclean re ucheck
# **************************************************************************** #
#                                End of Makefile                               #
# **************************************************************************** #