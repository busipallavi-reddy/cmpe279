// Server side C/C++ program to demonstrate Socket programming 
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 80
int main(int argc, char const *argv[]) 
{ 
    int server_fd, new_socket; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char *hello = "Hello from server"; 
       
    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    // Forcefully attaching socket to the port 8080 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                  &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
       
    // Forcefully attaching socket to the port 8080 
    if (bind(server_fd, (struct sockaddr *)&address,  
                                 sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,  
                       (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    }
    /* Assignment 1 */
    int current_pid = fork();
    if (current_pid == 0)
    {
	printf("In Child process with current_pid %d \n", current_pid);
	int proc_id = setuid(65534);
	if (proc_id == -1)
	{
	    perror("Drop Privileges Error");
	    exit(EXIT_FAILURE);
	}
	else
	{
	    if (execl("child", "child", &new_socket, hello, NULL) < 0)
	    {
	        perror("exec");
		exit(EXIT_FAILURE);
	    }
	    else
	    {
	        printf("Child exited with an error");
		return 0;
	    }
	}
    }
    else if (current_pid > 0)
    {
	printf("In parent process waiting for child to finish. \n");
	int wait_id;
	if((wait_id = wait(NULL)) < 0)
	{
            perror("Wait error");
            exit(EXIT_FAILURE);
        }
        printf("In parent process with current_pid %d \n", current_pid);
    }
    else
    {
	perror("Fork error");
	exit(EXIT_FAILURE);
    }
    return 0;
} 
