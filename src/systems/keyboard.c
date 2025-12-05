#include "game.h"
#include "key_manager.h"

void init_keys(t_mlx *mlx)
{
    int i;

    i = 0;
    while (i < 65536)
    {
        mlx->keys[i] = false;
        i++;
    }
}

void keyboard_system(t_mlx *mlx)
{
    int i;

    i = 0;
    t_entity *e = mlx->game->entities[i];
    while (i < mlx->game->total_entities)
    {
        if (mlx->game->entities[i]->keyboard &&
            mlx->game->entities[i]->velocity)
        {
            if (mlx->keys[W_KEY])
                mlx->game->entities[i]->velocity->vel_y = 2;
            if (!mlx->keys[W_KEY])
                mlx->game->entities[i]->velocity->vel_y = 0;
            if (mlx->keys[S_KEY])
                mlx->game->entities[i]->velocity->vel_y = 2;
            if (!mlx->keys[S_KEY])
                mlx->game->entities[i]->velocity->vel_y = 0;
            if (mlx->keys[A_KEY])
                mlx->game->entities[i]->velocity->vel_x = 2;
            if (!mlx->keys[A_KEY])
                mlx->game->entities[i]->velocity->vel_x = 0;
            if (mlx->keys[D_KEY])
                mlx->game->entities[i]->velocity->vel_x = 2;
            if (!mlx->keys[D_KEY])
                mlx->game->entities[i]->velocity->vel_x = 0;
        }
        i++;
    }
}
