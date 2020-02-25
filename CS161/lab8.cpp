#include <iostream>

int main() {
    char str[51];

    std::cout << "Enter a sentence: " << std::endl;
    std::cin.getline(str, 50);

    int length = 0;
    std::cout << "How many words do you want to look for: " << std::endl;
    std::cin >> length;

    std::string words[length];

    std::string word = " ";
    std::cout << "Enter your words: " << std::endl;
    for(int i = 0; i <= length; i++) {
          std::getline(std::cin, words[i]);
    }

    std::cout << "\n" << "Cstring: " << str << std::endl;
    std::cout << "\n" << "String array: " << std::endl;
    for(int i = 0; i <= length; i++) {
        std::cout << words[i] << " ";
    }
}