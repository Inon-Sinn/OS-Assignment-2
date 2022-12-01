#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>

/*
Prints the command DIR of our shell
if bool is 1 - will print the same as "dir"
if it's 0 - will print the same as "dir -a" - out default 
*/
void dir_cmd(const char* dirname, int bool);

/*
Copies the content of one file into another
In case the First file doesn't exist - error
In case the Second file doesn't exist it will be created, otherwise will be overwritten
*/
void copy_cmd(char* src, char* dst);


int main(int argc, char *argv[]){
    //dir_cmd(".",1);

    //copy_cmd("test1.txt","test1.txt");


    return 0;
}

void dir_cmd(const char* dirname, int bool){
    // open the current directory
	DIR* dir = opendir(dirname);
	if (dir == NULL){
		perror("ERROR - could't open the directory");
		exit(1);
	}

    // goint over all the entities inside the directory
	struct dirent* entity; 
    entity = readdir(dir);
	while (entity != NULL){
        if(((entity->d_name)[0]!='.')){
            printf("%s\n",entity->d_name);
        }
        else if(bool == 1){
            printf("%s\n",entity->d_name);
        }
        entity = readdir(dir);
    }

    // Closing the directory
	closedir(dir);	
}

void copy_cmd(char* src, char* dst){

    // Check if its is the same file
    if(strcmp(src,dst)==0){
        return;
    }

	// Creationg of the File descriptors and buffers
	int file_dpt1 = open(src,  O_RDONLY);
	int file_dpt2 = open(dst,  O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	char buff_1[100] = {0};

	// Testing the Input - <File1> - TODO check with nezer
	if(file_dpt1 == -1){
		perror("ERROR - couldn't open source file");
		exit(-1);
	}

	// Copying File 1 into File 2
	int read_1 = read(file_dpt1, buff_1, 1);
	while (read_1 != 0){
		write(file_dpt2, buff_1, 1);	
		read_1 = read(file_dpt1, buff_1, 1);
	}

    //closing the file descriptors
    close(file_dpt1);
    close(file_dpt2);
}

