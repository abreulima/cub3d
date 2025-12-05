#include "minilibx-linux/mlx.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Component Player
typedef struct s_comp_keyboard
{
}   t_comp_keyboard;


typedef struct  s_image_data
{
    void        *ptr;
    int         height;
    int         width;
}               t_image_data;

typedef struct      s_comp_sprite
{
    t_image_data    *sprite_data;
}                   t_comp_sprite;

// Component Transform
typedef struct s_comp_transform
{
    float pos_x;
    float pos_y;
    int rot;
}   t_comp_transform;

// Entitiy
typedef struct s_entity
{
    int                 id;
    t_comp_keyboard     *keyboard;
    t_comp_transform    *transform;
    t_comp_sprite       *sprite;
}   t_entity;

typedef struct      s_scenes
{
    char            *name;
    t_entity        *entities[1024];

}                   t_scenes;

typedef struct      s_game
{
    int             total_entities;
    t_entity        *entities[1024];
    t_image_data    images[256];
}                   t_game;

typedef struct s_mlx
{
    void    *mlx;
    void    *window;
    void    *frame;
    bool    keys[65536];
    t_game  *game;
}           t_mlx;
