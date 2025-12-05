#ifndef ENTITY_H
# define ENTITY_H

#include "components.h"

typedef struct s_entity
{
    int                 id;
    t_comp_keyboard     *keyboard;
    t_comp_transform    *transform;
	t_comp_velocity		*velocity;
    t_comp_sprite       *sprite;
}   t_entity;

int		add_entity(t_game *game, t_entity *e);
void	free_entities(t_game game);

#endif