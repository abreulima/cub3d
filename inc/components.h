#ifndef COMPONENTS_H
# define COMPONENTS_H

#include "image_manager.h"

typedef struct s_comp_keyboard
{
}   t_comp_keyboard;

typedef struct s_comp_map
{
}   t_comp_map;

typedef struct      s_comp_sprite
{
    t_image_data    *sprite_data;
    bool            is_static;
    bool            has_anim;
    int             tile_size_x;
    int             tile_size_y;
    int             num_frames;
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

typedef struct s_comp_text
{
    char *txt;
}               t_comp_text;

typedef struct s_comp_text_input
{
    int  size;
    char *txt;
}               t_comp_text_input;



#endif
