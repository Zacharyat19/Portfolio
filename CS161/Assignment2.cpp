/**************************************************************************************
 ** Program: Function library
 ** Author: Zach Taylor.
 ** Date: 2/1/2020
 ** Description: A collection of common functions hard coded
 ** Input: function calls
 ** Output: bool, int, string
 **************************************************************************************/
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
    if(letter >= 'A' && letter <= 'Z') {
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
    std::cout << "\n--------------------------\tcheckRange()\t--------------------------\n";
    std::cout << "\nRange: 0-5   Test Integer: -1\n";
    std::cout << "Running checkRange(\"0,5,-1\")\n";
    std::cout << "Expected: 0\t";
    std::cout << "Actual: " << checkRange(0,5,-1) << std::endl;
    (checkRange(0,5,-1)==false)? std::cout << "PASSED\n" : std::cout << "FAILED\n";

    std::cout << "\nRange: 10-20   Test Integer: 12\n";
    std::cout << "Running checkRange(\"10,20,12\")\n";
    std::cout << "Expected: 1\t";
    std::cout << "Actual: " << checkRange(10,20,12) << std::endl;
    (checkRange(10,20,12)==true)? std::cout << "PASSED\n" : std::cout << "FAILED\n";

    std::cout << "\n--------------------------\tisCapital()\t--------------------------\n";
    std::cout << "\nTest Character: C\n";
    std::cout << "Running isCapital(\'C\')\n";
    std::cout << "Expected: 1\t";
    std::cout << "Actual: " << isCapital('C') << std::endl;
    (isCapital('C')==true)? std::cout << "PASSED\n" : std::cout << "FAILED\n";


    std::cout << "\nTest Character: t\n";
    std::cout << "Running isCapital(\'t\')\n";
    std::cout << "Expected: 0\t";
    std::cout << "Actual: " << isCapital('t') << std::endl;
    (isCapital('t')==false)? std::cout << "PASSED\n" : std::cout << "FAILED\n";

    std::cout << "\n--------------------------\tisEven()\t--------------------------\n";

    std::cout << "\nTest Integer: 14\n";
    std::cout << "Running isEven(14)\n";
    std::cout << "Expected: 1\t";
    std::cout << "Actual: " << isEven(14) << std::endl;
    (isEven(14)==1)? std::cout << "PASSED\n" : std::cout << "FAILED\n";


    std::cout << "\nTest Integer: -2\n";
    std::cout << "Running isEven(-2)\n";
    std::cout << "Expected: 1\t";
    std::cout << "Actual: " << isEven(-2) << std::endl;
    (isEven(-2)==1)? std::cout << "PASSED\n" : std::cout << "FAILED\n";

    std::cout << "\n--------------------------\tisOdd()\t--------------------------\n";

    std::cout << "\nTest Integer: 9\n";
    std::cout << "Running isOdd(9)\n";
    std::cout << "Expected: 1\t";
    std::cout << "Actual: " << isOdd(9) << std::endl;
    (isOdd(9)==1)? std::cout << "PASSED\n" : std::cout << "FAILED\n";


    std::cout << "\nTest Integer: -49\n";
    std::cout << "Running isOdd(-49)\n";
    std::cout << "Expected: 1\t";
    std::cout << "Actual: " << isOdd(-49) << std::endl;
    (isOdd(-49)==1)? std::cout << "PASSED\n" : std::cout << "FAILED\n";

    std::cout << "\n--------------------------\tequalityTest()\t--------------------------\n";

    std::cout << "\nTest num1: 4   Test num2: 8\n";
    std::cout << "Running equalityTest(4,8)\n";
    std::cout << "Expected: -1\t";
    std::cout << "Actual: " << equalityTest(4,8) << std::endl;
    (equalityTest(4,8)==-1)? std::cout << "PASSED\n" : std::cout << "FAILED\n";


    std::cout << "\nTest num1: -16   Test num2: 16\n";
    std::cout << "Running equalityTest(16,-16)\n";
    std::cout << "Expected: 1\t";
    std::cout << "Actual: " << equalityTest(16,-16) << std::endl;
    (equalityTest(16,-16)==1)? std::cout << "PASSED\n" : std::cout << "FAILED\n";

    std::cout << "\n--------------------------\tisFloatEqual\t--------------------------\n";

    std::cout << "\nTest num1: 4.2350   Test num2: 4.2300   Precision: 0.0001\n";
    std::cout << "Running isFloatEqual(4.2350, 4.2300, 0.001)\n";
    std::cout << "Expected: 0\t";
    std::cout << "Actual: " << isFloatEqual(4.2350, 4.2300, 0.001) << std::endl;
    (isFloatEqual(4.2350, 4.2300, 0.001)==0)? std::cout << "PASSED\n" : std::cout << "FAILED\n";


    std::cout << "\nTest num1: 1.0000   Test num2: 1.0001   Precision: 0.001\n";
    std::cout << "Running isFloatEqual(1.0000, 1.0001, 0.001)\n";
    std::cout << "Expected: 1\t";
    std::cout << "Actual: " << isFloatEqual(1.0000, 1.0001, 0.001) << std::endl;
    (isFloatEqual(1.0000, 1.0001, 0.001)==1)? std::cout << "PASSED\n" : std::cout << "FAILED\n";

    std::cout << "\n--------------------------\tisInt\t--------------------------\n";

    std::cout << "\nTest string: \"hello\"\n";
    std::cout << "Running isInt(\"hello\")\n";
    std::cout << "Expected: 0\t";
    std::cout << "Actual: " << isInt("hello") << std::endl;
    (isInt("hello")==0)? std::cout << "PASSED\n" : std::cout << "FAILED\n";


    std::cout << "\nTest string: \"8\"\n";
    std::cout << "Running isInt(\"8\")\n";
    std::cout << "Expected: 1\t";
    std::cout << "Actual: " << isInt("8") << std::endl;
    (isInt("8")==1)? std::cout << "PASSED\n" : std::cout << "FAILED\n";

    std::cout << "\n--------------------------\tnumbersPresent()\t--------------------------\n";

    std::cout << "\nTest string: \"Hello World\"\n";
    std::cout << "Running numbersPresent(\"Hello World\")\n";
    std::cout << "Expected: 0\t";
    std::cout << "Actual: " << numbersPresent("Hello World") << std::endl;
    (numbersPresent("Hello World")==0)? std::cout << "PASSED\n" : std::cout << "FAILED\n";


    std::cout << "\nTest string: \"Hello World\"\n";
    std::cout << "Running numbersPresent(\"I am 18 years old.\")\n";
    std::cout << "Expected: 1\t";
    std::cout << "Actual: " << numbersPresent("This is the number 12.") << std::endl;
    (numbersPresent("I am 18 years old.")==1)? std::cout << "PASSED\n" : std::cout << "FAILED\n";

    std::cout << "\n--------------------------\tlettersPresent()\t--------------------------\n";

    std::cout << "\nTest string: \"11231]23[\"" << std::endl;
    std::cout << "Running lettersPresent(\"11231]23[\"" << std::endl;
    std::cout << "Expected: 0\t";
    std::cout << "Actual: " << lettersPresent("15675431]23[") << std::endl;
    (lettersPresent("11231]23[")==0)? std::cout << "PASSED\n" : std::cout << "FAILED\n";


    std::cout << "\nTest string: \"1831809273k\"" << std::endl;
    std::cout << "Running lettersPresent(\"1831809273k\")" << std::endl;
    std::cout << "Expected: 1\t";
    std::cout << "Actual: " << lettersPresent("1831809273k") << std::endl;
    (lettersPresent("1831809273k")==1)? std::cout << "PASSED\n" : std::cout << "FAILED\n";

    std::cout << "\n--------------------------\tcontainsSubString()\t--------------------------\n";

    std::cout << "\nTest string: \"This is a test.\"   Test substring:\"this\"" << std::endl;
    std::cout << "Running containsSubString(\"This is a test.\", \"test\")" << std::endl;
    std::cout << "Expected: 1\t";
    std::cout << "Actual: " << containsSubString("This is a test.","test") << std::endl;
    (containsSubString("This is a test.","test")==1)? std::cout << "PASSED\n" : std::cout << "FAILED\n";


    std::cout << "\nTest string: \"Is it done?\"   Test substring:\"year\"" << std::endl;
    std::cout << "Running containsSubString(\"Is it done?\", \"year\")" << std::endl;
    std::cout << "Expected: 0\t";
    std::cout << "Actual: " << containsSubString("Is it still 2019?","year") << std::endl;
    (containsSubString("Is it still year?","year")==0)? std::cout << "PASSED\n" : std::cout << "FAILED\n";

    std::cout << "\n--------------------------\twordCount()\t--------------------------\n";

    std::cout << "\nTest sentence: \"Hello, this is a test.\"" << std::endl;
    std::cout << "Running wordCount(\"Hello, this is a test.\")" << std::endl;
    std::cout << "Expected: 5\t";
    std::cout << "Actual: " << wordCount("Hello, my name is Akhil.") << std::endl;
    (wordCount("Hello, this is a test.")==5)? std::cout << "PASSED\n" : std::cout << "FAILED\n";


    std::cout << "\nTest sentence: \"Insert something important\"" << std::endl;
    std::cout << "Running wordCount(\"Insert something important!\")" << std::endl;
    std::cout << "Expected: 3\t";
    std::cout << "Actual: " << wordCount("Insert something here") << std::endl;
    (wordCount("Hydration is Important!")==3)? std::cout << "PASSED\n" : std::cout << "FAILED\n";

    std::cout << "\n--------------------------\ttoUpper()\t--------------------------\n";

    std::cout << "\nTest sentence: \"I Like Dogs!\"" << std::endl;
    std::cout << "Running toUpper(\"I Like Dogs!\")" << std::endl;
    std::cout << "Expected: I LIKE DOGS!\t";
    std::cout << "Actual: " << toUpper("I Like Dogs!") << std::endl;
    (toUpper("I Like Dogs!") == ("I LIKE DOGS!"))? std::cout << "PASSED\n" : std::cout << "FAILED\n";


    std::cout << "\nTest sentence: \"pizza\"" << std::endl;
    std::cout << "Running toUpper(\"pizza\")" << std::endl;
    std::cout << "Expected: PIZZA\t";
    std::cout << "Actual: " << toUpper("pizza") << std::endl;
    (toUpper("pizza") == ("PIZZA"))? std::cout << "PASSED\n" : std::cout << "FAILED\n";

    std::cout << "\n--------------------------\ttoLower()\t--------------------------\n";

    std::cout << "\nTest sentence: \"GO BEAVS!\"" << std::endl;
    std::cout << "Running toLower(\"GO BEAVS!\")" << std::endl;
    std::cout << "Expected: go beavs!\t";
    std::cout << "Actual: " << toLower("GO BEAVS!") << std::endl;
    (toLower("GO BEAVS!") == ("go beavs!"))? std::cout << "PASSED\n" : std::cout << "FAILED\n";


    std::cout << "\nTest sentence: \"RANDOMWORDS123\"" << std::endl;
    std::cout << "Running toLower(\"RANDOMWORDS123\")" << std::endl;
    std::cout << "Expected: randomwords123\t";
    std::cout << "Actual: " << toLower("RANDOMWORDS123") << std::endl;
    (toLower("RANDOMWORDS123") == ("randomwords123"))? std::cout << "PASSED\n" : std::cout << "FAILED\n";

    std::cout << "\n--------------------------\tgetInt()\t--------------------------\n";

    std::string user_input = "";
    std::cout << "Running get_int(int)" << std::endl;
    std::cout << "Enter a number: ";
    std::getline(std::cin, user_input);
    std::cout << "\nYour number is " << getInt(user_input) << "\n\n";
    
    return 0;
}