/*
 * This program should compute the factorial of a user-specified value of n.
 *
 * Once compiled, you can run this program like so (here, we're using n = 7):
 *   ./debug_2 7
 */

#include <iostream>
#include <cstdlib>

using namespace std;

/*
 * This function computes and returns the factorial of a given number n.
 */
int factorial(int n) {
  int fact = 0;
  while (n > 0) {
    fact += n;
    n--;
  }
  return fact;
}


int main(int argc, char** argv) {
  if (argc < 2) {
    cout << "Error: must specify a value for n." << endl;
    cout << "usage: " << argv[0] << " <n>" << endl;
    return 1;
  }

  int n = strtol(argv[1], NULL, 0);
  if (n <= 0) {
    cout << "Error: n must be a positive integer value." << endl;   
    cout << "usage: " << argv[0] << " <n>" << endl;
    return 1;
  }

  int n_factorial = factorial(n);
  cout << n << "! = " << n_factorial << endl;

  return 0;
}