NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LIBS_FLAGS = -lft -L./libs/libft -lmlx -L./libs/mlx -Imlx -lXext -lX11 -lm -lz

SRC_F = ./src/

OBJ_F = ./.obj/

FILES = main

SRCS = $(addprefix $(SRC_F), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJ_F), $(addsuffix .o, $(FILES)))

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS_FLAGS) -o $(NAME)

$(OBJ_F)%.o: $(SRC_F)%.c
	mkdir -p $(OBJ_F)
	$(CC) $(CFLAGS) $(LIBS_FLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
