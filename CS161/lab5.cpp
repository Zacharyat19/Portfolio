#include <iostream>
#include <string>

void swapSentence(std::string sent1, std::string sent2) {
    std::string temp = sent1;
    sent1 = sent2;
    sent2 = temp;

    std::cout << "In swap function ..." << std::endl;
    std::cout << "sentence1: " << sent1 << std::endl;
    std::cout << "sentence2 " << sent2  << std::endl;
}

int main() {
    std::string sentence1, sentence2;

    std::cout << "Enter sentence one: ";
    std::getline(std::cin, sentence1);
    std::cout << "Enter sentence two: ";
    std::getline(std::cin, sentence2);

    swapSentence(sentence1,sentence2);

    std::cout << "In main function ..." << std::endl;
    std::cout << "sentence1: " << sentence1 << std::endl;
    std::cout << "sentence2: " << sentence2 << std::endl;

    return 0;
}