CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LIBFLAGS = -lm -L./library/libft/ -lft -L./library/mlx/ -lmlx -Imlx -lXext -lX11 -lz

<<<<<<< HEAD
NAME = cub3d
=======
SRC_F = ./src/
VALIDATION_F = $(SRC_F)validation/
>>>>>>> ab93960d3a46b472d4c671b8ed840835f946f38a

SRC_F = ./source/
OBJ_F = ./.objs/

<<<<<<< HEAD
DIR_LIST = $(OBJ_F) \
			$(OBJ_F)aux_func \
			$(OBJ_F)minimap

FILE_NAME =	cub \
			player \
			init \
			free \
			ray \
			ray_aux \
			world3d \
			aux_func/pixel_put \
			aux_func/draw_line \
			aux_func/draw_square \
			aux_func/clear_all_image \
			minimap/minimap \

SRCS = $(addprefix $(SRC_F), $(addsuffix .c, $(FILE_NAME)))
OBJS = $(addprefix $(OBJ_F), $(addsuffix .o, $(FILE_NAME)))
=======
FILES = main \
		free \
		image \
		draw_map2d \
		player2d \
		player_vision

VALIDATION_SRC = $(wildcard $(VALIDATION_F)*.c)
VALIDATION_OBJ = $(patsubst $(VALIDATION_F)%.c, $(OBJ_F)validation/%.o, $(VALIDATION_SRC))

SRCS = $(addprefix $(SRC_F), $(addsuffix .c, $(FILES))) $(VALIDATION_SRC)
OBJS = $(addprefix $(OBJ_F), $(addsuffix .o, $(FILES))) $(VALIDATION_OBJ)
>>>>>>> ab93960d3a46b472d4c671b8ed840835f946f38a

$(NAME): $(OBJS)
	make -C ./library/libft/
	make -C ./library/mlx
	$(CC) $(CFLAGS) $^ $(LIBFLAGS) -o $(NAME)

<<<<<<< HEAD
$(OBJ_F)%.o : $(SRC_F)%.c
	@mkdir -p $(DIR_LIST)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean :
	make clean -C ./library/libft/
	make clean -C ./library/mlx/
	rm -rf $(OBJS)
=======
$(OBJ_F)%.o: $(SRC_F)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(LIBS_FLAGS) -c $< -o $@

$(OBJ_F)validation/%.o: $(VALIDATION_F)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(LIBS_FLAGS) -c $< -o $@

all: $(NAME)

clean:
	make clean -C libs/mlx
	make clean -C libs/libft
	$(RM) $(OBJS)
	$(RM) $(OBJ_F)validation
>>>>>>> ab93960d3a46b472d4c671b8ed840835f946f38a

fclean: clean
	make fclean -C ./library/libft/
	rm -rf $(NAME)

re: fclean all

<<<<<<< HEAD
.PHONY: all clean fclean
=======
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
	./cub3d

### Compilar arquivos .c para .o no macOS
$(OBJ_F)%.o: $(SRC_F)%.c
	mkdir -p $(OBJ_F)
	$(CC) $(CFLAGS) -I./libs/mlx -I./libs/libft -c $< -o $@

re_mac:
	make clean -C libs/mlx_opengl
	make fclean -C libs/libft
	$(RM) $(OBJS) $(NAME)
	make mac
>>>>>>> ab93960d3a46b472d4c671b8ed840835f946f38a
