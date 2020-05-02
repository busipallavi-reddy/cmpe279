#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <sys/wait.h>

int main(int argc, char const *argv[]) 
{
    printf("In newly execd child with uid %d \n", getuid());
    int valread, new_socket;
    const char *hello;
    char buffer[1024] = {0};
    if (argc == 3)
    {
        new_socket = *argv[1];
	hello = argv[2];
    }
    else
    {
        perror("Args error");
        exit(EXIT_FAILURE);
    }
    valread = read( new_socket , buffer, 1024); 
    printf("%s\n", buffer); 
    send(new_socket , hello , strlen(hello) , 0 ); 
    printf("Hello message sent\n");
    return 0;
} 
