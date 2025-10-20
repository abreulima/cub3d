all: main.c
	cc -Iminilibx-linux ft_split.c main.c  -Lminilibx-linux -lX11 -lXext -lmlx_Linux
	
