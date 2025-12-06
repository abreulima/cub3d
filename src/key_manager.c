#include "game.h"
#include "key_manager.h"

int    keydown(int keycode, t_mlx *mlx)
{
    mlx->keys[keycode] = true;
	if(keycode == ESC_KEY)
		mlx_destroy_window(mlx->mlx, mlx->window);
	return (0);
}

int    keyup(int keycode, t_mlx *mlx)
{
    mlx->keys[keycode] = false;
	return (0);
}