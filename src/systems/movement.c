#include "game.h"

void movement_system(t_mlx *mlx)
{
    int i;

    i = 0;
    while (i < mlx->game->total_entities)
    {
        if (mlx->game->entities[i]->transform && mlx->game->entities[i]->velocity)
        {
			mlx->game->entities[i]->transform->pos_x += mlx->game->entities[i]->velocity->vel_x;
			mlx->game->entities[i]->transform->pos_y += mlx->game->entities[i]->velocity->vel_y;
        }
        i++;
    }
}
