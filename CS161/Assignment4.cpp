/**********************************************************************************
 ** Program: cString
 ** Author: Zach Taylor.
 ** Date: 2/21/2020
 ** Description: Takes a cstring input from the user and perform various operations
 ** Input: char str[]
 ** Output: char str[], bool
 **********************************************************************************/
#include <iostream>
#include <cstring>
#include <string>

void vowelsVsConsonants(char *str);
void letterSwap(char *str);
char *flip(char *str);
bool isPalindrome(char *str, char *str2);
void wordFrequency(char *str);
char *purge(char *str);


/*************************************
** Function: Main
** Description: Gets cstring from user
** Parameters: none
** Pre-conditions: cstring is char
** Post-conditions: none
**************************************/
int main() {
    char str[1024];

    std::cout << "Enter a sentece in 1023 charcters or less: " << std::endl;
    std::cin.getline(str, 1023);

    bool again = true;
    int x = 0;

    while(again) {
        char *str2 = purge(str);

        std::cout << "\nWhat would you like top do:\n(1) Vowels vs Consonants.\n(2) Letter Swap.\n(3) Flip.\n(4) Palindrome.\n(5) Word Frequency.\n" << std::endl;
        std::cin >> x;

        //if statement for function choices, memory managment and repeatability
        if(x == 1) {
            vowelsVsConsonants(str2);
            delete []str2;
            std::cout << "Want to run again?\n1(yes)\n0(no)" << std::endl;
            std::cin >> again;
        } else if(x == 2) {
            letterSwap(str);
            delete []str2;
            std::cout << "Want to run again?\n1(yes)\n0(no)" << std::endl;
            std::cin >> again;
        } else if(x == 3) {
            char *str3 = flip(str);
            std::cout << str3 << std::endl;
            delete []str3;
            delete []str2;
            std::cout << "Want to run again?\n1(yes)\n0(no)" << std::endl;
            std::cin >> again;
        } else if(x == 4) {
            char *str3 = flip(str2);
            if(isPalindrome(str2, str3) == true) {
                std::cout << "Is palindrome." << std::endl;
            } else {
                std::cout << "Is not a palindrome." << std::endl;
            }
            delete []str2;
            delete []str3;
            std::cout << "Want to run again?\n1(yes)\n0(no)" << std::endl;
            std::cin >> again;
        } else if(x == 5) {
            wordFrequency(str2);
            delete []str2;
            std::cout << "Want to run again?\n1(yes)\n0(no)" << std::endl;
            std::cin >> again;
        }
    }
    return 0;
}


/*******************************************************************************************
** Function: vowelsVsConsonants
** Description: checks if the number of vowels in the string equals the number of consonants
** Parameters: char *str
** Pre-conditions: str is a cstring
** Post-conditions: outputs if vowels are equal to consonants
********************************************************************************************/
void vowelsVsConsonants(char *str) {
    int x = 0;
    int y = 0;

    for(int i = 0; i < strlen(str); i++) {
        if(str[i] == 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U') {
            x++;
        } else {
            y++;
        }
    }
    if(x == y) {
        std::cout << "# of vowels = # of consonants." << std::endl;
    } else {
        std::cout << "# of vowels != # of consonants." << std::endl;
    }
}


/**********************************************************************************************
** Function: letterSwap
** Description: gets two letter inputs from the user and swaps the first letter with the second
** Parameters: char *str
** Pre-conditions: str is a cstring
** Post-conditions: outputs cstring with swapped letters
***********************************************************************************************/
void letterSwap(char *str) {
    bool isCapital = false;
    char one = ' ';
    char two = ' ';

    std::cout << "Enter the first letter: " << std::endl;
    std::cin >> one;
    std::cout << "Enter the second letter: " << std::endl;
    std::cin >> two;

    for(int i = 0; i < strlen(str) - 1; i++) {
        if(str[i] == one && (str[i] >= 'A' && str[i] <= 'Z')) {
            two += 32;
            str[i] = two;
        } else if(str[i] == one) {
            str[i] = two;
        }
    }
    std::cout << "\n" << str << "\n" << std::endl;
}


/*****************************************************************
** Function: flip
** Description: takse a cstring input and returns a fliped cstring
** Parameters: char *str
** Pre-conditions: str is cstring
** Post-conditions: returns cstring
******************************************************************/
char *flip(char *str) {
    char *temp = new char[strlen(str)];

    for(int i = 0; i < strlen(str); i++) {
        temp[i] = str[strlen(str) - 1 - i];
    }
    return temp;
}


/*******************************************************************
** Function: isPalindrome
** Description: checks if one cstring is equal to its fliped version
** Parameters: char *str
** Pre-conditions: str is a cstring
** Post-conditions: outputs true if cstrings are palindrome
********************************************************************/
bool isPalindrome(char *str, char *str2) {
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
    for(int i = 0; i < strlen(str2); i++) {
        if(str2[i] >= 'A' && str2[i] <= 'Z') {
            str2[i] += 32;
        }
    }
    for(int i = 0; i < strlen(str) - 1; i++) {
        if(str2[i] != str[i]) {
            return false;
        }
    }
    return true;
}


/*****************************************************************
** Function: flip
** Description: takse a cstring input and returns a fliped cstring
** Parameters: char *str
** Pre-conditions: str is cstring
** Post-conditions: returns cstring
******************************************************************/
void wordFrequency(char *str) {
    int length = 0;
    std::cout << "How many words do you want to look for: " << std::endl;
    std::cin >> length;

    std::string *words = new std::string[length];

    std::string word = " ";
    std::cout << "Enter your words: " << std::endl;
    for(int i = 0; i <= length; i++) {
          std::getline(std::cin, words[i]);
    }

    std::cout << words << std::endl;
}


/***************************************************************
** Function: *purge
** Description: Gets a cstring and removes unwanted characters
** Parameters: char *str
** Pre-conditions: str is a cstring
** Post-conditions: returns a cstring wihtout unwanted charcters
****************************************************************/
char *purge(char *str) {
    char *temp = new char[1024];
    strcpy(temp,str);

    for(int i = 0; i < strlen(temp); i++) {
        if(!((temp[i] >= 'a' && temp[i] <= 'z') || (temp[i] >= 'A' && temp[i] <= 'Z'))) {
            memmove(&temp[i], &temp[i + 1], strlen(temp) - i);
            i--;
        }
    }
    return temp;
}
