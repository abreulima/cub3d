#include <unistd.h>
#include "game.h"
#include "renderer.h"

static int k = 0;

void render_system(t_mlx *mlx)
{
    int             i;
    t_rect          src_rect;
    t_rect          src_dst;
    t_image_data    *src;

    clear_window(&mlx->frame);
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
        src_dst.x = (int)mlx->game->entities[i]->transform->pos_x;
        src_dst.y = (int)mlx->game->entities[i]->transform->pos_y;

        if (k > 47)
            k = 0;

        src_rect.x = 200;
        src_rect.y = 0;
        src_rect.w = 200;
        src_rect.h = 160;

        k++;
        //paint_anim_image(mlx, src, src_dst, src_rect);
        paint_image(mlx, src, src_rect);
        i++;

    }
    mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->frame.ptr, 0, 0);
    usleep(16000);
}
