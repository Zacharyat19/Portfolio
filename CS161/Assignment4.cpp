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
char *letterSwap(char *str);
char *flip(char *str);
bool isPalindrome(char *str, char *str2);
void wordFrequency(char *str);
char *purge(char *str);
int countInstances(char *str, char *str2);
char i_to_a(int decimal);


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

        std::cout << "\nWhat would you like to do:\n(1) Vowels vs Consonants.\n(2) Letter Swap.\n(3) Flip.\n(4) Palindrome.\n(5) Word Frequency.\n" << std::endl;
        std::cin >> x;

        //if statement for function choices, memory managment and repeatability
        if(x == 1) {
            vowelsVsConsonants(str2);
            delete []str2;
            std::cout << "Want to run again?\n1(yes)\n0(no)" << std::endl;
            std::cin >> again;
        } else if(x == 2) {
            char *temp = letterSwap(str);
            std::cout << "\n" << temp << "\n" << std::endl;
            delete []str2;
            delete []temp;
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
            wordFrequency(str);
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
char *letterSwap(char *str) {
    char *temp = new char[strlen(str)];
    strcpy(temp,str);

    char one = ' ';
    char two = ' ';

    std::cout << "Enter the first letter: " << std::endl;
    std::cin >> one;
    std::cout << "Enter the second letter: " << std::endl;
    std::cin >> two;

    for(int i = 0; i < strlen(temp); i++) {
        if(temp[i] == i_to_a(one - 32)) {
            two = i_to_a(two - 32);
            temp[i] = two;
            two = i_to_a(two + 32);
        } else if(temp[i] == one) {
            temp[i] = two;
        }
    }
    
    return temp;
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
    temp[strlen(str)] = '\0';
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


/********************************************************************
** Function: word frequency
** Description: looks for the frequency of N words in a cstring input
** Parameters: char *str
** Pre-conditions: str is a cstring
** Post-conditions: returns frequency of N words
**********************************************************************/
void wordFrequency(char *Ostr) {
    //remove unwanted characters but keep spaces to identify words vs parts of words
    char *temp = new char[1024];
    strcpy(temp,Ostr);

    for(int i = 0; i < strlen(temp); i++) {
        if(!((temp[i] >= 'a' && temp[i] <= 'z') || (temp[i] >= 'A' && temp[i] <= 'Z') || (temp[i] == ' '))) {
            memmove(&temp[i], &temp[i + 1], strlen(temp) - i);
            i--;
        }
    }

    //make all letters lowercase 
    char *str = new char[strlen(temp) + 1];
    str[0] = ' ';
    for(int i = 1; i < strlen(temp) + 1; i++) {
        if(temp[i - 1] >= 'A' && temp[i - 1] <= 'Z') {
            str[i] = temp[i - 1] + 32;
        } else {
            str[i] = temp[i - 1];
        }
    }
    str[strlen(Ostr) + 1] = '\0';

    int length = 0;
    std::cout << "How many words do you want to look for: " << std::endl;
    std::cin >> length;
    std::cin.ignore();
    std::cin.clear();

    //create 2d array to hold cstrings
    char **words = new char*[length];

    std::cout << "Enter your words: " << std::endl;
    //get cstrings from user and add them to **words
    for(int i = 0; i < length; i++) {
        char *word = new char[30];
        std::cin.getline(word,30);
        words[i] = word;
    }
    for(int i = 0; i < length; i++) {
        std::cout << words[i] << ": " << countInstances(str,words[i]) << std::endl;
    }
    //delete nested memory
    for(int i = 0; i < length; i++) {
        delete []words[i];
    }
    delete []temp;
    delete []str;
}


/******************************************************************************
** Function: countInstances
** Description: Gets two cstrings and returns how many times str2 appears in str
** Parameters: char *str, cchar *str2
** Pre-conditions: str and str2 are cstrings
** Post-conditions: returns instancews of substring
*******************************************************************************/
int countInstances(char *str, char *str2) {
    if(strlen(str) < strlen(str2)) {
        return 0;
    }
    char *temp = strstr(str,str2);
    if(temp == NULL) {
        return 0;
    }
    if(!isalpha(*(temp - 1)) && !isalpha(*(temp + strlen(str2)))) {
        return 1 + countInstances(temp + 1, str2);
    } else {
        return countInstances(temp + 1, str2);
    }
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


/**************************************************************
** Function: i_to_a
** Description: turns a decimal value into a character value
** Parameters: int decimal
** Pre-Conditions: the input is an integer
** Post-Conditions: returned the character which represents the
decimal value
***************************************************************/
char i_to_a(int decimal) {
    return static_cast<char>(decimal);

}