// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#define PORT 20232

int main(int argc, char const *argv[])
{
    struct sockaddr_in address;
    int sock = 0, valread, i;
    struct sockaddr_in serv_addr;
   //  char *hello = "Hello from client";
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "193.226.12.217", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
        char K[] ="frlls";
    
    for(i=0; i<strlen(K); i++)
    {
    if(K[i]=='f')
      send(sock, "f", 2, 0);
    if(K[i]=='b')
      send(sock, "b",2 , 0);
    if(K[i]=='l')
      send(sock, "l", 2, 0);
    if(K[i]=='r')
      send(sock, "r", 2, 0);
    if(K[i]=='s')
      send(sock, "s", 2, 0);
    }
    
    //send(sock, "f", 2, 0);
    //send(sock, "s", 2, 0);
    printf("Hello message sent\n");
    //valread = read( sock , buffer, 1024);
    //printf("%s\n",buffer );
    return 0;
}

