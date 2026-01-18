#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
// netinet/in.h includes #define INET6_ADDRSTRLEN 48 
#include <netinet/in.h>

int host(char *host) {

    struct addrinfo hints, *res, *p;
    int status;
    char ipstr[INET6_ADDRSTRLEN];

    /*
        memset is used to fill a block of memory:    
        (pointer to memory [&hints is the memory address of hints], value to set, number of bytes to set to the value)
        
    */
   
    memset(&hints, 0, sizeof hints);
    hints.ai_addr = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // getaddrinfo(host, NULL, &hints, &res) returns an integer. Test: "printf("%d\n", getaddrinfo(host, NULL, &hints, &res))";
    if ((status = getaddrinfo(host, NULL, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return 2;
    }

    printf("IP address for %s:\n\n", host);

    // printf("%p\n", p);
    // printf("%p\n", res);

    // itterate through the list - Explination: https://youtu.be/VOpjAHCee7c?t=372
    for (p = res; p != NULL; p = p->ai_next) {
        
        void *addr;
        char *ipver;

        struct sockaddr_in *ipv4;
        struct sockaddr_in6 *ipv6;

        if (p->ai_family == AF_INET) {
            ipv4 = (struct sockaddr_in *)p->ai_addr;
            addr = &(ipv4->sin_addr);
            ipver = "IPv4";
        } else {
            ipv6 = (struct sockaddr_in6 *)p->ai_addr;
            addr = &(ipv6->sin6_addr);
            ipver = "IPv6";
        }
        
        inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
        printf("    %s: %s\n", ipver, ipstr );

        // printf("%p\n", p);
    }    

    freeaddrinfo(res);

    return 0;

}
