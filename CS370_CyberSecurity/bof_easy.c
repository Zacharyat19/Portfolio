#include <stdio.h>
#include <stdlib.h>

void get_flag() {
    printf("Not bad. cs370_flag{--------------}.\n");
    exit(0);
}

void say_hi() {
    int n00b = 0xdeadbeef;
    char name[100];
    printf("Hi, Whats was your name again?!\n");
    read(0, name, 0x100);
    if(n00b == 0xdeadbeef) {
        printf("Hi n00b!");
    } else {
        printf("Hi %x", n00b);
    }
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    say_hi();
    return 0;
}
