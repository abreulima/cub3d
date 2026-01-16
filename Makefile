NAME := cub3d
LDFLAGS := -Iinc

SRCS := src/main.c
SRCS += src/image_manager.c
SRCS += src/key_manager.c
SRCS += src/renderer/renderer.c
SRCS += src/entities/entity_manager.c
SRCS += src/entities/add_input.c
SRCS += src/entities/add_player.c
SRCS += src/entities/add_enemy.c
SRCS += src/entities/add_crosshair.c
SRCS += src/systems/keyboard.c
SRCS += src/systems/movement.c
SRCS += src/systems/render.c
SRCS += src/systems/text.c


all: $(SRCS)
	cc $(LDFLAGS) $^ -O3 -Lminilibx-linux -lmlx_Linux -lz -lXext -lm -lX11 -g -o $(NAME)
