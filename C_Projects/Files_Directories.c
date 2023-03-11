#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#define PREFIX "movies_"

//Function declarations
void file_select();
void find_file(int choice);
void find_file_by_name();
char *make_dir();
void proccess_file(char *file, char *dir_name);
int check_file(char *file_name);

/*
 * This function should check whether a given input file has the prefix "movies_"
 * or ends in a ".csv". Returns 1 if it's a valid file, 0 otherwise.
 *
 * Params:
 *   file_name - the file to check. May not be NULL.
 */
int check_file(char *file_name) {
    //get length of the file
    int length = strlen(file_name);
    //If the first part of a file doesn't match the prefix return false
    if(strncmp(PREFIX, file_name, strlen(PREFIX)) != 0) {
        return 0;
    }
    //If the file doesn't end in .csv return false
    if(file_name[length - 1] != 'v' || file_name[length - 2] != 's' ||
       file_name[length - 3] != 'c' || file_name[length - 4] != '.') {
           return 0;
    }
    return 1; 
}

/*
 * This function should parse over a csv file and create txt files related to 
 * movie release years. Each file should include movies that were released in that year.
 * Code was reused and adapted from assignment 1 with some TA help.
 *
 * Params:
 *   file - the user selected file. May not be NULL.
 *   dir_name - the directory that the files will be put into.
 */
void proccess_file(char *file, char *dir_name) {
    //Open the input file
    FILE *movie_list = fopen(file, "r");

    //Assign variables for parsing
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char *token;

    //Get rid of the first line 
    nread = getline(&line, &len, movie_list);

    //Loop while not end of file
    while((nread = getline(&line, &len, movie_list)) != -1) {
        //Use with strtok_r
        char *saveptr;

        /* Parse the first line until "," is found
        * Once it is found, allocate the movie title and assign it
        */
        char *token = strtok_r(line, ",", &saveptr);
        char *title = calloc(strlen(token) + 2, sizeof(char));
        strcpy(title, token);
        title[strlen(token)] = '\n';

        //Parse until the year is found and assign it
        token = strtok_r(NULL, ",", &saveptr);
        int year = atoi(token);

        //Assign the file name location
        char file_name[256];
        sprintf(file_name, "%s/%d.txt", dir_name, year);
        //Open the file to write or create it if it doesn't exist
        int ret = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0640);
        write(ret, title, (strlen(title)) * sizeof(char));

        free(title);
        close(ret);
    }

    //free the line, close the file, and return the node
    free(line);
    fclose(movie_list);
}

/*
 * This function should create a directory with a randomized ending 
 * and return a string containing its name.
 *
 * Params:
 *   None
 */
char *make_dir() {
    int ret;
    // Create a random integer ending and allocate a string for the name
    int num = random() % 100000;
    char *file_name = calloc(256, sizeof(char));
    // Combine the begining and ending of the string into file_name
    sprintf(file_name, "taylzach.movies.%d", num);

    // Make directory with given name and permissions
    ret = mkdir(file_name, 0750);
    if(ret == 0) {
        // Print that the directory was successfully created and return its name
        printf("Created directory with name %s\n", file_name);
        return file_name;
    } else {
        // Print an error message if the directory encountered errors
        printf("Error in creating directory %s", file_name);
        free(file_name);
    }
}

/*
 * This function should prompt the user on which file they want to proccess
 * and execute the appropriate function call.
 *
 * Params:
 *   None
 */
void file_select() {
    int choice;
    // Prompt user for a selection
    printf("\nWhich file do you want to proccess\nEnter 1 to pick largest file\nEnter 2 to pick the smallest file");
    printf("\nEnter 3 to specify a file name\n\nEnter a choice from 1 to 3: ");
    scanf("%d", &choice);

    if(choice == 1 || choice == 2) {
        // If the user wants the smallest or largest file
        find_file(choice);
    } else if(choice == 3) {
        // If the user wants to specify a file name
        find_file_by_name();
    } else {
        printf("Invalid choice\n");

    }
}

/*
 * This function should loop through the current directory and find the 
 * largest or smallest csv file based on user input.
 * Code was adapted from directories module and TA help.
 *
 * Params:
 *   Choice - the user choice for the largest or smallest file
 */
void find_file(int choice) {
    // Open current directory and declare other variables
    DIR *curr_dir = opendir(".");
    struct dirent *a_dir;
    struct stat stats;
    int MAX;
    int MIN;
    int i = 0;
    char entry_name[256];

    // Loop while there are still contents to look at in the directory
    while((a_dir = readdir(curr_dir)) != NULL) {
        // If the file is a csv file
        if(check_file(a_dir->d_name)) {
            // Assign the stat struct the file
            stat(a_dir->d_name, &stats);

            // Check and see if the file is the first, largest, or smallest
            if(i == 0 || (stats.st_size > MAX && choice == 1) || (stats.st_size < MIN && choice == 2)) {
                if(choice == 1) {
                    // Assign the file name to the entry string if it's the largest
                    MAX = stats.st_size;
                    memset(entry_name, '\0', sizeof(entry_name));
                    strcpy(entry_name, a_dir->d_name);
                } else {
                    // Assign the file name to the entry string if it's the smallest
                    MIN = stats.st_size;
                    memset(entry_name, '\0', sizeof(entry_name));
                    strcpy(entry_name, a_dir->d_name);
                }
            }
            i++;  
        }
    }
    
    // Close the current directory and print out which file is proccessing
    closedir(curr_dir);
    printf("Now processing the chosen file named %s\n", entry_name);
    // Create the directory and get its name
    char *dir_name = make_dir();
    // Pass the name file and directory name for proccessing
    proccess_file(entry_name, dir_name);
    free(dir_name);
}

/*
 * This function ask the user to input the name of the file they want 
 * to search for. If the file doesn't exist. prompt them again for a file
 * choice. 
 *
 * Params:
 *   None
 */
void find_file_by_name() {
    // Get the name of the file
    char entry_name[256];
    printf("Enter the complete file name: ");
    scanf("%s", entry_name);

    // Try opening the file 
    int file = open(entry_name, O_RDONLY);

    if(file == -1) {
        // If the file can't be found, return the user to the file select 
        printf("The file %s was not found. Try again\n", entry_name);
        file_select();
    } else {
        // If the file is found, close it and print out its name for proccessing
        close(file);
        printf("Now processing the chosen file named %s\n", entry_name);
        // Make directory and proccess the file
        char *dir_name = make_dir();
        proccess_file(entry_name, dir_name);
        free(dir_name);
    }
}

/*
 * This function should ask the user what they wish to do,
 * proccess a file or exit the program.
 *
 * Params:
 *   None
 */
int main() {
    // Initialize random for later use
    srandom(time(NULL));
    while(1) {
        // Get the user input
        int choice;
        printf("\n1. Select file to proccess\n2. Exit the program\nEnter a choice 1 or 2: ");
        scanf("%d", &choice);

        if(choice == 1) {
            // Move to file select if choice is 1
            file_select();
        } else if(choice == 2) {
            // Exit the program if choice is 2
            return EXIT_SUCCESS;
        } else {
            // Print an error message otherwise
            printf("Invalid choice\n");
        }
    }
}