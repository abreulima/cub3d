#ifndef IMAGE_MANAGER_H
# define IMAGE_MANAGER_H

typedef struct s_mlx t_mlx;

typedef struct  s_image_data
{
    void        *ptr;
    int         height;
    int         width;
    int         *buffer;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_image_data;

typedef enum    e_images
{
                HERO,
                MAP,
                ENEMY_01,
                ENEMY_02,
                CROSSHAIR,
                WALL_N,
                WALL_W,
                WALL_E,
                WALL_S,
                HUD_HP,
                BT_PLAY,
                BT_PLAY_HOVER
}               t_images;

t_image_data image_loader(t_mlx *mlx, char *path);

#endif
