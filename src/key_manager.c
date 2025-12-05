#include "game.h"

int    keydown(int keycode, t_mlx *mlx)
{
    mlx->keys[keycode] = true;
	return (0);
}

int    keyup(int keycode, t_mlx *mlx)
{
    mlx->keys[keycode] = false;
	return (0);
}