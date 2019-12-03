#include <iostream>
#include <cstring>

void c_string() {
    char arr[] = {'Z','a','c','h'};
        for(int i = 0; i < 4; i++) {
        std::cout << arr[i];
    }   
}

int main() {
    c_string();
    return 0;
}