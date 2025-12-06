#include "game.h"

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
