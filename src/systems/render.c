#include <unistd.h>
#include "game.h"
#include "renderer.h"

static int k = 0;

void render_system(t_mlx *mlx)
{
    int             i;
    t_rect          dst_rect;
    t_rect          src_rect;
    t_image_data    *src;

    i = 0;
    while (i < mlx->game->total_entities)
    {
        if (!mlx->game->entities[i]->sprite ||
            !mlx->game->entities[i]->transform)
        {
            i++;
            continue ;
        }
        src = mlx->game->entities[i]->sprite->sprite_data;

        dst_rect.x = (int)mlx->game->entities[i]->transform->pos_x;
        dst_rect.y = (int)mlx->game->entities[i]->transform->pos_y;
        dst_rect.h = mlx->game->entities[i]->sprite->sprite_data->height;
        dst_rect.w = mlx->game->entities[i]->sprite->sprite_data->width;

        if (mlx->game->entities[i]->sprite->has_anim)
        {
            src_rect.x = ((mlx->game->entities[i]->sprite->tile_size_x) * (k % mlx->game->entities[i]->sprite->num_frames));
            src_rect.y = 0;
            src_rect.w = mlx->game->entities[i]->sprite->tile_size_x; //100; //src_rect.w / mlx->game->entities[i]->sprite->x_size;
            src_rect.h = mlx->game->entities[i]->sprite->tile_size_y; //100; //src_rect.w / mlx->game->entities[i]->sprite->x_size;

            paint_anim_image(mlx, src, dst_rect, src_rect);
            k++;
        }
        else
            paint_image(mlx, src, dst_rect);
        i++;

    }
}
