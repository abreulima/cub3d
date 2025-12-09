#ifndef ENTITY_H
# define ENTITY_H

typedef struct s_game t_game;
#include "components.h"

typedef struct s_entity
{
    int                 id;
    t_comp_keyboard     *keyboard;
    t_comp_transform    *transform;
	t_comp_velocity		*velocity;
    t_comp_sprite       *sprite;
}   t_entity;

void	init_player(t_game *game);
void	init_enemy(t_game *game);
void	init_crosshair(t_game *game);
int		add_entity(t_game *game, t_entity *entity);
void	free_entities(t_game game);

#endif
