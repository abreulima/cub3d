#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "game.h"
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
    mlx.frame = mlx_new_image(mlx.mlx, 800, 600);
    mlx.game = &game;
    init_keys(&mlx);
    game.total_entities = 0;

    game.images[HERO] = image_loader(&mlx, "res/collect_banner.xpm");

    t_entity player = {0};
    player.keyboard = calloc(sizeof(t_comp_keyboard), 1);
    player.transform = calloc(sizeof(t_comp_transform), 1);
    player.sprite = calloc(sizeof(t_comp_sprite), 1);
    player.velocity = calloc(sizeof(t_comp_velocity), 1);
    player.sprite->sprite_data = &game.images[HERO];
    add_entity(&game, &player);

    t_entity enemy = {0};
    enemy.transform = calloc(sizeof(t_comp_transform), 1);
    add_entity(&game, &enemy);
    printf("Game is working...\n");

    mlx_loop_hook(mlx.mlx, &game_loop, &mlx);
    mlx_hook(mlx.window, 2, 1L<<0, keydown, &mlx);
    mlx_hook(mlx.window, 3, 1L<<1, keyup, &mlx);
    mlx_loop(mlx.mlx);

    free_entities(game);
}
