#include <iostream>

/********************************************************************
** Function: a_to_i
** Description: turns a character into a decimal value
** Parameters: char character
** Pre-Conditions: the input is a character
** Post-Conditions: returned the decimal value of the character
********************************************************************/ 
int a_to_i(char character) {
    return (int)character;
}

/********************************************************************
** Function: i_to_a
** Description: turns a decimal value into a character value
** Parameters: int decimal
** Pre-Conditions: the input is an integer
** Post-Conditions: returned the character which represents the
decimal value
********************************************************************/
char i_to_a(int decimal) {
    return static_cast<char>(decimal);

}

int main() {
    std::cout << a_to_i('a') << std::endl;
    std::cout << i_to_a(97) << std::endl;
    return 0;
}

/*
#include <iostream>
using namespace std;


int main() {

	int x=3, y;
	char myAnswer;

	y = x;
	cout << "y is set to: " << y << endl;

	cout << "Please input a number: ";
	cin >> y;
	bool again = true;
	while(again == true){
		if(x > y) {
			cout << "X is greater than Y\n";
			cout << "would you like to input another number?" << endl;
			cin >> again;
		} else {
			cout << "X is less than Y" << endl;
			cout << "would you like to input another number?" << endl;
			cin >> again;
		}
		//hint: what about equal logic?
	}
	for(x = 0; x < 10; x+1) {
		cout << x << endl;
    }
	cout << "What number would you like to find the factorial for? " << endl;

    int num;
	cin >> num;

	for(int x = num; x > 0; x--) {
		x = x * x;				//hint: is this factorial correct?
    }

	cout << "Are you enjoying cs161? (y or n) " << endl;
	cin >> myAnswer;
	if(myAnswer = 'y') {
		cout << "YAY" << endl;
    } else {
		cout << "YOU WILL SOON!" << endl;
    }
	return 0;
}
*/