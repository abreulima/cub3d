#ifndef RENDERER_H
#define RENDERER_H

#include "image_manager.h"

typedef struct  s_rect
{
    int x;
    int y;
    int w;
    int h;
}               t_rect;

void clear_window(t_image_data *frame);
void paint_image(t_mlx *mlx, t_image_data *src, t_rect rect);
void paint_anim_image(t_mlx *mlx, t_image_data *img_data, t_rect dst, t_rect src);
void paint_image_rotation(t_mlx *mlx, t_image_data *src, t_rect rect, int angle_rot);

#endif
