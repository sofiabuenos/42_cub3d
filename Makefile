#COLORS
RESET	= \033[0m
BLACK	= \033[1;30m
RED	= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
MAGENTA	= \033[1;35m
CYAN	= \033[1;36m
WHITE	= \033[1;37m


NAME = cub3D
RM = rm -fr
UNAME = $(shell uname)
CFLAGS = -Wall -Wextra -Werror -g 
LFLAGS = -L ./$(LIBFTD) -lft -L ./$(FTPRINTFD) -lftprintf -I $(INC)
LIBFTD = libft
FTPRINTFD = ft_printf
INC = inc
SRCD = src/
OBJD = obj/

#check mac or linux
ifeq ($(UNAME), Darwin)
	MLXD = minilibx-mac
else
	MLXD = minilibx-linux
endif

#ajust flags according to operational system
ifeq ($(UNAME), Darwin) 
	CC = cc
	LFLAGS += -framework OpenGL -framework AppKit -L $(MLXD) -lmlx
else ifeq ($(UNAME), FreeBSD) 
	CC = clang
else 
	CC = cc
	LFLAGS += -L $(MLXD) -lmlx -Ilmlx -lXext -lX11 -lm
endif

SRCS = $(SRCD)main.c $(SRCD)error.c $(SRCD)parsing.c

OBJS = $(patsubst $(SRCD)%.c, $(OBJD)%.o, $(SRCS))

$(OBJD)%.o: $(SRCD)%.c
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

#RULES
all: $(NAME)

$(NAME): $(OBJS) $(OBJD) libft ft_printf minilibx
	echo "$(CYAN)Linking: $(RESET) $(CFLAGS) $(GREEN)*$(RESET)"
	$(CC) $(CFLAGS) $(LFLAGS) -I$(INC) $(OBJS) -o $(NAME)
	echo "$(GREEN)All files compiled!$(RESET)"


libft: $(LIBFTD)/libft.a
$(LIBFTD)/libft.a:
	make -s -C $(LIBFTD)
	make bonus -s -C $(LIBFTD)

ft_printf: $(FTPRINTFD)/libftprintf.a
$(FTPRINTFD)/libftprintf.a:
	make -s -C $(FTPRINTFD)

minilibx: $(MLXD)/libmlx.a
$(MLXD)/libmlx.a:
	make -s -C $(MLXD) 2>/dev/null


clean:
	make -s -C $(LIBFTD) clean
	make -s -C $(FTPRINTFD) clean
	make -s -C $(MLXD) 2>/dev/null clean

	echo "$(RED)Deleted: $(RESET) $(GREEN)$(OBJD)$(RESET)"
	$(RM) $(OBJD)

fclean: clean
	make fclean -s -C $(LIBFTD)
	make fclean -s -C $(FTPRINTFD)

	echo "$(RED)Deleted: $(RESET) $(GREEN)$(NAME)$(RESET)"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT: