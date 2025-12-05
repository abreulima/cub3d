#include "game.h"

t_image_data image_loader(t_mlx *mlx, char *path)
{
    t_image_data data;

    data.ptr = mlx_xpm_file_to_image(
        mlx->mlx,
        path,
        &data.width,
        &data.height
    );
    #ifdef DEBUG
        printf
        (
            "Image loaded. path: %s, width: %d, height: %d\n",
            path, data.width, data.height
        );
    #endif
    return (data);
}