#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

/*
 * This function print out the error message to stdout
 *
 * Params:
 *   msg - the error to print.
 */
void error_msg(const char *msg) {
    //print msg to stdout
    perror(msg);
}

/*
 * This function should receive data from the server and form it into a string
 *
 * Params:
 *   socket - the socket to receive data from.
 *   length - the length of the file.
 */
char *receive_txt(int socket, int length) {
    //create a buffer to put data into and other variables
    char bf[length + 1];
    char *text = calloc(length + 1, sizeof(char));
    int len = 0;

    //loop until all data has been sent
    while(len < length) {
        //clear the buffer and receive data into it
        memset(bf, '\0', sizeof(bf));
        len += recv(socket, bf, sizeof(bf), 0);

        //add the received data into our string
        strcat(text, bf);
        memset(bf, '\0', sizeof(bf));
    }

    //return the full string
    return text;
}

/*
 * This function should send data back to the server
 *
 * Params:
 *   socket, the socket to send data through.
 *   msg - the data to send.
 */
void send_txt(int socket, char *msg) {
    //get msg length and make a buffer of that size
    int length = strlen(msg);
    char bf[length + 1];
    int len = 0;

    //loop until all the data has been sent
    while(len < length) {
        //clear buffer and copy msg into the buffer
        memset(bf, '\0', sizeof(bf));
        strcpy(bf, msg + len);

        //send the data to the client
        len += send(socket, bf, sizeof(bf), 0);
        memset(bf, '\0', sizeof(bf));
    }
}

/*
 * This function should check the input files for errors
 *
 * Params:
 *   text - the file to check for errors
 */
char *check_inp(char *text) {
    //allocate allowed chars and open the file
    char *allowed = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    FILE *file = fopen(text, "r");

    //needed variables
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    int i;

    //grab the text and append a null terminator
    nread = getline(&line, &len, file);
    int n = strcspn(line, "\n");
    line[n] = '\0';

    //loop over the string and look for bad characters
    for(i = 0; i < strlen(line); i++) {
        if(line[i] != ' ' && (line[i] < 'A' || line[i] > 'Z')) {
            error_msg("Files contain invalid characters\n");
            free(line);
            exit(1);
        }
    }

    //return the string
    return line;
}

/*
 * The main function where sockets are declared and forks are made
 *
 * Params:
 *   cmd line args
 */
int main(int argc, char *argv[]) {
    //check number of args
    if(argc < 3) {
        fprintf(stderr, "USAGE: %s plaintext key port\n", argv[0]);
        exit(1);
    }

    //needed variables
    char bf[100000] = {0};
    int port;
    int chars_written;
    int chars_read;
    int socket_fd;
    struct sockaddr_in address_s;

    //setup the client socket 
    memset((char*) &address_s, '\0', sizeof(address_s));
    port = atoi(argv[3]);
    address_s.sin_family = AF_INET;
    address_s.sin_port = htons(port);
    struct hostent *server_info = gethostbyname("localhost");

    //print error if host can't be found
    if(server_info == NULL) {
        fprintf(stderr, "CLIENT: ERROR, no such host\n"); 
        exit(0);
    }

    //copy IP Address to socket
    memcpy((char *) &address_s.sin_addr.s_addr, server_info->h_addr_list[0], server_info->h_length);

    //setup socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd < 0) {
        error_msg("CLIENT: ERROR opening socket");
    }

    //make socket reusable
    int yes = 1;
    setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

    //connect socket to server
    if(connect(socket_fd, (struct sockaddr *) &address_s, sizeof(address_s)) < 0) {
        error_msg("CLIENT: ERROR connecting");
    }

    //ask if it's connected to the right server
    chars_written = send(socket_fd, "dec_client", 11, 0);
    if(chars_written < 0){
        error_msg("ERROR writing to socket");
    }

    //terminate if not
    memset(bf, '\0', sizeof(bf));
    chars_read = recv(socket_fd, bf, sizeof(bf), 0);
    if(chars_read < 0) {
        error_msg("ERROR reading from socket\n");
    }

    if(strcmp(bf, "Incorrect server") == 0) {
        printf("Cannot connect to port %d\n", port);
        close(socket_fd);
        exit(2);
    }

    //check the input files for errors
    char *plain = check_inp(argv[1]);
    char *key = check_inp(argv[2]);

    if(strlen(key) < strlen(plain)) {
        error_msg("ERROR: Key is shorter than plaintext\n");
        free(key);
        free(plain);
        exit(1);
    }

    //make key the same length as the plaintext
    char *new_key = calloc(strlen(plain) + 1, sizeof(char));
    strncpy(new_key, key, strlen(plain));
    free(key);
    key = new_key;

    //send the file length to the server
    memset(bf, '\0', sizeof(bf));
    sprintf(bf, "%d", strlen(plain));
    send_txt(socket_fd, bf);
    memset(bf, '\0', sizeof(bf));

    //send plaintext and key to server
    send_txt(socket_fd, plain);
    send_txt(socket_fd, key);

    //receive encrypted text and print it
    char *text = receive_txt(socket_fd, strlen(plain));
    strcat(text, "\n");
    printf("%s", text);

    //free strings
    free(plain);
    free(key);
    free(text);
    close(socket_fd);

    return 0;
}