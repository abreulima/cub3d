#include "game.h"
#include "image_manager.h"

static void alloc_entity_input(t_game *game, t_entity *input) 
{
	input->sprite = calloc(sizeof(t_comp_sprite), 1);
	input->transform = calloc(sizeof(t_comp_transform), 1);
	input->transform->pos_x = 200;
	input->transform->pos_y = 200;
	input->sprite->is_static = false;
    input->sprite->sprite_data = &game->images[FONT_ALP];
}

void	init_input(t_game *game)
{
	t_entity *input;

	input = calloc(sizeof(t_entity), 1);
	alloc_entity_input(game, input);
	add_entity(game, input);
}