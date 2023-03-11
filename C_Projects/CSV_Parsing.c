#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Movie struct used throughout the assignment
struct movie {
    char *title;
    int year;
    char languages[5][21];
    int lang_size;
    double rating;
    struct movie *next_movie;
};

/*
 * This function should allocate a new movie struct and return a pointer to it.
 * Each attribute should be allocated and only the next movie pointer can be NULL.
 * Code has been adapted from the student.c resource along with some help from the TA.
 *
 * Params:
 *   line - the current line of the input file to parse over. May not be NULL.
 */
struct movie *make_list(char *line) {
    //Allocate a new movie struct
    struct movie *curr_movie = malloc(sizeof(struct movie));

    //Use with strtok_r
    char *saveptr;

   /* Parse the first line until "," is found
    * Once it is found, allocate the movie title and assign it
    */
    char *token = strtok_r(line, ",", &saveptr);
    curr_movie->title = calloc(strlen(token) + 1, sizeof(char));
    strcpy(curr_movie->title, token);

    //Parse until the year is found and assign it
    token = strtok_r(NULL, ",", &saveptr);
    curr_movie->year = atoi(token);

   /* Parse until the end of the language array is found
    * Once it is found, remove the starting/ending brackets from the string
    */
    token = strtok_r(NULL, ",", &saveptr);
    token[strlen(token) - 1] = '\0';
    token++;

    //Parse over the new token to extract individual languages
    char *saveptr2;
    char *token2 = strtok_r(token, ";", &saveptr2);
    int idx = 0;

    while(token2 != NULL) {
        //copy the token to the correct index in the movie struct
        strcpy(curr_movie->languages[idx], token2);
        idx++;
        token2 = strtok_r(NULL, ";", &saveptr2);

        //Since the last language won't have a "," to find, look for the NULL terminator instead
        if(token2 == NULL) {
            token2 = strtok_r(NULL, "\0", &saveptr2);
        }
    }
    //Add idx to the lang_size for later use
    curr_movie->lang_size = idx;

    //Parse over token to find the rating and convert it
    token = strtok_r(NULL, "\n", &saveptr);
    curr_movie->rating = strtod(token, &saveptr);

    //Set the next node pointer to NULL by default
    curr_movie->next_movie = NULL;

    return curr_movie;
}

/*
 * This function should parse over the input file and build a linked list of its contents.
 * Code has been adapted from the student.c resource along with some help from the TA.
 *
 * Params:
 *   file - the user input file to parse over. May not be NULL.
 */
struct movie *proccess_movie(char *file) {
    //Open the input file
    FILE *movie_list = fopen(file, "r");

    //Assign variables for parsing
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char *token;

    //Create the head and tail nodes
    struct movie *head = NULL;
    struct movie *tail = NULL;
    //Get rid of the first line 
    nread = getline(&line, &len, movie_list);

    //Loop while not end of file
    while((nread = getline(&line, &len, movie_list)) != -1) {
        //Create a new node
        struct movie *new_movie = make_list(line);

        //If this is the first node, assign it to the head
        if(head == NULL) {
            head = new_movie;
            tail = new_movie;
        //Otherwise add it to the end
        } else {
            tail->next_movie = new_movie;
            tail = new_movie;
        }
    }

    //free the line, close the file, and return the node
    free(line);
    fclose(movie_list);
    return head;
}

/*
 * This function should return the length of the movie linked list.
 *
 * Params:
 *   head - the head of the linked list. May not be NULL.
 */
int get_length(struct movie *head) {
    //Assign curr node to head
    struct movie *curr = head;
    int size = 0;

    while(curr != NULL) {
        //Increment the size and move on to the next node
        size += 1;
        curr = curr->next_movie;
    }

    return size;
}

/*
 * This function should print out the movie titles associated with a specified year.
 * The user will be asked for an input year and it will out movies released in that year.
 * Otherwise an error message will be printed.
 *
 * Params:
 *   list - the movie linked list to traverse over. May not be NULL.
 */
void show_movie_release_in_specified_year(struct movie *list) {
    //Variable declaration
    int movie_year;
    int movie_count = 0;

    //Prompt user for an input year
    printf("Enter the year for which you want to see movies: ");
    scanf("%d", &movie_year);

    struct movie *curr = list;
    while(curr != NULL) {
        //If the input year and current movie year match print out the movie
        if(curr->year == movie_year) {
            printf("%s\n", curr->title);
            //Increment the movie count
            movie_count += 1;
        }
        //Increment to next movie
        curr = curr->next_movie;
    }
    
    //If no movies were printed then the year has no movies, print an error message
    if(movie_count == 0) {
        printf("No data about movies released in the year %d\n", movie_year);
    }
}

