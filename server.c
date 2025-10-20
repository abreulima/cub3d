// server program for udp connection
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 5000
#define MAXLINE 1000

typedef struct s_player 
{
	int	id;
	int	x;
	int	y;
}		t_player;


// Driver code
int main()
{   
    char buffer[100];
    char *message = "Hello Client";
    int listenfd, len;
    struct sockaddr_in servaddr, cliaddr;
    bzero(&servaddr, sizeof(servaddr));

    // Create a UDP Socket
    listenfd = socket(AF_INET, SOCK_DGRAM, 0);        
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    servaddr.sin_family = AF_INET; 
 
    // bind server address to socket descriptor
    bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
     
    //receive the datagram
    len = sizeof(cliaddr);
    
    t_player player_one = {0};
    t_player player_two = {0};
    
	while (1)
	{
	
	  int n = recvfrom(listenfd, buffer, sizeof(buffer),
            0, (struct sockaddr*)&cliaddr,&len); //receive message from server
    buffer[n] = '\0';


		if (strcmp(buffer, "GET_POS") == 0)
		{
			char temp[100];
			snprintf(temp, 100, 
			"PLAYER_ONE;%d;%d@PLAYER_TWO;%d;%d", 
			player_one.x, player_one.y,
			player_two.x, player_two.y);	
				
			puts(temp);
			sendto(listenfd, temp, MAXLINE, 0, (struct sockaddr*)&cliaddr, sizeof(cliaddr));
		}
		
		if (strncmp(buffer, "PLAYER_ONE", 10) == 0)
		{

			if (buffer[11] == 'W')
				player_one.y -= 1;
			if (buffer[11] == 'S')
				player_one.y += 1;			
			if (buffer[11] == 'A')
				player_one.x -= 1;			
			if (buffer[11] == 'D')
				player_one.x += 1;
			
			char temp[50];
			//snprintf(temp, 50, "PLAYER_ONE;%d;%d", player_one.x, player_one.y);			
			//puts(temp);
			//sendto(listenfd, temp, MAXLINE, 0, (struct sockaddr*)&cliaddr, sizeof(cliaddr));
		}
		
		if (strncmp(buffer, "PLAYER_TWO", 10) == 0)
		{

			if (buffer[11] == 'W')
				player_two.y -= 1;
			if (buffer[11] == 'S')
				player_two.y += 1;			
			if (buffer[11] == 'A')
				player_two.x -= 1;			
			if (buffer[11] == 'D')
				player_two.x += 1;
			
			char temp[50];
			//snprintf(temp, 50, "PLAYER_TWO;%d;%d", player_one.x, player_one.y);			
			//puts(temp);
			//sendto(listenfd, temp, MAXLINE, 0, (struct sockaddr*)&cliaddr, sizeof(cliaddr));
		}
		
		
  
 	}
}
