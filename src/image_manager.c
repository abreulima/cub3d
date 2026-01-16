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


void *create_img_from_rect(t_mlx *mlx, void *source, int x, int y, int width, int height)
{
    int *src_buffer;
    int	*dst_buffer;
    void *target_img;
    t_image_data src_data;
    t_image_data dst_data;
    int i;
    int j;
	
    src_buffer = (int *)mlx_get_data_addr(source, &src_data.bits_per_pixel, &src_data.line_length, &src_data.endian);

    target_img = mlx_new_image(mlx->mlx, width, height);
    dst_buffer = (int *)mlx_get_data_addr(target_img, &dst_data.bits_per_pixel, &dst_data.line_length, &dst_data.endian);
    dst_data.line_length /= 4;

    i = 0;
	while (i <height)
	{
		j = 0;
		while (j < width)
		{
			dst_buffer[(i * dst_data.line_length) + j] = src_buffer[((i + y) * src_data.line_length / 4) + j + x];
			j++;
		}
		i++;
	}

    return ((void *)target_img);
}
