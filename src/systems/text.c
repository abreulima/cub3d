#include <unistd.h>
#include "game.h"
#include "renderer.h"
#include <string.h>

void text_system(t_mlx *mlx)
{
	int             i;
    t_rect          dst_rect;
    t_rect          src_rect;
    t_image_data    *src;

    i = 0;
    while (i < mlx->game->total_entities)
    {
        if (!mlx->game->entities[i]->text ||
            !mlx->game->entities[i]->transform)
        {
            i++;
            continue ;
        }
		for(int c = 0; c < strlen(mlx->game->entities[i]->text->txt); c++)
		{
			char letter = mlx->game->entities[i]->text->txt[c];
			src = &mlx->game->font[letter - 65];
	
			dst_rect.x = (int)mlx->game->entities[i]->transform->pos_x + 12*c;
			dst_rect.y = (int)mlx->game->entities[i]->transform->pos_y;
			dst_rect.h = 18;
			dst_rect.w = 10;
			paint_image(mlx, src, dst_rect);
		}
		i++;
    }
}