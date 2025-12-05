#ifndef COMPONENTS_H
# define COMPONENTS_H

#include "image_manager.h"

typedef struct s_comp_keyboard
{
}   t_comp_keyboard;

typedef struct      s_comp_sprite
{
    t_image_data    *sprite_data;
}                   t_comp_sprite;

typedef struct      s_comp_velocity
{
    float           vel_x;
    float           vel_y;
}                   t_comp_velocity;

typedef struct s_comp_transform
{
    float       pos_x;
    float       pos_y;
    int         rot;
}               t_comp_transform;

#endif