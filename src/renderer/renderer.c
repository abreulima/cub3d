#include "../minilibx-linux/mlx.h"
#include "game.h"
#include "renderer.h"
#include "image_manager.h"

       #include <sys/time.h>
#include <time.h>

# define MAGENTA 0xFF00FF

#include <math.h>

void paint_pixel(int *buff, int line_len, int x, int y, int color)
{
    //float now = ((float)SDL_GetTicks()) / 1000.0;
    //const float red = (float) (0.5 + 0.5 * sin(now));
    //const float green = (float) (0.5 + 0.5 * sin(now + M_PI * 2 / 3));
    //const float blue = (float) (0.5 + 0.5 * sin(now + M_PI * 4 / 3));

    //int rnd_color = (int)(red * 255) << 16 | (int)(255 * green) << 8 | (int)(255 * blue);
    //(void)color;
    buff[(y * line_len) + x] = color;
}

void paint_rect(int *buff, int line_len, t_rect rect, int color)
{
    int i;
    int j;

    i = rect.y;
    while (i < rect.y + rect.h)
    {
        j = rect.x;
        while (j < rect.x + rect.w)
        {
            //paint_rect(buff, line_len, j++, i, color);
        }
        ++i;
    }
}

void paint_image(t_mlx *mlx, t_image_data *src, t_rect rect)
{
    int *buffer;
    int *src_buffer;
    int x;
    int y;
    int pixel;

    buffer = (int *)mlx_get_data_addr(
        mlx->frame.ptr,
        &mlx->frame.bits_per_pixel,
        &mlx->frame.line_length,
        &mlx->frame.endian);
    mlx->frame.line_length /= 4;


    src_buffer = (int *)mlx_get_data_addr(
        src->ptr,
        &src->bits_per_pixel,
        &src->line_length,
        &src->endian);
    src->line_length /= 4;

    y = 0;
    while (y < rect.h)
    {
        x = 0;
        while (x < rect.w)
        {
            pixel = src_buffer[(y * src->line_length) + x];
            //pixel = buffer_src[((y + src->y) * src->img_data.line_length) + (x + src->x)];
            if (pixel == MAGENTA)
            {
                x++;
                continue;
            }
            buffer[((y + (int)rect.y) * mlx->frame.line_length)
				+ (x + (int)rect.x)] = pixel;
            x++;
        }
        y++;
    }
}

void paint_anim_image(t_mlx *mlx, t_image_data *img_data, t_rect dst, t_rect src)
{
    int *buffer;
    int *src_buffer;
    int x;
    int y;
    int pixel;

    buffer = (int *)mlx_get_data_addr(
        mlx->frame.ptr,
        &mlx->frame.bits_per_pixel,
        &mlx->frame.line_length,
        &mlx->frame.endian);
    mlx->frame.line_length /= 4;


    src_buffer = (int *)mlx_get_data_addr(
        img_data->ptr,
        &img_data->bits_per_pixel,
        &img_data->line_length,
        &img_data->endian);
    img_data->line_length /= 4;

    y = 0;
    while (y < src.h)
    {
        x = 0;
        while (x < src.w)
        {
            pixel = src_buffer[((y + src.y) * img_data->line_length) + (x + src.x)];
            //pixel = buffer_src[((y + src->y) * src->img_data.line_length) + (x + src->x)];
            if (pixel == MAGENTA)
            {
                x++;
                continue;
            }
            buffer[((y + (int)dst.y) * mlx->frame.line_length)
				+ (x + (int)dst.x)] = pixel;
            x++;
        }
        y++;
    }
}

void clear_window(t_image_data *frame)
{
    int i;
    int j;
    int *buffer;

    i = 0;
    buffer = (int *)mlx_get_data_addr(
        frame->ptr,
        &frame->bits_per_pixel,
        &frame->line_length,
        &frame->endian);
    frame->line_length /= 4;
    while (i < frame->height)
    {
        j = 0;
        while (j < frame->width)
        {
            paint_pixel(buffer, frame->line_length,i , j, 0);
            j++;
        }
        i++;
    }

}

static float angle = 0;

void paint_image_rotation(t_mlx *mlx, t_image_data *src, t_rect rect, int angle_rot)
{
    int *buffer;
    int *src_buffer;
    int x;
    int y;
    int new_x;
    int new_y;
    //float angle = 0;

    int pixel;

    buffer = (int *)mlx_get_data_addr(
        mlx->frame.ptr,
        &mlx->frame.bits_per_pixel,
        &mlx->frame.line_length,
        &mlx->frame.endian);
    mlx->frame.line_length /= 4;


    src_buffer = (int *)mlx_get_data_addr(
        src->ptr,
        &src->bits_per_pixel,
        &src->line_length,
        &src->endian);
    src->line_length /= 4;

    y = 0;
    while (y < rect.h)
    {
        x = 0;
        while (x < rect.w)
        {
            pixel = src_buffer[(y * src->line_length) + x];
            //pixel = buffer_src[((y + src->y) * src->img_data.line_length) + (x + src->x)];
            if (pixel == MAGENTA)
            {
                x++;
                continue;
            }
            angle_rot = 180 * (M_PI / 180.0);
            //angle_rot++;
            //if (angle_rot > 90)
            //    angle_rot = 0;
            //printf()
            angle += 0.000001f;
            if (angle > 2 * M_PI)
                angle = 0;

            // https://stackoverflow.com/questions/2259476/rotating-a-point-about-another-point-2d
            // new_x = cos(angle) * x - sin(angle) * y;
            // new_y = sin(angle) * x + cos(angle) * y;

            // p'x = cos(theta) * (px-ox) - sin(theta) * (py-oy) + ox
            // p'y = sin(theta) * (px-ox) + cos(theta) * (py-oy) + oy

            float pivot_x = src->width / 2.0;
            float pivot_y = src->height / 2.0;
            new_x = cos(angle) * (x - pivot_x) - sin(angle) * (y - pivot_y) + pivot_x;
            new_y = sin(angle) * (x - pivot_x) + cos(angle) * (y - pivot_y) + pivot_y;

            //if (new_x > rect.w || new_y > rect.h || new_x + rect.x < 0 || new_y + rect.y < 0)
            {
            //    x++;
            //    continue;
            }

            //new_x = x;
            //new_y = y;

            buffer[((new_y + (int)rect.y) * mlx->frame.line_length)
				+ (new_x + (int)rect.x)] = pixel;
            x++;
        }
        y++;
    }
}
