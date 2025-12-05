#include "minilibx-linux/mlx.h"

#include <stdio.h>
#include <stdlib.h>

// Component Player
typedef struct s_comp_keyboard
{
}   t_comp_keyboard;

typedef struct s_comp_sprite
{
    void    *sprite;
}           t_comp_sprite;

// Component Transform
typedef struct s_comp_transform
{
    int pos_x;
    int pos_y;
    int rot;
}   t_comp_transform;

// Entitiy
typedef struct s_entity
{
    int                 id;
    t_comp_keyboard     *keyboard;
    t_comp_transform    *transform;
}   t_entity;

typedef struct s_game
{
    int         total_entities;
    t_entity    *entities[1024];
    void        *images[256];
}   t_game;

typedef struct s_mlx
{
    void    *mlx;
    void    *window;
    void    *frame;
    t_game  *game;
}           t_mlx;
