
server side:

```
pallavi@desktop:~/Desktop/cmpe279/assignment1$ gcc -o server server.c
pallavi@desktop:~/Desktop/cmpe279/assignment1$ sudo ./server
In parent process waiting for child to finish. 
In Child process with current_pid 0 
Child process privileges dropped to nobody user.
Hello from client
Hello message sent
In parent process with current_pid 2427 
```

client side:

```
pallavi@desktop:~/Desktop/cmpe279/assignment1$ gcc -o client client.c
pallavi@desktop:~/Desktop/cmpe279/assignment1$ sudo ./client 
Hello message sent
Hello from server
```
