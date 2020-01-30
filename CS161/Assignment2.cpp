#include <iostream>
#include <cmath>
#include <string>

/**************************************************************************
 * * Function: CheckRange
 * * Description: checks if a test value is between a lower and upper bound
 * * Parameters: lowerBound, upperBound, testValue
 * * Pre-Conditions: all parameters are ints 
 * * Post-Conditions: retruns true if testValue is between upper and lower
 * ************************************************************************/
bool checkRange(int lowerBound, int upperBound,int testValue) {
    if(testValue < upperBound && testValue > lowerBound) {
        return true;
    }
    return false;
}


/**************************************************************************
 * * Function: isCapital
 * * Description: checks if a characters is a capital
 * * Parameters: letter
 * * Pre-Conditions: letter is a char 
 * * Post-Conditions: outputs true if letter is a capital
 * ************************************************************************/
bool isCapital(char letter) {
    if(letter >= 'A' || letter <= 'Z') {
        return true;
    }
    return false;
}


/**************************************************************************
 * * Function: isEvem
 * * Description: checks if a number is even or not
 * * Parameters: num
 * * Pre-Conditions: num is an int
 * * Post-Conditions: outputs true if num is an int
 * ************************************************************************/
bool isEven(int num) {
    if(num % 2 == 0) {
        return true;
    }
    return false;
}


/**************************************************************************
 * * Function: isOdd
 * * Description: checks if a number is odd or not
 * * Parameters: num
 * * Pre-Conditions: num is an int 
 * * Post-Conditions: outputs true if num is odd
 * ************************************************************************/
bool isOdd(int num) {
    if(num % 2 != 0) {
        return true;
    }
    return false;
}


/**************************************************************************
 * * Function: equalityTest
 * * Description: checks if a two numbers are equal
 * * Parameters: num1, num2
 * * Pre-Conditions: num1 and num2 are ints
 * * Post-Conditions: outputs true if they're equal, false otherwise
 * ************************************************************************/
int equalityTest(int num1,int num2) {
    if(num1 < num2) {
        return -1;
    } else if(num1 == num2) {
        return 0;
    } else if(num1 > num2) {
        return 1;
    }
    return 0;
}


/**************************************************************************
 * * Function: isFloatEqual
 * * Description: checks if two floats are equal
 * * Parameters: num1, num2, precision
 * * Pre-Conditions: All parameters are floats
 * * Post-Conditions: returns true if floats are equal, false otherwise
 * ************************************************************************/
bool isFloatEqual(float num1,float num2,float precision) {
    float num3 = num1 - num2;
    num3 = abs(num3);

    if(num3 > precision) {
        return false;
    }
    return false;
}


/**************************************************************************
 * * Function: isInt
 * * Description: checks if a string is an integers
 * * Parameters: num
 * * Pre-Conditions: num is a string
 * * Post-Conditions: returns true if num contains an integer
 * ************************************************************************/
bool isInt(std::string num) {
    for(int i = 0; i < num.length(); i++) {
        if(num[i] >= '0' && num[i] <= '9') {
            return true;
        }
    }
    return false;
}


/**************************************************************************
 * * Function: numbersPresent
 * * Description: checks if a string contains numbers
 * * Parameters: sentence
 * * Pre-Conditions: sentence is a string 
 * * Post-Conditions: returns true if a number is in a string
 * ************************************************************************/
bool numbersPresent(std::string sentence) {
    for(int i = 0; i < sentence.length(); i++) {
        if(sentence[i] >= '0' && sentence[i] <= '9') {
            return true;
        }
    }
    return false;
}


/**************************************************************************
 * * Function: lettersPresent
 * * Description: checks if a string contains letters
 * * Parameters: sentence
 * * Pre-Conditions: sentence is a string 
 * * Post-Conditions: returns true if letters are in a string
 * ************************************************************************/
bool lettersPresent(std::string sentence) {
    for(int i = 0; i < sentence.length(); i++) {
        if((sentence[i] >= 'A' && sentence[i] <= 'Z') || (sentence[i] >= 'a' && sentence[i] <= 'z')) {
            return true;
        }
    } 
    return false;
}


