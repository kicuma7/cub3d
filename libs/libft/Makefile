# --- CORES NORMAIS ---
BLACK		= \033[0;30m
RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
MAGENTA		= \033[0;35m
CYAN		= \033[0;36m
WHITE		= \033[0;37m

# --- CORES EM NEGRITO ---
B_BLACK		= \033[1;30m
B_RED		= \033[1;31m
B_GREEN		= \033[1;32m
B_YELLOW	= \033[1;33m
B_BLUE		= \033[1;34m
B_MAGENTA	= \033[1;35m
B_CYAN		= \033[1;36m
B_WHITE		= \033[1;37m

# --- CÓDIGOS ESPECIAIS ---
RESET		= \033[0m
BOLD		= \033[1m
UNDERLINE	= \033[4m
REVERSE		= \033[7m


CC			= cc
RM			= rm -f
AR			= ar rc
RN			= ranlib

CFLAGS 		= -Wall -Wextra -Werror

NAME		= libft.a

SRC_F = ./src/
OBJ_F = ./.obj/

FILES = ft_atoi \
			ft_bzero \
			ft_calloc \
			ft_isalnum \
			ft_isalpha \
			ft_isascii \
			ft_isdigit \
			ft_isprint \
			ft_itoa \
			ft_memchr \
			ft_memcmp \
			ft_memcpy \
			ft_memmove \
			ft_memset \
			ft_putchar_fd \
			ft_putendl_fd \
			ft_putnbr_fd \
			ft_putstr_fd \
			ft_split \
			ft_strchr \
			ft_strdup \
			ft_striteri \
			ft_strjoin \
			ft_strlcat \
			ft_strlcpy \
			ft_strlen \
			ft_strmapi \
			ft_strncmp \
			ft_strnstr \
			ft_strrchr \
			ft_strtrim \
			ft_substr \
			ft_strncpy \
			ft_tolower \
			ft_toupper \
			ft_lstnew \
			ft_lstadd_front \
			ft_lstsize \
			ft_lstlast \
			ft_lstadd_back \
			ft_lstdelone \
			ft_lstclear \
			ft_lstiter \
			ft_lstmap \
			get_next_line \
			get_next_line_utils \

SRCS		= $(addprefix $(SRC_F), $(addsuffix .c, $(FILES)))
OBJS		= $(addprefix $(OBJ_F), $(addsuffix .o, $(FILES)))

$(OBJ_F)%.o: $(SRC_F)%.c
			@mkdir -p $(OBJ_F)
			@$(CC) $(CFLAGS) -c $< -o $@
			@clear
			@echo "$(B_WHITE)Building $(B_BLUE)$< $(B_WHITE)→ $(B_GREEN)$@$(RESET)"

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS)
			@echo "$(B_WHITE)Linking $(B_BLUE) Objs to $(B_GREEN)$(NAME)$(RESET)"
			@$(RN) $(NAME)
			@echo "$(B_WHITE)Finished Building $(B_GREEN)$(NAME)$(RESET)"

all:		$(NAME)

clean:
			@$(RM) $(OBJS)
			@echo "$(B_WHITE)Objects Files $(B_RED)DELETED $(RESET)"

fclean:		clean
			@$(RM) $(NAME)
			@echo "$(B_WHITE)LIB File $(B_RED)DELETED $(RESET)"

re:			fclean all

.PHONY:		all clean fclean re
