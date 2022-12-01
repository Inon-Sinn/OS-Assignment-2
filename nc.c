#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char *argv[]){


    int optinal_arg = getopt (argc, argv, "l");
    // check if we should listen
    if((argc == 3) && (optinal_arg == 'l')){

        if (isdigit(argv[2][0]))
        {
            printf(" Server and is a number");
        }
        printf(" Server and not number");
    }

    // open the client
    printf("Its a clien");
    return 0;

}