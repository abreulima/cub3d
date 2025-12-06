#include "game.h"

static void	alloc_entity_crosshair(t_game *game, t_entity *crosshair)
{
    crosshair->transform = calloc(sizeof(t_comp_transform), 1);
    crosshair->sprite = calloc(sizeof(t_comp_sprite), 1);
    crosshair->sprite->sprite_data = &game->images[CROSSHAIR];
}
void	init_crosshair(t_game *game)
{
	t_entity *crosshair;

	crosshair = calloc(sizeof(t_entity), 1);
	alloc_entity_crosshair(game, crosshair);
	add_entity(game, crosshair);
}