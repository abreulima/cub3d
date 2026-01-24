#include "game.h"
#include "image_manager.h"
#include <string.h>

static void alloc_entity_input(t_game *game, t_entity *input) 
{
	input->transform = calloc(sizeof(t_comp_transform), 1);
	input->text_input = calloc(sizeof(t_comp_text_input), 1);
	input->transform->pos_x = 200;
	input->transform->pos_y = 200;
	input->text_input->txt = strdup("! !");
};

void	init_input(t_game *game)
{
	t_entity *input;

	input = calloc(sizeof(t_entity), 1);
	alloc_entity_input(game, input);
	add_entity(game, input);
}