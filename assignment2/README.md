To solve the assignment, added the child contents to a new file child.c and execd child.c from server.c

Compile child.c

```
pallavi@desktop:~/Desktop/cmpe279/assignment2$ gcc -o child child.c
```

On server side 
```
pallavi@desktop:~/Desktop/cmpe279/assignment2$ gcc -o server server.c
pallavi@desktop:~/Desktop/cmpe279/assignment2$ sudo ./server 
In parent process waiting for child to finish. 
In Child process with current_pid 0 
In newly execd child with uid 65534 
Hello from client
Hello message sent
In parent process with current_pid 13239 
```

On client side
```
pallavi@desktop:~/Desktop/cmpe279/assignment2$ gcc -o client client.c
pallavi@desktop:~/Desktop/cmpe279/assignment2$ ./client
Hello message sent
Hello from server
```
