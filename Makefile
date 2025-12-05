NAME := cub3d


all: main.c
	cc main.c -Lminilibx-linux -lmlx_Linux -lz -lXext -lm -lX11 -g -o $(NAME)
