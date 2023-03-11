#include <iostream>

void getString(std::string *);
void setReplaceString(std::string, std::string *);
int getSearchReplace(char, std::string, std::string &); 

int main() {
    std::string str = " ";
    getString(&str);

    std::string str2 = " ";
    setReplaceString(str,&str2);
    std::cout << str2 << std::endl;

    std::cout << "Enter a character to look for: " << std::endl;
    char c = ' ';
    std::cin >> c;
    std::cout << "Number of letters found: " << getSearchReplace(c,str,str2) << std::endl;
    std::cout << str2 << std::endl;

    return 0;
}

void getString(std::string *str) {
    std::cout << "Enter a string: " << std::endl;
    std::getline(std::cin, *str);
}

void setReplaceString(std::string str, std::string *p) {
    for(int i = 0; i < str.length(); i++) {
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            str[i] = '-';
        }
    }
    *p = str;
}

int getSearchReplace(char c, std::string str, std::string &str2) {
    int counter = 0;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == c) {
            counter += 1;
            str2[i] = c;
        }
    }
    return counter;
}