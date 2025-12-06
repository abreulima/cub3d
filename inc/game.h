#ifndef GAME_H
# define GAME_H

#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "components.h"
#include "image_manager.h"
#include "entity.h"

typedef struct      s_game
{
    int             total_entities;
    t_entity        *entities[1024];
    t_image_data    images[256];
}                   t_game;

typedef struct      s_scenes
{
    char            *name;
    t_entity        *entities[1024];

}                   t_scenes;

typedef struct      s_mlx
{
    void            *mlx;
    void            *window;
    t_image_data    frame;
    bool            keys[65536];
    t_game          *game;
}                   t_mlx;

void	*ft_calloc(size_t nmemb, size_t size);

#endif
