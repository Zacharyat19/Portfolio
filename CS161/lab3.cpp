#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>

int main() {
        int length;
        int letters;
        int upper;
        int numUpper;
        int lowercase;
        int numLower;
        int num;
        int numNum;
        std::string strTemp1;
        std::string strTemp2;
        std::string strTemp3;
        std::string password;

        std::cout << "How long do you want the password: " <<  std::endl;
        std::cin >> length;

        std::cout << "Do you want letters (0-no, 1-yes):"  << std::endl;
        std::cin >> letters;

        if(letters == 1) {
                std::cout << "Do you want uppercase letters (0-no, 1-yes)" << std::endl;
                std::cin >> upper;
        
                std::cout << "How many should be uppercase: " << std::endl;
                std::cin >> numUpper;
        
                std::cout << "How many should be lowercase: " << std::endl;
                std::cin >> numLower;

                std::cout << "Do you want numbers (0-no, 1-yes)" << std::endl;
                std::cin >> num;
        }

        if(num == 1) {
                std::cout << "How many should be numbers: " << std::endl;
                std::cin >> numNum;
        }
        
        srand(time(NULL));
        int r;
        int remaining;
        if(letters == 1) {
                if(upper == 1) {
                        for(int i = 0; i < numUpper; i++) {
                                r = rand() % 26;
                                char c = 'A' + r;
                                strTemp1 += c;
                        }
                }
                
                for(int i = 0; i < numLower; i++) {
                        r = rand() % 26;
                        char c = 'a' + r;
                        strTemp2 += c;
                }
        
                if(num == 1) {
                        for(int i = 0; i < numNum; i++) {
                                r = rand() % 9;
                                std::ostringstream ss;
                                ss << r;
                                strTemp3 += ss.str();
                        }
                } else if(num == 0) {
                        remaining = length -(numUpper+ numLower);
                        for(int i = 0; i < remaining; i++) {
                                r = rand() % 26;
                                char c = 'a' + r;
                                strTemp2 += c;
                        }
                }

                password = strTemp1 + strTemp2 + strTemp3;
                std::cout << "Your password is " << password << std::endl;

        } else if(letters == 0) {
                for(int i = 0; i < length; i++) {
                        r = rand() % 9;
                        std::ostringstream ss;
                        ss << r;
                        password += ss.str();
                }
                std::cout << "Your password is " << password << std::endl;
        }
}
