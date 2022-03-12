#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

//Global variables
char output_str[81];
int out_idx = 0;

char buffer_1[50][1001] = {0};
char buffer_2[50][1001] = {0};
char buffer_3[50][1001] = {0};

int prod_idx_1 = 0;
int con_idx_1 = 0;

int prod_idx_2 = 0;
int con_idx_2 = 0;

int prod_idx_3 = 0;
int con_idx_3 = 0;

int count_1 = 0;
int count_2 = 0;
int count_3 = 0;

pthread_mutex_t mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t full_1 = PTHREAD_COND_INITIALIZER;

pthread_mutex_t mutex_2 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t full_2 = PTHREAD_COND_INITIALIZER;

pthread_mutex_t mutex_3 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t full_3 = PTHREAD_COND_INITIALIZER;

/*
 * This function add an input string to the next spot in buffer one
 *
 * Params:
 *   str - the string to be added to buffer one.
 */
void put_bf1(char *str) {
    //Lock the mutex before putting the item in the buffer
    pthread_mutex_lock(&mutex_1);

    //Put the item in the buffer
    strcpy(buffer_1[prod_idx_1], str);

    //Increment the index where the next item will be put.
    prod_idx_1 = prod_idx_1 + 1;
    count_1++;

    //Signal to the consumer that the buffer is no longer empty
    pthread_cond_signal(&full_1);

    //Unlock the mutex
    pthread_mutex_unlock(&mutex_1);
}

/*
 * This function add an input string to the next spot in buffer two
 *
 * Params:
 *   str - the string to be added to buffer two.
 */
void put_buf2(char *str) {
    //Lock the mutex before putting the item in the buffer
    pthread_mutex_lock(&mutex_2);

    //Put the item in the buffer
    strcpy(buffer_2[prod_idx_2], str);

    //Increment the index where the next item will be put.
    prod_idx_2 = prod_idx_2 + 1;
    count_2++;

    //Signal to the consumer that the buffer is no longer empty
    pthread_cond_signal(&full_2);

    //Unlock the mutex
    pthread_mutex_unlock(&mutex_2);
}

/*
 * This function add an input string to the next spot in buffer three
 *
 * Params:
 *   str - the string to be added to buffer three.
 */
void put_buf3(char *str) {
    //Lock the mutex before putting the item in the buffer
    pthread_mutex_lock(&mutex_3);

    //Put the item in the buffer
    strcpy(buffer_3[prod_idx_3], str);

    //Increment the index where the next item will be put.
    prod_idx_3 = prod_idx_3 + 1;
    count_3++;

    //Signal to the consumer that the buffer is no longer empty
    pthread_cond_signal(&full_3);

    //Unlock the mutex
    pthread_mutex_unlock(&mutex_3);
}

/*
 * This function return the next string in buffer one.
 *
 * Params:
 *   none.
 */
char *get_bf1() {
    //Create new string to hold item from buffer
    char *str = malloc(1001 * sizeof(char));

    //Lock the mutex before checking if the buffer has data
    pthread_mutex_lock(&mutex_1);

    while(count_1 == 0) {
        //Buffer is empty. Wait for the producer to signal that the buffer has data
        pthread_cond_wait(&full_1, &mutex_1);
    }

    strcpy(str, buffer_1[con_idx_1]);

    //Increment the index from which the item will be picked up
    con_idx_1 = con_idx_1 + 1;
    count_1--;

    //Unlock the mutex
    pthread_mutex_unlock(&mutex_1);

    //Return the item
    return str;
}

/*
 * This function return the next string in buffer two.
 *
 * Params:
 *   none.
 */
char *get_bf2() {
    //Create new string to hold item from buffer
    char *str = malloc(1001 * sizeof(char));

    //Lock the mutex before checking if the buffer has data
    pthread_mutex_lock(&mutex_2);

    while(count_2 == 0) {
        //Buffer is empty. Wait for the producer to signal that the buffer has data
        pthread_cond_wait(&full_2, &mutex_2);
    }
    
    strcpy(str, buffer_2[con_idx_2]);

    //Increment the index from which the item will be picked up
    con_idx_2 = con_idx_2 + 1;
    count_2--;

    //Unlock the mutex
    pthread_mutex_unlock(&mutex_2);

    //Return the item
    return str;
}

/*
 * This function return the next string in buffer three.
 *
 * Params:
 *   none.
 */
char *get_bf3() {
    //Create new string to hold item from buffer
    char *str = malloc(1001 * sizeof(char));
    
    // Lock the mutex before checking if the buffer has data
    pthread_mutex_lock(&mutex_3);

    while(count_3 == 0) {
        //Buffer is empty. Wait for the producer to signal that the buffer has data
        pthread_cond_wait(&full_3, &mutex_3);
    }
    
    strcpy(str, buffer_3[con_idx_3]);

    //Increment the index from which the item will be picked up
    con_idx_3 = con_idx_3 + 1;
    count_3--;

    //Unlock the mutex
    pthread_mutex_unlock(&mutex_3);

    //Return the item
    return str;
}

