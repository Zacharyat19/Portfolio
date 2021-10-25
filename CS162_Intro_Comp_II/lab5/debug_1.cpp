/*
 * This program should compute do some simple setting and printing of values.
 *
 * Once compiled, you can run this program like so:
 *   ./debug_1
 */

#include <iostream>

using namespace std;

void setval(int* i_ptr, int val) {
  *i_ptr = val;
}

int main(int argc, char** argv) {
  int a;
  setval(&a, 13);
  cout << "a: " << a << endl;

  int* b = new int;
  setval(b, 4);
  cout << "*b:" << *b << endl;

  return 0;
}