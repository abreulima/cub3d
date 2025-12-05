#include "cub3d.h"
#include "images.h"
#include "keys.h"

#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#include <time.h>

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
int    keydown(int keycode, t_mlx *mlx)
{
    mlx->keys[keycode] = true;
	return (0);
}

int    keyup(int keycode, t_mlx *mlx)
{
    mlx->keys[keycode] = false;
	return (0);
}

void movement_system(t_game game)
{
    int i;

    i = 0;
    while (i < game.total_entities)
    {
        if (game.entities[i]->transform)
        {
            //printf("Entity has move %d\n", game.entities[i]->id);
        }
        i++;
    }
}

// We need a smoother movememnt equation

void keyboard_system(t_mlx *mlx)
{
    int i;

    i = 0;
    t_entity *e = mlx->game->entities[i];
    while (i < mlx->game->total_entities)
    {
        if (mlx->game->entities[i]->keyboard &&
            mlx->game->entities[i]->transform)
        {
            if (mlx->keys[W_KEY])
                mlx->game->entities[i]->transform->pos_y -= 2;
            if (mlx->keys[S_KEY])
                mlx->game->entities[i]->transform->pos_y += 2;
            if (mlx->keys[A_KEY])
                mlx->game->entities[i]->transform->pos_x -= 2;
            if (mlx->keys[D_KEY])
                mlx->game->entities[i]->transform->pos_x += 2;
        }
        i++;
    }
}

void render_system(t_mlx *mlx)
{
    int i;

    i = 0;
    mlx_clear_window(mlx->mlx, mlx->window);
    while (i < mlx->game->total_entities)
    {
        if (mlx->game->entities[i]->keyboard  &&
            mlx->game->entities[i]->sprite    &&
            mlx->game->entities[i]->transform)
        {
            mlx_put_image_to_window(mlx->mlx, 
                mlx->window, 
                mlx->game->entities[i]->sprite->sprite_data->ptr, 
                mlx->game->entities[i]->transform->pos_x, 
                mlx->game->entities[i]->transform->pos_y);
        }
        i++;
    }
    usleep(16000);
    
}

//game.entities[0] = player;
//game.total_entities++;
int add_entity(t_game *game, t_entity *e)
{
    game->entities[game->total_entities] = e;
    e->id = game->total_entities;
    game->total_entities++;
    return (game->total_entities);
}

void free_entities(t_game game)
{
    int i;

    i = 0;
    while (i < game.total_entities)
    {
        if (game.entities[i]->keyboard)
            free(game.entities[i]->keyboard);
        if (game.entities[i]->transform)
            free(game.entities[i]->keyboard);
        i++;
    }
}

int game_loop(void *data)
{
    t_mlx *mlx;

    mlx = (t_mlx*)data;
    keyboard_system(mlx);
    movement_system(*(mlx->game));
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

    game.total_entities = 0;

    game.images[HERO] = image_loader(&mlx, "_res/collect_banner.xpm");

    t_entity player = {0};
    player.keyboard = calloc(sizeof(t_comp_keyboard), 1);
    player.transform = calloc(sizeof(t_comp_transform), 1);
    player.sprite = calloc(sizeof(t_comp_sprite), 1);
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
