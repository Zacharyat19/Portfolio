#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <netdb.h>
#include <fcntl.h>
#include <sys/stat.h>

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
 * This function should encrypt the plaintext string using the provided key
 *
 * Params:
 *   pain_text - the string to encrypt.
 *   key - the key used for encryption.
 */
void encrypt_msg(char *plain_text, char *key) {\
    //needed variables
    int i, n, k;
    int new_letter;
    char *allowed = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

    //loop over and modify the plaintext
    for(i = 0; i < strlen(plain_text); i++) {
        //keep track of numerical version of letters
        if(plain_text[i] == ' ') {
            n = 26;
        } else {
            n = plain_text[i] - 'A';
        }

        //keep track in key
        if(key[i] == ' ') {
            k = 26;
        } else {
            k = key[i] - 'A';
        }

        //add the numbers and modulo, then add the corrsponding letter
        new_letter = (n + k) % 27;
        plain_text[i] = allowed[new_letter];
    }
}

/*
 * This function should receive data from the client and form it into a string
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
 * This function should send data back to the client
 *
 * Params:
 *   socket - the socket to send data through.
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
 * The main function where sockets are declared and forks are made
 *
 * Params:
 *   cmd line args
 */
int main(int argc, char *argv[]) {
    //check if number of args is correct
    if (argc < 2) { 
        fprintf(stderr,"USAGE: %s port\n", argv[0]); 
        exit(1);
    }

    //declare necessary variables
    int connection_sock;
    int listen_sock;
    int chars_read;
    int chars_written;
    int port;
    int status;
    struct sockaddr_in address_s, address_c;
    socklen_t client_info_size = sizeof(address_c);

    //set up the listen socket
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        error_msg("ERROR opening socket");
        exit(1);
    }

    //set up the server socket
    memset((char *) &address_s, '\0', sizeof(address_s));
    port = atoi(argv[1]);
    address_s.sin_family = AF_INET;
    address_s.sin_port = htons(port);
    address_s.sin_addr.s_addr = INADDR_ANY;

    //attempt to bind the server socket to port
    if(bind(listen_sock, (struct sockaddr *) &address_s, sizeof(address_s)) < 0) {
        error_msg("ERROR on binding");
        exit(1);
    }

    //listen for five connections on server
    listen(listen_sock, 5);
    while(1) {
        //accept socket connections
        connection_sock = accept(listen_sock, (struct sockaddr *) &address_c, &client_info_size);
        if(connection_sock < 0) {
            error_msg("ERROR on accept");
        }

        //fork a child proccess to handle sending/receiving
        pid_t spawn_pid = fork();
        switch(spawn_pid) {
            case -1:
                //return error if fork wasn't successful
                error_msg("fork()\n");
                exit(1);
                break;
            case 0:;
                //create a buffer and clear it
                char bf[100000] = {0};
                memset(bf, '\0', sizeof(bf));

                //read incoming request from the client
                chars_read = recv(connection_sock, bf, sizeof(bf), 0);
                if(chars_read < 0) {
                    error_msg("ERROR reading from socket\n");
                }

                //If the client is correct, return they have the right server
                if(strcmp(bf, "enc_client") == 0) {
                    chars_written = send(connection_sock, "This is enc_server", 15, 0);
                    if (chars_written < 0){
                        error_msg("ERROR writing to socket");
                    }
                } else {
                    chars_written = send(connection_sock, "Incorrect server", 18, 0);\
                    if (chars_written < 0){
                        error_msg("ERROR writing to socket");
                    }
                }

                //clear the buffer and get the file lengths from client
                memset(bf, '\0', sizeof(bf));
                chars_read = recv(connection_sock, bf, sizeof(bf), 0);
                int plain_length = atoi(bf);

                //receive plaintext and key from client 
                char *plain = receive_txt(connection_sock, plain_length);
                char *key = receive_txt(connection_sock, plain_length);

                //encrypt the message and send it back
                encrypt_msg(plain, key);
                send_txt(connection_sock, plain);
            
                //free strings
                free(plain);
                free(key);
                exit(0);
                break;
            default:;
                //don't sleep while child proccess is running
                pid_t parent = waitpid(spawn_pid, &status, WNOHANG);
        }
        //close listening and connection sockets
        close(connection_sock);
    }
    close(listen_sock);
    return 0;
}