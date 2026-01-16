#include "game.h"

static void	alloc_entity_player(t_game *game, t_entity *player)
{

    player->transform = calloc(sizeof(t_comp_transform), 1);
    player->transform->pos_x = (int)((800 / 2) - 200 / 2)  + 180;
    player->transform->pos_y = 600 - 160;
    
    player->sprite = calloc(sizeof(t_comp_sprite), 1);
    player->sprite->has_anim = true;
    player->sprite->is_static = true;
    player->sprite->tile_size_x = 200;
    player->sprite->tile_size_y = 160;
    player->sprite->num_frames = 48;

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
