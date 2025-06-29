CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
# As flags de linkagem precisam ser ajustadas para o macOS
# -lmlx não é suficiente, você precisa linkar com os frameworks do sistema.
# O IOKit é necessário para o mouse e teclado.
LIBFLAGS = -L./library/libft/ -lft -L./library/mlx/ -lmlx -framework OpenGL -framework AppKit

NAME = cub3d

SRC_F = ./source/
OBJ_F = ./.objs/

DIR_LIST = $(OBJ_F) \
            $(OBJ_F)aux_func \
            $(OBJ_F)minimap

FILE_NAME = cub \
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

# Regra principal para construir o executável
$(NAME): $(OBJS)
	@make -C ./library/libft/
	@make -C ./library/mlx
	$(CC) $(CFLAGS) $^ $(LIBFLAGS) -o $(NAME)

# Regra para compilar os arquivos .c em .o
$(OBJ_F)%.o : $(SRC_F)%.c
	@mkdir -p $(DIR_LIST)
	$(CC) $(CFLAGS) -c $< -o $@

# Alvos
all: $(NAME)

clean :
	@rm -rf $(OBJS)
	@make -C ./library/libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C ./library/libft/ fclean

re: fclean all

.PHONY: all clean fclean re
