#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "game.h"
#include "renderer.h"
#include "image_manager.h"
#include "systems.h"
#include "key_manager.h"

int game_loop(void *data)
{
    t_mlx *mlx;

    mlx = (t_mlx*)data;
    clear_window(&mlx->frame);
    keyboard_system(mlx);
    movement_system(mlx);
    render_system(mlx);
    text_system(mlx);
    input_system(mlx);
    mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->frame.ptr, 0, 0);
    usleep(16000);
    return (0);
}

int main()
{
    t_mlx mlx;
    t_game game;

    mlx.mlx = mlx_init();
    mlx.window = mlx_new_window(mlx.mlx, 800, 600, "cub3d");

    mlx.frame.height = 800;
    mlx.frame.width = 600;
    mlx.frame.ptr = mlx_new_image(mlx.mlx, 800, 600);
    mlx.game = &game;

    init_keys(&mlx);
    game.total_entities = 0;

    game.images[HERO] = image_loader(&mlx, "res/walk_anim.xpm");
    game.images[CROSSHAIR] = image_loader(&mlx, "res/crosshair_2.xpm");
    game.images[ENEMY_01] = image_loader(&mlx, "res/oi.xpm");
    game.images[ENEMY_02] = image_loader(&mlx, "res/enemy.xpm");
    game.images[FONT_ALP] = image_loader(&mlx, "res/def_font.xpm");

    int i = 0;
    int j = 0;
    int y_offset[6] = {1, 18, 35, 52, 69, 86};


    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            game.font[i + j * 16].ptr = create_img_from_rect(&mlx, game.images[FONT_ALP].ptr, (9 * i) + 1, 17 * j + 1, 8, 16);
            game.font[i + j * 16].width = 8;
            game.font[i + j * 16].height = 16;
        }
    }

    while(i < 96)
    {
        //game.font[i].ptr = create_img_from_rect(&mlx, game.images[FONT_ALP].ptr, (9 * i) + 1, 1, 8, 16);
        //game.font[i].ptr = create_img_from_rect(&mlx, game.images[FONT_ALP].ptr, (9 * i) + 1, 17 * (i / 16) + 1, 8, 16);
        printf("i:%d \t %d %d %d %d\n", i, (9 * i) + 1, 17 * ((int)(i / 16)) + 1, 8, 16);
        i++;
    }
    //while(i < 52)
    //{
    //    game.font[i].ptr = create_img_from_rect(&mlx, game.images[FONT_ALP].ptr, i * 10, 10, 10, 18);
    //    game.font[i].width = 10;
    //    game.font[i].height = 18;
    //    i++;
    //}

    init_input(&game);
    init_player(&game);
    //init_enemy(&game);
    init_crosshair(&game);

    printf("Game is working...\n");

    mlx_loop_hook(mlx.mlx, &game_loop, &mlx);
    mlx_hook(mlx.window, 2, 1L<<0, keydown, &mlx);
    mlx_hook(mlx.window, 3, 1L<<1, keyup, &mlx);
    mlx_hook(mlx.window, 17, 0, key_click_on_x, &mlx);
    mlx_loop(mlx.mlx);

    free_entities(game);
}
