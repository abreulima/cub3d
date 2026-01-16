#ifndef KEYS_H
#define KEYS_H

#include "game.h"

#define MAX_KEYS 65536


typedef	enum	e_keys
{
	A_KEY  = 97,
	B_KEY  = 98,
	C_KEY  = 99,
	D_KEY  = 100,
	E_KEY  = 101,
	F_KEY  = 102,
	G_KEY  = 103,
	H_KEY  = 104,
	I_KEY  = 105,
	J_KEY  = 106,
	K_KEY  = 107,
	L_KEY  = 108,
	M_KEY  = 109,
	N_KEY  = 110,
	O_KEY  = 111,
	P_KEY  = 112,
	Q_KEY  = 113,
	R_KEY  = 114,
	S_KEY  = 115,
	T_KEY  = 116,
	U_KEY  = 117,
	V_KEY  = 118,
	W_KEY = 119,
	X_KEY  = 120,
	Y_KEY  = 121,
	Z_KEY  = 122,
	ESC_KEY = 65307,
	SHIFT_KEY = 65505
}				t_e_keys;

int		keydown(int keycode, t_mlx *mlx);
int		keyup(int keycode, t_mlx *mlx);
int		key_click_on_x(t_mlx *mlx);
void	init_keys(t_mlx *mlx);


#endif
