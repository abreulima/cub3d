#include <unistd.h>
#include "game.h"

void render_system(t_mlx *mlx)
{
    int i;

    i = 0;
    mlx_clear_window(mlx->mlx, mlx->window);
    while (i < mlx->game->total_entities)
    {
        if (mlx->game->entities[i]->sprite   &&
            mlx->game->entities[i]->transform)
        {
            mlx_put_image_to_window(mlx->mlx, 
                mlx->window, 
                mlx->game->entities[i]->sprite->sprite_data->ptr, 
                mlx->game->entities[i]->transform->pos_x, 
                mlx->game->entities[i]->transform->pos_y);
        }
        i++;
    }
    usleep(16000);
}