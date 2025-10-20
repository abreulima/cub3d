#include <stdlib.h>
#include <mlx.h>
#define MLX_ERROR 1

#include <stdio.h>
#include <strings.h>

#include <X11/X.h>
#include <X11/keysym.h>

#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>


#include <stdlib.h>  


#define PORT 5000
#define MAXLINE 1000

typedef struct s_image
{
	void	*img;
	int	w;
	int	h;
}		t_image;

typedef struct s_player 
{
	int	id;
	int	x;
	int	y;
}		t_player;

typedef struct s_network 
{
	int	sockfd;
	char	buffer[100];
	int 	n;
	struct 	sockaddr_in servaddr;
}		t_network;


typedef struct s_game 
{
	void		*mlx;
	void		*win;
	t_player	player_one;
	t_player	player_two;
	t_image		hunter;
	t_image		cavegirl;
	t_network	network;
}			t_game;


char			**ft_split(const char *str, char c);


int handle_key(int key, t_game *game)
{

	if (key == XK_Escape)
	{
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
		exit(0);
	}

	if (key == XK_w)
	{
		game->player_one.y -= 1;
		sendto(game->network.sockfd, "PLAYER_TWO;W", MAXLINE, 0, (struct sockaddr*)NULL, sizeof(game->network.servaddr));
	}
	
	if (key == XK_s)
	{
		game->player_one.y += 1;
		sendto(game->network.sockfd, "PLAYER_TWO;S", MAXLINE, 0, (struct sockaddr*)NULL, sizeof(game->network.servaddr));
	}
		
	if (key == XK_a)
	{
		game->player_one.x -= 1;
		sendto(game->network.sockfd, "PLAYER_TWO;A", MAXLINE, 0, (struct sockaddr*)NULL, sizeof(game->network.servaddr));
	
	}
		
	if (key == XK_d)
	{
		game->player_one.x += 1;
		sendto(game->network.sockfd, "PLAYER_TWO;D", MAXLINE, 0, (struct sockaddr*)NULL, sizeof(game->network.servaddr));
	}
	
	return (0);
}

int render(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);

	// get player_position
	// render
	

	
	
	
	sendto(game->network.sockfd, "GET_POS", MAXLINE, 0, (struct sockaddr*)NULL, sizeof(game->network.servaddr));
	
	int n = recvfrom(game->network.sockfd, game->network.buffer, sizeof(game->network.buffer), 0, (struct sockaddr*)NULL, NULL);
	game->network.buffer[n] = '\0';


	char **moves = ft_split(game->network.buffer, '@');
	
	char **player_one = ft_split(moves[0], ';');
	char **player_two = ft_split(moves[1], ';');
	
	
	game->player_one.x = atoi(player_one[1]);
	game->player_one.y = atoi(player_one[2]);
	
	game->player_two.x = atoi(player_two[1]);
	game->player_two.y = atoi(player_two[2]);

	
	mlx_put_image_to_window(game->mlx, 
	game->win,
	game->hunter.img, 
	game->player_one.x, game->player_one.y);

	mlx_put_image_to_window(game->mlx, 
	game->win,
	game->cavegirl.img, 
	game->player_two.x, game->player_two.y);

	return (0);
}

void init_player(t_game *game)
{
	game->player_one.id = 0;
	game->player_one.x = 0;
	game->player_one.y = 0;
	
	
	game->player_two.id = 0;
	game->player_two.x = 0;
	game->player_two.y = 0;
}

void load_images(t_game *game)
{
	game->hunter.img = mlx_xpm_file_to_image(
		game->mlx, 
		"res/hunter.xpm", 
		&game->hunter.w, 
		&game->hunter.h);
		
	game->cavegirl.img = mlx_xpm_file_to_image(
	game->mlx,
	"res/cave_girl.xpm", 
	&game->cavegirl.w, 
	&game->cavegirl.h);
}

int main()
{
	t_game game;
	
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		return (MLX_ERROR);
	
	game.win = mlx_new_window(game.mlx, 800, 600, "Walking Simulator Now Multiplayer");
	if (game.mlx == NULL)
	{
		free(game.mlx);
		return (MLX_ERROR);
	}
	

	char *message = "Hello Server";

	
	 // clear servaddr
	bzero(&game.network.servaddr, sizeof(game.network.servaddr));
	game.network.servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	game.network.servaddr.sin_port = htons(PORT);
	game.network.servaddr.sin_family = AF_INET;
	
	game.network.sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	
	if(connect(game.network.sockfd, (struct sockaddr *)&game.network.servaddr, sizeof(game.network.servaddr)) < 0)
	{
		printf("\n Error : Connect Failed \n");
		exit(0);
	}
	
	//sendto(game.network.sockfd, "PLAYER_ONE", MAXLINE, 0, (struct sockaddr*)NULL, sizeof(game.network.servaddr));
	
	load_images(&game);
	init_player(&game);
	
	mlx_loop_hook(game.mlx, &render, &game);
	mlx_hook(game.win, 2, 1L<<0, &handle_key, &game);
	
	mlx_loop(game.mlx);
	//mlx_destroy_window(game.mlx, game.win);

	//free(game.mlx);
	
}
