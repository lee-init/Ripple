#include "host.h"

int main(int argc, char *argv[]) {

    if (argc != 2) {
        // fprintf is formated. printf is not
        fprintf(stderr, "usage: show ip / hostname\n");
        return 1;
    }

    host(argv[1]);

    return 0;

}