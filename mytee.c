#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){


    // TODO - check if the \n from the input should be removed or not

    // Part 1 - read Input form stdin
    char *line = NULL;
    size_t len = 0;
    ssize_t lineSize = 0;
    lineSize = getline(&line, &len, stdin);
    // Part 2 - Write to the files
    for (size_t i = 1; i < argc; i++)
    {
        // Creation of the File descriptor
		int file_dpt = open(argv[i],  O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);

		// Testing the Input
		if(file_dpt == -1){
			perror("eERROR while trying to open File");
			exit(-1);
		}

		// Writing input into the files
        write(file_dpt, line, lineSize);	
    }
    
    // Part 3 - Write to stdout
    free(line);

    return 0;
}
