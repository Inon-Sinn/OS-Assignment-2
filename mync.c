#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h> 


void build_server();

void build_client();

int main(int argc, char *argv[]){


    int optinal_arg = getopt (argc, argv, "l");
    // check if we should listen
    if((argc == 3) && (optinal_arg == 'l')){
        build_server(atoi(argv[2]));
    }// open the client
    else  if (argc == 3)
    {
        build_client(argv[1],atoi(argv[2]));
    }
    else{
        perror("ERROR - Incorrect amount of arguments given\n");
		exit(-1);
    }
    return 0;

}

void build_server(int port){
    // Variable initation
    int sock; 
    int connect_sock; 
    struct sockaddr_in serv_name; 
    socklen_t len = sizeof(serv_name);

    // socket create and verification
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("ERROR - socket creation failed...\n");
        exit(0);
    }

    // Clean the file where the socket is saved
    bzero(&serv_name, sizeof(serv_name)); 

    //assign IP, PORT
    serv_name.sin_family = AF_INET;                                   
    serv_name.sin_port = htons(port);

    // Binding newly created socket to given IP
     if ((bind(sock, (struct sockaddr *)&serv_name, sizeof(serv_name))) != 0) {
        perror("ERROR - socket bind failed...\n");
        exit(0);
    }

    //Now the server is ready to listen
    if((listen(sock, 1))!=0){
        perror("ERROR - Listen failed...\n");
        exit(0);
    }
    len = sizeof(serv_name); 

    //Accept the data packet from client and verification
    connect_sock = accept(sock, (struct sockaddr *)&serv_name, &len);
    if(connect_sock < 0){
        perror("ERROR - socket accept failed...\n");
        exit(0);
    }

    // Read 10 messages from the client
    char value[1] = {0}; 
    for (;;){
        read(connect_sock, &value, 1);
        printf("%s",value);
        bzero(value,sizeof(value));
    }

    // closing the socket
    close(connect_sock); 
    close(sock);

    printf("Build server\n");
}

void build_client(char *ip, int port){

    // Variable initation
    int sock; 
    struct sockaddr_in cli_name; 

    // socket create and verification
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("ERROR - socket creation failed...\n");
        exit(0);
    }


    // Clean the file where the socket is saved
    bzero(&cli_name, sizeof(cli_name)); 

    //assign IP, PORT
    cli_name.sin_family = AF_INET;     
    cli_name.sin_addr.s_addr = inet_addr(ip);                              
    cli_name.sin_port = htons(port);

    // connect the client socket to server socket
    if (connect(sock, (struct sockaddr *)&cli_name, sizeof(cli_name)) != 0){
        perror ("Error establishing communications");
        close(sock);
        exit(1);
    }

    // Wait to receive 10 messages from the server
    char input;
    for (;;){
        input =  getchar();
        write(sock,&input,1);
    }

    // Closing the socket
    close(sock); 
    printf("Build client\n");
}