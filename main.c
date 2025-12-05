#include "cub3d.h"

void *image_loader(t_game *mlx, const char *path)
{

}



void movement_system(t_game game)
{
    int i;

    i = 0;
    while (i < game.total_entities)
    {
        if (game.entities[i]->transform)
        {
            printf("Entity has move %d\n", game.entities[i]->id);
        }
        i++;
    }
}

void keyboard_system(t_game game)
{
    int i;

    i = 0;
    while (i < game.total_entities)
    {
        if (game.entities[i]->keyboard &&
            game.entities[i]->transform)
        {
            printf("Entity has keyboard! %d\n", i);
        }
        i++;
    }
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
    keyboard_system(*(mlx->game));
    movement_system(*(mlx->game));
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

    t_entity player = {0};
    player.keyboard = calloc(sizeof(t_comp_keyboard), 1);
    player.transform = calloc(sizeof(t_comp_transform), 1);
    add_entity(&game, &player);

    t_entity enemy = {0};
    enemy.transform = calloc(sizeof(t_comp_transform), 1);
    add_entity(&game, &enemy);

    printf("Game is working...\n");

    mlx_loop_hook(mlx.mlx, &game_loop, &mlx);
    mlx_loop(mlx.mlx);

    free_entities(game);
}
