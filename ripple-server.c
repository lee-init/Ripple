// contains SOCK_STREAM
#include <sys/socket.h>

// contains sockaddr_in
#include <netinet/in.h>

// contains memset()
#include <string.h>

// contains printf()
#include <stdio.h>

int main(void) {

    int listenfd = 0,connfd = 0;

    struct sockaddr_in serv_addr;

    // create sendBuff array of size 1025
    char sendBuff[1025];
    int numrv;
    
    // socket creates endpoint for communication and returns a file
    // socket (int domain, int type, int protocol)
    // https://www.man7.org/linux/man-pages/man2/socket.2.html
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("socker retrieve success\n");

    
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(5000);

    return 0;

}
