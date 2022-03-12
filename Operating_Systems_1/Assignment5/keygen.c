#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    //check if correct number of args
    if(argc != 2) {
        fprintf(stderr,"USAGE: %s length\n", argv[0]);
        fprintf(stderr,"For example: %s 256\n", argv[0]); 
        exit(0);
    }


    //needed variables
    srand(time(NULL));
    int i;
    int size = atoi(argv[1]);

    //possible characters for the key
    char *key_opt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    char key_act[size + 1];
    
    //generate a rand num and select from the possible characters
    for(i = 0; i < size; i++) {
        int r = rand() % 27;
        key_act[i] = key_opt[r];
    }

    //append a null terminator and print the key
    key_act[size] = '\0'; 
	printf("%s\n", key_act);

    return 0;
}