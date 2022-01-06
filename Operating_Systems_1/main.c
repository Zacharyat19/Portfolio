#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct movie {
    char *title;
    int year;
    char languages[5][21];
    int lang_size;
    double rating;
    struct movie *next_movie;
};

//adapted from student.c resource
struct movie *make_list(char *line) {
    //Allocate a new movie
    struct movie *curr_movie = malloc(sizeof(struct movie));

    //Use with strtok_r
    char *saveptr;

    //First line
    char *token = strtok_r(line, ",", &saveptr);
    curr_movie->title = calloc(strlen(token) + 1, sizeof(char));
    strcpy(curr_movie->title, token);

    //year
    token = strtok_r(NULL, ",", &saveptr);
    curr_movie->year = atoi(token);

    //languages
    token = strtok_r(NULL, ",", &saveptr);
    token++;

    char *saveptr2;
    char *token2 = strtok_r(token, ";", &saveptr2);
    int idx = 0;

    while(token2 != NULL) {
        strcpy(curr_movie->languages[idx], token2);
        idx++;
        token2 = strtok_r(NULL, ";", &saveptr2);

        if(token2 == NULL) {
            token2 = strtok_r(NULL, "\0", &saveptr2);
        }
    }

    curr_movie->lang_size = idx;

    //rating
    token = strtok_r(NULL, "\n", &saveptr);
    curr_movie->rating = strtod(token, &saveptr);

    //next node pointer
    curr_movie->next_movie = NULL;

    return curr_movie;
}

//adapted from student.c resource
struct movie *proccess_movie(char *file) {
    FILE *movie_list = fopen(file, "r");

    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char *token;

    struct movie *head = NULL;
    struct movie *tail = NULL;
    nread = getline(&line, &len, movie_list);

    while((nread = getline(&line, &len, movie_list)) != -1) {
        struct movie *new_movie = make_list(line);

        if(head == NULL) {
            head = new_movie;
            tail = new_movie;
        } else {
            tail->next_movie = new_movie;
            tail = new_movie;
        }
    }

    free(line);
    fclose(movie_list);
    return head;
}

int get_length(struct movie *movie_head) {
    struct movie *curr = movie_head;
    int size = 0;

    while(curr != NULL) {
        size += 1;
        curr = curr->next_movie;
    }

    return size;
}

void show_movie_release_in_specified_year(struct movie *list) {
    int movie_year;
    int movie_count = 0;
    printf("Enter the year for which you want to see movies: ");
    scanf("%d", &movie_year);

    struct movie *curr = list;
    while(curr != NULL) {
        if(curr->year == movie_year) {
            printf("%s\n", curr->title);
            movie_count += 1;
        }
        curr = curr->next_movie;
    }
    
    if(movie_count == 0) {
        printf("No data about movies released in the year %d\n", movie_year);
    }
}

void show_highest_rated_movie_for_each_year() {
    //make array of pointers for 122 years
    //loop through list and add node to year if it is knew or has a higher rating
    //move down list until finished then print out array
}

void show_movie_and_year_for_language(struct movie *list) {
    char *lang;
    printf("Enter the language for which you want to see movies: ");
    scanf("%s", lang);

    struct movie *curr = list;
    int i;
    while(curr != NULL) {
        for(i = 0; i < curr->lang_size; i++) {
            if(curr->languages[i] == lang) {
                printf("%d %s\n", curr->year, curr->title);
                break;
            }
        }
        curr = curr->next_movie;
    }
}

void clean(struct movie *head) {
    struct movie *curr = head;

    while(curr != NULL) {
        free(curr->title);
        free(curr);
        curr = curr->next_movie;
    }
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("You must provide the name of the file to process\n");
        printf("Example usage: ./movies movie_sample_1.csv\n");
        return EXIT_FAILURE;
    }

    struct movie *head = proccess_movie(argv[1]);
    printf("Proccessed file %s and parsed data for %d movies\n", argv[1], get_length(head));

    while(1) {
        printf("\n1. Show movies released in the specified year");
        printf("\n2. Show highest rated movie for each year");
        printf("\n3. Show the title and year of release of all movies in a specific language");
        printf("\n4. Exit from the program\n");

        int choice;
        printf("\nEnter a choice from 1 to 4: ");
        scanf("%d", &choice);
        
        if(choice == 1) {
            show_movie_release_in_specified_year(head);
        } else if(choice == 2) {
            show_highest_rated_movie_for_each_year(head);
        } else if(choice == 3) {
            show_movie_and_year_for_language(head);
        } else if(choice == 4) {
            clean(head);
            return EXIT_SUCCESS;
        }
    }
}