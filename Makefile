RM = rm -rf
NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LIBS_FLAGS = -lft -L./libs/libft -lmlx -L./libs/mlx -Imlx -lXext -lX11 -lm -lz

SRC_F = ./src/

OBJ_F = ./.obj/

FILES = main \
		tmp_file \
		free \
		image

SRCS = $(addprefix $(SRC_F), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJ_F), $(addsuffix .o, $(FILES)))

$(NAME): $(OBJS)
	make -C libs/mlx
	make -C libs/libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBS_FLAGS) -o $(NAME)

$(OBJ_F)%.o: $(SRC_F)%.c
	mkdir -p $(OBJ_F)
	$(CC) $(CFLAGS) $(LIBS_FLAGS) -c $< -o $@

all: $(NAME)

clean:
	make clean -C libs/mlx
	make clean -C libs/libft
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libs/libft
	$(RM) $(NAME)

re: mlx_re fclean all

mlx_re:
	make re -C libs/mlx

run: all
	valgrind ./cub3d assets/maps/map.cub

.PHONY: all clean fclean re


### 🟣 macOS-specific flags (MiniLibX OpenGL + AppKit)
MAC_LIBS_FLAGS = -framework OpenGL -framework AppKit \
				-I./libs/mlx_opengl -L./libs/mlx_opengl -lmlx \
				-I./libs/libft -L./libs/libft -lft

### Compilar Cub3D no macOS
mac: $(OBJS)
	make -C libs/mlx_opengl
	make -C libs/libft
	$(CC) $(CFLAGS) $(OBJS) $(MAC_LIBS_FLAGS) -o $(NAME)

### Compilar arquivos .c para .o no macOS
$(OBJ_F)%.o: $(SRC_F)%.c
	mkdir -p $(OBJ_F)
	$(CC) $(CFLAGS) -I./libs/mlx -I./libs/libft -c $< -o $@
