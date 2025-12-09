#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "game.h"
#include "image_manager.h"
#include "systems.h"
#include "key_manager.h"


int game_loop(void *data)
{
    t_mlx *mlx;

    mlx = (t_mlx*)data;
    keyboard_system(mlx);
    movement_system(mlx);
    render_system(mlx);
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

    init_player(&game);
    init_enemy(&game);
    init_crosshair(&game);

    printf("Game is working...\n");

    mlx_loop_hook(mlx.mlx, &game_loop, &mlx);
    mlx_hook(mlx.window, 2, 1L<<0, keydown, &mlx);
    mlx_hook(mlx.window, 3, 1L<<1, keyup, &mlx);
    mlx_hook(mlx.window, 17, 0, key_click_on_x, &mlx);
    mlx_loop(mlx.mlx);

    free_entities(game);
}