/**************************************************************************
 * * Function: containsSubString
 * * Description: checks if a substring exists in a string
 * * Parameters: sentence, substring
 * * Pre-Conditions: sentence is a string, substring is a string 
 * * Post-Conditions: returns true if substring is in sentence
 * ************************************************************************/
bool containsSubString(std::string sentence, std::string subString) {
    int sentenceLength = sentence.length();
    int subStringLength = subString.length();

    if (sentenceLength < subStringLength) { 
            return false;
    } else {
        for (int i = 0; i < sentenceLength; i++) {
            int j = 0;
            if(sentence[i] == subString[j]) {
                int position = i;
                for(int a = 0; a < subStringLength; a++) {
                    if(sentence[i] == subString[j]) {

                        j++;
                        i++;
                    }
                }
                if (j == subStringLength) {
                    return true;
                } else {
                    i = position;
                }
            }
        }
        return false;
    }
}


/**************************************************************************
 * * Function: wordCount
 * * Description: returns the number of words in a string
 * * Parameters: sentence
 * * Pre-Conditions: sentence is a string
 * * Post-Conditions: outputs an int representing the number of words
 * ************************************************************************/
int wordCount(std::string sentence) {
    int count = 0;
    for(int i = 0; i < sentence.length(); i++) {
        if(sentence[i] == ' ') {
            count++;
        }
    }
    return count + 1;
}


/**************************************************************************
 * * Function: toUpper
 * * Description: returns a string in uppercase
 * * Parameters: sentence
 * * Pre-Conditions: sentence is a string
 * * Post-Conditions: outputs a string in all uppercase
 * ************************************************************************/
std::string toUpper(std::string sentence) {
    for(int i = 0; i < sentence.length(); i++) {
        if(sentence[i] >= 'a' && sentence[i <= 'z']) {
            sentence[i] = sentence[i] - 32;
        }
    }
    return sentence;
}


/**************************************************************************
 * * Function: toLower
 * * Description: returns a sring in all lowercase
 * * Parameters: sentence
 * * Pre-Conditions: sentence is a string
 * * Post-Conditions: outputs a string in all lowercase
 * ************************************************************************/
std::string toLower(std::string sentence){
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] >= 'A' && sentence[i] <= 'Z') {
            sentence[i] = sentence[i] + 32;
        }
    }
    return sentence;    
}


/**************************************************************************
 * * Function: getInt
 * * Description: Checks if input is a valid integer, returns the integer
 * * Parameters: prompt
 * * Pre-Conditions: prompt is a string
 * * Post-Conditions: outputs the provided integer
 * ************************************************************************/
int getInt(std::string prompt) {
    bool negative_prompt = false;
    if (prompt[0] == '-') {
        negative_prompt = true;
        prompt[0] = '0';
    }
    
    for (int i = 0; i < prompt.length(); i++) {
        if (prompt[i] < '0' || prompt[i] > '9') {
            std::cout << "Not a valid Integer.";
            return false;
        }
    }

    int sum = 0;
    for(int i = 0; i < prompt.length(); i++) {
        int int_from_char = (prompt[i]-48);
        float pow_function = int_from_char * pow(10,prompt.length()-1-i);
        sum += pow_function;
    }
   
    if (negative_prompt) {
        return (sum*-1);
    }
    return sum;
}
/**************************************************************************
 * * Function: main
 * * Description: outputs results of all functions
 * * Parameters: none
 * * Pre-Conditions: function inputs are correct type
 * * Post-Conditions: outputs true or false
 * ************************************************************************/
int main() {
    std::cout << checkRange(10,20,15);
    std::cout << isCapital('A');
    std::cout << isEven(4);
    std::cout << isOdd(3);
    std::cout << equalityTest(3,2);
    std::cout << isFloatEqual(2.0,3.5,0.1);
    std::cout << isInt("1");
    std::cout << numbersPresent("happ1ness");
    std::cout << lettersPresent("123hi132");

    return 0;
}