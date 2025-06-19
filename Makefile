CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LIBFLAGS = -lm -L./library/libft/ -lft -L./library/mlx/ -lmlx -Imlx -lXext -lX11 -lz

NAME = cub3d

SRC_F = ./source/
OBJ_F = ./.objs/

FILE_NAME =	cub \

SRCS = $(addprefix $(SRC_F), $(addsuffix .c, $(FILE_NAME)))
OBJS = $(addprefix $(OBJ_F), $(addsuffix .o, $(FILE_NAME)))

$(NAME): $(OBJS)
	make -C ./library/libft/
	make -C ./library/mlx
	$(CC) $(CFLAGS) $^ $(LIBFLAGS) -o $(NAME)

$(OBJ_F)%.o : $(SRC_F)%.c
	@mkdir -p $(OBJ_F)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)