/*
 * This function replace all instances of '\n' with ' ' in a string.
 *
 * Params:
 *   str - the string to be modified.
 */
void replace(char *str) {
    int i;

    //replace all instances of a new line character with a space
    for(i = 0; i < strlen(str); i++) {
        if(str[i] == '\n') {
            str[i] = ' ';
        }
    }
}

/*
 * This function replace all instances of ++ with ^ in an input string.
 * Adapted from source https://www.intechgrity.com/c-program-replacing-a-substring-from-a-string/#
 *
 * Params:
 *   orig - the string to be modified.
 *   rep - the substring to replace.
 *   with - the string that will replace rep.
 */
void replace_plus(char *orig, char *rep, char *with) {
    //A buffer variable to do all replace things
    char buffer[1001];

    //To store the pointer returned from strstr
    char *ch;

    //First exit condition
    if(!(ch = strstr(orig, rep))) {
        return;
    }

    //Copy all the content to buffer before the first occurrence of the search string
    strncpy(buffer, orig, ch - orig);

    //Prepare the buffer for appending by adding a null to the end of it
    buffer[ch - orig] = 0;

    //Append using sprintf function
    sprintf(buffer + (ch - orig), "%s%s", with, ch + strlen(rep));

    //Empty orig for copying
    orig[0] = 0;
    strcpy(orig, buffer);

    //Pass recursively to replace other occurrences
    return replace_plus(orig, rep, with);
}

/*
 * This function is he default function for the first thread.
 * It should read data from stdin and add it to the first buffer.
 *
 * Params:
 *   args - arguments for Pthread API.
 */
void *get_input(void *args) {
    //Declare a new input string and variables
    char *inp_str = malloc(1001 * sizeof(char));
    char *emp = "";
    size_t len = 0;
    ssize_t line;
    int count = 0;

    //get the first line of input
    line = getline(&inp_str, &len, stdin);
    
    while(1) {
        //If the input string is equal to STOP\n, stop looping
        if(strcmp(inp_str, "STOP\n") == 0) {
            break;
        }
        count++;
        //Add item to buffer one and get next line
        put_bf1(inp_str);
        line = getline(&inp_str, &len, stdin);
    }

    //Fill the rest of buffer one with empty strings
    for(count; count < 50; count++) {
        put_bf1(emp);
    }

    //Free the string and return NULL
    free(inp_str);
    return NULL;
}

/*
 * This function is he default function for the second thread.
 * It should remove a string from buffer one, replace '\n' characters, then add it to buffer two.
 *
 * Params:
 *   args - arguments for Pthread API.
 */
void *line_seperator(void *args) {
    int i;

    //Loop through buffer one and take an item
    for(i = 0; i < 50; i++) {
        char *item = get_bf1();

        //Replace '\n' with ' ' and add to buffer two
        replace(item);
        put_buf2(item);
        free(item);
    }

    return NULL;
}

/*
 * This function is he default function for the third thread.
 * It should take an item from buffer two, replace instaces of ++ with ^
 * and add the new string to buffer three.
 *
 * Params:
 *   args - arguments for Pthread API.
 */
void *plus_sign(void *args) {
    int i;
    char *rep = "++";
    char *with = "^";

    //Loop through buffer two and grab an item
    for(i = 0; i < 49; i++) {
        char *item = get_bf2();

        //Replace ++ with ^ and add to buffer four
        replace_plus(item, rep, with);
        put_buf3(item);
        free(item);
    }

    return NULL;
}

/*
 * This function is he default function for the fourth thread.
 * It should take an item from buffer three, add characters from the item
 * to an output string, and print the string when its full.
 *
 * Params:
 *   args - arguments for Pthread API.
 */
void *print_str(void *args) {
    int i;

    //Loop through buffer three and grab an item
    for(i = 0; i < 49; i++) {
        char *item = get_bf3();
        int j;

        //Loop over the string and add characters to output_str
        for(j = 0; j <strlen(item); j++) {
            output_str[out_idx] = item[j];
            out_idx++;

            //Once output_str reaches 80 characters, print it
            if(out_idx == 80) {
                printf("%s\n", output_str);
                out_idx = 0;
            }
        }

        free(item);
    }

    //Check if output_str is full
    if(out_idx == 80) {
        printf("%s\n", output_str);
        out_idx = 0;
    }

    return NULL;
}

/*
 * This function should declare four threads and wait for them to finish
 *
 * Params:
 *   none.
 */
int main() {
    //Declare threads
    pthread_t input_t, line_sep_t, plus_sign_t, output_t;

    //Create the threads
    pthread_create(&input_t, NULL, get_input, NULL);
    pthread_create(&line_sep_t, NULL, line_seperator, NULL);
    pthread_create(&plus_sign_t, NULL, plus_sign, NULL);
    pthread_create(&output_t, NULL, print_str, NULL);

    //Wait for the threads to terminate
    pthread_join(input_t, NULL);
    pthread_join(line_sep_t, NULL);
    pthread_join(plus_sign_t, NULL);
    pthread_join(output_t, NULL);

    return EXIT_SUCCESS;
}