/*
 * This function should print out the year, name, and highest rated movie of each year.
 *
 * Params:
 *   list - the list of the movies. May not be NULL.
 */
void show_highest_rated_movie_for_each_year(struct movie *list) {
    //Allocate an array of struct pointers for each possible year
    struct movie **years = calloc(122, sizeof(struct movie*));
    struct movie *curr = list;

    while(curr != NULL) {
        //If a pointer is NULL or a higher rated movie for that year is found
        if(years[curr->year - 1900] == NULL || years[curr->year - 1900]->rating < curr->rating) {
            //Assign new movie
            years[curr->year - 1900] = curr;
        }
        //Increment the list
        curr = curr->next_movie;
    }

    for(int i = 0; i < 122; i++) {
        //If a movie exists in the array, print out its contents
        if(years[i] != NULL) {
            printf("%d %.1f %s\n", years[i]->year, years[i]->rating, years[i]->title);
        }
    }
    //Free the pointer array
    free(years);
}

/*
 * This function should print out the movie titles associated with a specified year.
 * The user will be asked for an input year and it will out movies released in that year.
 * Otherwise an error message will be printed.
 *
 * Params:
 *   list - the movie linked list to traverse over. May not be NULL.
 */
void show_movie_and_year_for_language(struct movie *list) {
    //Variable delcarations
    char lang[21];
    int p = 0;

    //Prompt the user for an input string
    printf("Enter the language for which you want to see movies: ");
    scanf("%s", lang);

    struct movie *curr = list;
    int i;
    while(curr != NULL) {
        //loop over and check each language in the array
        for(i = 0; i < curr->lang_size; i++) {
            //If the languages match, print out its year and title
            if(strcmp(curr->languages[i], lang) == 0) {
                printf("%d %s\n", curr->year, curr->title);
                p++;
                break;
            }
        }
        //Increment to next movie
        curr = curr->next_movie;
    }

    //If no movies were printed, print an error message.
    if(p == 0) {
        printf("No data about movies released in %s\n", lang);
    }
}

/*
 * This function should free the memory associated with the linked list.
 * Checks to see if a node is NULL, otherwise recurses down.
 * Once NULL is found, moves back up and clears the memory.
 *
 * Params:
 *   head - the head of the movie list. May not be NULL.
 */
void clean(struct movie *node) {
    //Check to see if a node is null, base case
    if(node == NULL) {
        return;
    }

    //If the node isn't null, keep going down the list
    clean(node->next_movie);
    //Free all memory associated with a node
    free(node->title);
    free(node);
}

/*
 * The main function should take in command line inputs and perform a set of operations.
 * 1. Check to make sure the number of arguments is correct.
 * 2. Pass the input file to create the movie linked list.
 * 3. Print out choices and procces user inputs, calling the appropriate function.
 *
 * Params:
 *   argc - the number of arguments.
 *   argv[] - A string array containing the file name.
 */
int main(int argc, char *argv[]) {
    //Check to see if the correct number of arguments was given
    if(argc < 2) {
        printf("You must provide the name of the file to process\n");
        printf("Example usage: ./movies movie_sample_1.csv\n");
        return EXIT_FAILURE;
    }

    //Create the linked list from the input file
    struct movie *head = proccess_movie(argv[1]);
    printf("Proccessed file %s and parsed data for %d movies\n", argv[1], get_length(head));

    while(1) {
        //Print out user choices
        printf("\n1. Show movies released in the specified year");
        printf("\n2. Show highest rated movie for each year");
        printf("\n3. Show the title and year of release of all movies in a specific language");
        printf("\n4. Exit from the program\n");

        //Collect user input
        int choice;
        printf("\nEnter a choice from 1 to 4: ");
        scanf("%d", &choice);
        
        //Call the specific function related to user input, otherwise print an error message
        if(choice == 1) {
            show_movie_release_in_specified_year(head);
        } else if(choice == 2) {
            show_highest_rated_movie_for_each_year(head);
        } else if(choice == 3) {
            show_movie_and_year_for_language(head);
        } else if(choice == 4) {
            clean(head);
            return EXIT_SUCCESS;
        } else {
            printf("You entered an incorrect choice. Try again.\n");
        }
    }
}