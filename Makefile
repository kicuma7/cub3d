CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LIBFLAGS = -lm -L./library/libft/ -lft -L./library/mlx/ -lmlx -Imlx -lXext -lX11 -lz

NAME = cub3d

SRC_F = ./source/
OBJ_F = ./.objs/

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

$(NAME): $(OBJS)
	make -C ./library/libft/
	make -C ./library/mlx
	$(CC) $(CFLAGS) $^ $(LIBFLAGS) -o $(NAME)

$(OBJ_F)%.o : $(SRC_F)%.c
	@mkdir -p $(DIR_LIST)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean :
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

.PHONY: all clean fclean
