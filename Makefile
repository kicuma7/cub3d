NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LIBFLAGS = -L./libs/libft -lft -Llibs/mlx -lmlx -Ilibs/mlx -lXext -lX11 -lm -lz

LIBFT_DIR = ./libs/libft
MLX_DIR = ./libs/mlx

SRC_DIR = ./src/

FILE =	main \

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILE)))

$(NAME):
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)

all: $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean:
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all
	make re -C $(MLX_DIR)

run: re
	$(CC) $(SRC) $(CFLAGS) $(LIBFLAGS) -o $(NAME)

.PHONY: all clean fclean
