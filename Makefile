NAME = cub3D
CC = cc

CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lSDL2 -lm

INCLUDE = -Iinclude -Ilibft/include -IMacroLibX/includes

SRC = 	src/main.c \
		src/engine/hooks/key_hook.c \
		src/engine/hooks/loop_hook.c \
		src/engine/hooks/window_hook.c \
		src/engine/engine.c \
		src/engine/engine_hooks.c \
		src/engine/engine_map.c \
		src/engine/engine_raycast.c \
		src/engine/engine_raycast_utils.c \
		src/engine/engine_texture.c \
		src/engine/engine_wall.c \
		src/engine/renderer.c \
		src/engine/renderer_draw.c \
		src/engine/renderer_minimap.c \
		src/cfg/cfg_parse.c \
		src/cfg/cfg.c \
		src/cfg/cfg_checks.c \
		src/cfg/cfg_parse_line.c \
		src/cfg/cfg_map_translate.c \
		src/cfg/cfg_parse_color.c \
		src/cfg/state.c \
		src/math/vec3.c \
		src/math/vec2.c \
		src/math/conv.c \

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a
MLX = MacroLibX/libmlx.so

COLOUR_GREEN=\033[0;32m
COLOUR_GRAY=\033[0;90m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

ifdef DEBUG
	CFLAGS = -Wall -Wextra -g -D CUB_DEBUG=1
endif
ifdef OPT
	CFLAGS += -O2 -flto
endif
ifdef CHECK
	CFLAGS += -fsanitize=address
endif

ifndef NO_SILENT
.SILENT:
endif

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $@  $(LDFLAGS) $(INCLUDE)
	@echo "$(COLOUR_GREEN)Compiled:$(COLOUR_END) $(NAME)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
	@echo "$(COLOUR_BLUE)Compiled:$(COLOUR_END) $< $(COLOUR_GRAY)$(CC) $(CFLAGS)$(COLOUR_END)"

$(LIBFT):
	@echo "$(COLOUR_GREEN)Compiling libft$(COLOUR_END)"
	@make -j8 -C libft/ all --no-print-directory

$(MLX):
	@echo "$(COLOUR_GREEN)Compiling MLX$(COLOUR_END)"
	@make -j8 -C MacroLibX --no-print-directory

clean:
	@rm -f $(OBJ)
	@make -C MacroLibX clean --no-print-directory
	@make -C libft clean --no-print-directory

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@rm -f $(MLX)

re : fclean all

set_bonus_flag:
	$(eval CFLAGS += -D CUB_BONUS=1)

bonus: set_bonus_flag all
