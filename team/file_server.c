#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <fcntl.h>

#define BUF_SIZE 10000

void error_handling(char *message);

int main(int argc, char *argv[])
{
    int s_socket;
    int c_socket;
    struct sockaddr_in s_addr;
    struct sockaddr_in c_addr;
    socklen_t client_addr_size;
    int fd;
    char buf[BUF_SIZE];
 
    fd=open(argv[1], O_RDONLY);
    if( fd==-1 )
        error_handling("open() error!");
    if( read(fd,buf,sizeof(buf))==-1)
        error_handling("read() error!");
    close(fd);

    if(argc!=3){
        printf("Usage : %s<txt>  <port>\n", argv[0]);
        exit(1);
    }

    s_socket=socket(PF_INET, SOCK_STREAM, 0);
    if(s_socket == -1)
        error_handling("socket() error");

    memset(&s_addr, 0, sizeof(s_addr));
    s_addr.sin_family=AF_INET;
    s_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    s_addr.sin_port=htons(atoi(argv[2]));

    if(bind(server_sock, (struct sockaddr*) &s_addr, sizeof(s_addr))==-1)
        error_handling("bind() error");

    if(listen(server_sock, 5)==-1)
        error_handling("listen() error");

    c_addr_size=sizeof(c_addr);
    c_socket=accept(s_socket, (struct sockaddr*)&c_addr, &c_addr_size);
    if(c_socket==-1)
        error_handling("accept() error");

    write(clnt_sock, buf, sizeof(buf));

    close(c_socket);
    close(s_socket);

    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n',stderr);
    exit(1);
}



