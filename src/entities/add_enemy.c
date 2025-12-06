#include "game.h"

static void	alloc_entity_enemy(t_game *game, t_entity *enemy)
{
    enemy->transform = calloc(sizeof(t_comp_transform), 1);
    enemy->sprite = calloc(sizeof(t_comp_sprite), 1);
    enemy->sprite->sprite_data = &game->images[ENEM];
}
void	init_enemy(t_game *game)
{
	t_entity *enemy;

	enemy = calloc(sizeof(t_entity), 1);
	alloc_entity_enemy(game, enemy);
	add_entity(game, enemy);
}