NAME := minirt
NAME_B := minirt_bonus
CC := clang
OBJ_DIR := obj

LIBFT_DIR := libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a

MLX_DIR := mlx
MLX_LIB := $(MLX_DIR)/libmlx.a

CFLAGS := -Wall -Wextra -Werror -g
CPPFLAGS := -I$(LIBFT_DIR) -MMD
LDFLAGS := -L$(LIBFT_DIR)
LDLIBS := -lft
#SRC_COMMON := 	get_next_line.c		get_next_line_utils.c	common_funcs0.c		check_map0.c	\
				check_map1.c		map_init0.c				load_images.c		main_logick0.c	\
				main_logick1.c		map_init1.c


SRC_COMMON := 	get_next_line.c		get_next_line_utils.c	ft_split_new.c		ft_strjoin3.c	\
				common_funcs0.c		common_funcs1.c			common_funcs2.c		common_funcs3.c	\
				parse_scene00.c		parse_scene01.c			parse_scene02.c		parse_scene03.c	\
				parse_scene04.c		parse_scene05.c			parse_scene06.c		parse_scene07.c	\
				parse_scene08.c
				
SRC := 			$(SRC_COMMON)		main.c

#SRC_B :=		$(SRC_COMMON)		bonus0.c	bonus1.c	bonus2.c	main_bonus.c


OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJ_B := $(SRC_B:%.c=$(OBJ_DIR)/%.o)

DEP := $(OBJ:.o=.d)
DEP_B := $(OBJ_B:.o=.d)

.PHONY: all clean fclean re bonus libft1

all:	libft1 mlx1 $(NAME)
bonus:	libft1 mlx1 $(NAME_B)

$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME_B): $(LIBFT_LIB) $(MLX_LIB) $(OBJ_B)
	$(CC) $(LDFLAGS) $(OBJ_B) $(LDLIBS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS)  -c $< -o $@

$(LIBFT_LIB): libft1

libft1:
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB): mlx1

mlx1:
	@$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR):
	mkdir -p $@

-include $(DEP) $(DEP_B)

clean:
	@rm -f $(OBJ) $(DEP) $(OBJ_B) $(DEP_B)
	make clean -C libft

fclean: clean
	@rm -f $(NAME) $(NAME_B)
	make fclean -C libft

re: fclean all
