#include <unistd.h>
#include "game.h"
#include "renderer.h"
#include "key_manager.h"
#include <string.h>


void addChar(char *s, char c) {

  	// Move pointer to the end
    while (*s++);
  
    // Append the new character
    *(s - 1) = c;
  
    // Add null terminator to mark new end
    *s = '\0';
}


void input_system(t_mlx *mlx)
{
	int             i;
    t_rect          dst_rect;
    t_rect          src_rect;
    t_image_data    *src;
	char *input;

    i = 0;
	input = NULL;
    while (i < mlx->game->total_entities)
    {
        if (!mlx->game->entities[i]->text_input ||
            !mlx->game->entities[i]->transform)
		{
            i++;
            continue ;
        }
		for(int j = 65; j < 122; j++)
		{
			if (mlx->keys[j])
			{
				addChar(mlx->game->entities[i]->text_input->txt, j);		
				keyup(j, mlx);

			}
		}
		for(int c = 0; c < strlen(mlx->game->entities[i]->text_input->txt); c++)
		{
			char letter = mlx->game->entities[i]->text_input->txt[c];
			src = &mlx->game->font[1];
			dst_rect.x = (int)mlx->game->entities[i]->transform->pos_x + 12 * c;
			dst_rect.y = (int)mlx->game->entities[i]->transform->pos_y;
			dst_rect.h = 16;
			dst_rect.w = 8;
            paint_image(mlx, src, dst_rect);
		}
		i++;
    }
}