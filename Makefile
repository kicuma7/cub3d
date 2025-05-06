RM = rm -rf
NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LIBS_FLAGS = -lft -L./libs/libft -lmlx -L./libs/mlx -Imlx -lXext -lX11 -lm -lz

SRC_F = ./src/
VALIDATION_F = $(SRC_F)validation/

OBJ_F = ./.obj/

FILES = main \
        tmp_file \
        free

VALIDATION_SRC = $(wildcard $(VALIDATION_F)*.c)
VALIDATION_OBJ = $(patsubst $(VALIDATION_F)%.c, $(OBJ_F)validation/%.o, $(VALIDATION_SRC))

SRCS = $(addprefix $(SRC_F), $(addsuffix .c, $(FILES))) $(VALIDATION_SRC)
OBJS = $(addprefix $(OBJ_F), $(addsuffix .o, $(FILES))) $(VALIDATION_OBJ)

$(NAME): $(OBJS)
	make -C libs/mlx
	make -C libs/libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBS_FLAGS) -o $(NAME)

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

fclean: clean
	make fclean -C libs/libft
	$(RM) $(NAME)

re: mlx_re fclean all

mlx_re:
	make re -C libs/mlx

run: all
	valgrind ./cub3d assets/maps/map.cub

.PHONY: all clean fclean re