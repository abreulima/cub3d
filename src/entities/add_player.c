#include "game.h"

static void	alloc_entity_player(t_game *game, t_entity *player)
{
    player->keyboard = calloc(sizeof(t_comp_keyboard), 1);
    player->transform = calloc(sizeof(t_comp_transform), 1);
    player->sprite = calloc(sizeof(t_comp_sprite), 1);
    player->velocity = calloc(sizeof(t_comp_velocity), 1);
    player->sprite->sprite_data = &game->images[HERO];
}
void	init_player(t_game *game)
{
	t_entity *player;

	player = calloc(sizeof(t_entity), 1);
	alloc_entity_player(game, player);
	add_entity(game, player);
}
