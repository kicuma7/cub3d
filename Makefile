# Makefile for cub3d on macOS M1

# Commands
RM = rm -rf
NAME = cub3d
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -g3 -D__APPLE__

# Library flags
# -lft: Link with libft
# -L./libs/libft: Specify the path to libft
# -lmlx: Link with minilibx
# -L./libs/mlx: Specify the path to minilibx
# -framework OpenGL -framework AppKit: Essential frameworks for minilibx on macOS
LIBS_FLAGS = -lft -L./libs/libft -lmlx -L./libs/mlx -framework OpenGL -framework AppKit -lm

# Source and object file directories
SRC_F = ./src/
OBJ_F = ./.obj/

# Source files (add more if needed)
FILES = main \
        tmp_file \
        free \
		init \
		player \
		aux_func/pixel_put \
		aux_func/draw_square \
		2dmap/map \
		2dmap/player \
		2dmap/2d_window

# Generate full paths for source and object files
SRCS = $(addprefix $(SRC_F), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJ_F), $(addsuffix .o, $(FILES)))

# Default target: builds the cub3d executable
all: $(NAME)

# Rule to build the cub3d executable
$(NAME): $(OBJS)
	@echo "--- Building Minilibx ---"
	$(MAKE) -C libs/mlx
	@echo "--- Building Libft ---"
	$(MAKE) -C libs/libft
	@echo "--- Linking cub3d ---"
	$(CC) $(CFLAGS) $(OBJS) $(LIBS_FLAGS) -o $(NAME)
	@echo "--- cub3d built successfully! ---"

# Rule to compile source files into object files
$(OBJ_F)%.o: $(SRC_F)%.c
	@mkdir -p $(OBJ_F)
	@mkdir -p $(OBJ_F)aux_func
	@mkdir -p $(OBJ_F)2dmap
	$(CC) $(CFLAGS) -c $< -o $@

# Cleans up object files and library builds
clean:
	@echo "--- Cleaning Minilibx ---"
	$(MAKE) clean -C libs/mlx
	@echo "--- Cleaning Libft ---"
	$(MAKE) clean -C libs/libft
	@echo "--- Cleaning object files ---"
	$(RM) $(OBJS)
	@echo "--- Clean complete ---"

# Full clean: removes executable and all build artifacts
fclean: clean
	@echo "--- Full clean: removing cub3d executable ---"
	$(MAKE) fclean -C libs/libft
	$(RM) $(NAME)
	@echo "--- Full clean complete ---"

# Rebuilds everything
re: fclean all

# Rebuilds Minilibx only
mlx_re:
	@echo "--- Rebuilding Minilibx ---"
	$(MAKE) re -C libs/mlx
	@echo "--- Minilibx rebuild complete ---"

# Runs the program with Valgrind (Valgrind is not directly available on macOS M1)
# For macOS M1, you'd typically use Instruments or dtrace for profiling/memory analysis.
run: all
	@echo "--- Valgrind is not available on macOS M1 for direct use like this. ---"
	@echo "--- Consider using Instruments for profiling or memory analysis. ---"
	# valgrind ./cub3d assets/maps/map.cub

# Phony targets to prevent conflicts with file names
.PHONY: all clean fclean re mlx_re run
