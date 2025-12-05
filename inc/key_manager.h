#ifndef KEYS_H
#define KEYS_H

#include "game.h"

#define MAX_KEYS 65536

typedef enum 	e_key 
{
	W_KEY = 119,
	S_KEY = 115,
	D_KEY = 100,
	A_KEY = 97
}				t_key;

int		keydown(int keycode, t_mlx *mlx);
int		keyup(int keycode, t_mlx *mlx);
void	init_keys(t_mlx *mlx);


#endif